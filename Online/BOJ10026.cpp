#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

bool visited[101][101];
int N, cnt, dir[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};
char grid[101][101];

void normal(int x, int y) {
  cnt++;
  queue<pair<int,int> > q;
  q.push({x,y});
  while(!q.empty()) {
    x = q.front().first, y = q.front().second;
    q.pop();
    for(int i=0; i<4; i++) {
      int nx = x + dir[i][0], ny = y + dir[i][1];
      if(nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny] || grid[x][y] != grid[nx][ny]) continue;
      visited[nx][ny] = 1;
      q.push({nx,ny});
    }
  }
}

void weak(int x, int y) {
  cnt++;
  queue<pair<int,int> > q;
  q.push({x,y});
  while(!q.empty()) {
    x = q.front().first, y = q.front().second;
    q.pop();
    for(int i=0; i<4; i++) {
      int nx = x + dir[i][0], ny = y + dir[i][1];
      if(nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny]) continue;
      if(grid[x][y] != grid[nx][ny] && abs(grid[x][y]-grid[nx][ny]) != 11) continue;
      visited[nx][ny] = 1;
      q.push({nx,ny});
    }
  }
}

int main() {
  cin>>N;
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cin>>grid[i][j];
    }
  }
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      if(visited[i][j]) continue;
      visited[i][j] = 1;
      normal(i,j);
    }
  }
  cout<<cnt<<" ";
  memset(visited, 0, sizeof(visited));
  cnt = 0;
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      if(visited[i][j]) continue;
      visited[i][j] = 1;
      weak(i,j);
    }
  }
  cout<<cnt<<"\n";
  return 0;
}
