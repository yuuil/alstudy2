#include <iostream>
#define INF 987654321
using namespace std;

int N, cost[17][17], dp[17][1<<17];

int tsp(int node, int mask) {
  if(mask == (1<<N)-1) {
    if(cost[node][1] != 0) return cost[node][1];
  }
  int &ret = dp[node][mask];
  if(ret != 0) return ret;
  ret = INF;
  for(int i=1; i<=N; i++) {
    if(!(mask & (1<<(i-1))) && cost[node][i]) ret = min(ret, cost[node][i] + tsp(i, mask | (1<<(i-1))));
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin>>N;
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      cin>>cost[i][j];
    }
  }
  cout<<tsp(1,1)<<"\n";
  return 0;
}
