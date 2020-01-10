#include <iostream>
#include <vector>

using namespace std;

bool flag;
int sudoku[10][10];
vector<pair<int,int> > blank;

bool checking(int r, int c, int n) {
  for(int i=0; i<9; i++) {
    if(sudoku[r][i] == n || sudoku[i][c] == n) return 0;
  }
  int sr = r/3*3, sc = c/3*3;
  for(int i=sr; i<sr+3; i++) {
    for(int j=sc; j<sc+3; j++) {
      if(sudoku[i][j] == n) return 0;
    }
  }
  return 1;
}

void game(int depth) {
  int tempSdk[10][10];
  int x = blank[depth].first, y = blank[depth].second;
  for(int i=0; i<9; i++) {
    for(int j=0; j<9; j++) {
      tempSdk[i][j] = sudoku[i][j];
    }
  }
  if(depth == blank.size()) {
    for(int i=0; i<9; i++) {
      for(int j=0; j<9; j++) {
        cout<<tempSdk[i][j]<<" ";
      }
      cout<<"\n";
    }
    flag = 1;
    return;
  }
  for(int i=1; i<=9; i++) {
    if(checking(x, y, i)) {
      sudoku[x][y] = i;
      game(depth+1);
      sudoku[x][y] = 0;
    }
    if(flag) return;
  }
}

int main() {
  for(int i=0; i<9; i++) {
    for(int j=0; j<9; j++) {
      cin>>sudoku[i][j];
      if(sudoku[i][j] == 0) {
        blank.push_back(make_pair(i, j));
      }
    }
  }
  game(0);
  return 0;
}
