#include <iostream>

using namespace std;

long long square[1025][1025];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin>>N>>M;
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      cin>>square[i][j];
      square[i][j] += square[i][j-1];
    }
  }
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      square[i][j] += square[i-1][j];
    }
  }
  for(int i=0; i<M; i++) {
    int x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;
    cout<<square[x2][y2]-square[x1-1][y2]-square[x2][y1-1]+square[x1-1][y1-1]<<"\n";
  }
}
