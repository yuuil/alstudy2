#include <iostream>
#include <climits>
#define INF 987654321

using namespace std;

int N, M, a, b, cnt, conn[501][501], deg[501];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>N>>M;
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      conn[i][j] = INF;
    }
  }
  for(int i=0; i<M; i++) {
    cin>>a>>b;
    conn[a][b] = 1;
  }
  for(int v=1; v<=N; v++) {
    for(int f=1; f<=N; f++) {
      for(int t=1; t<=N; t++) {
        if(conn[f][t] > conn[f][v] + conn[v][t]) conn[f][t] = conn[f][v] + conn[v][t];
      }
    }
  }
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      if(conn[i][j] != INF) {
        deg[i]++, deg[j]++;
        if(deg[i] == N-1) cnt++;
        if(deg[j] == N-1) cnt++;
      }
    }
  }
  cout<<cnt<<"\n";
  return 0;
}
