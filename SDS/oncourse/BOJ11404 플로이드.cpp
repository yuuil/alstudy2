#include <iostream>
#define INF 987654321

using namespace std;

int n,m,from,to,w,cost[101][101];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      cost[i][j] = INF;
    }
  }
  for(int i=0; i<m; i++) {
    cin>>from>>to>>w;
    cost[from][to] = min(cost[from][to], w);
  }
  for(int v=1; v<=n; v++) {
    for(int f=1; f<=n; f++) {
      for(int t=1; t<=n; t++) {
        if(f == t) continue;
        if(cost[f][t] > cost[f][v] + cost[v][t]) cost[f][t] = cost[f][v] + cost[v][t];
      }
    }
  }
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      if(cost[i][j] == INF) cout<<"0 ";
      else cout<<cost[i][j]<<" ";
    }
    cout<<"\n";
  }
  return 0;
}
