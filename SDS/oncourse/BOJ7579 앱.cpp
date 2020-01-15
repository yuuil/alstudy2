#include <iostream>
#include <cstring>

using namespace std;

int N, M, ans, m[101], c[101], dp[101][10001];

int solve(int idx, int cost) {
  if(idx >= 100) return 0;
  int &ret = dp[idx][cost];
  if(ret != -1) return ret;
  ret = solve(idx+1, cost);
  if(c[idx] <= cost) ret = max(ret, m[idx]+solve(idx+1, cost-c[idx]));
  return ret;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin>>N>>M;
  memset(dp, -1, sizeof(dp));
  for(int i=0; i<N; i++) cin>>m[i];
  for(int i=0; i<N; i++) cin>>c[i];
  while(solve(0, ans) < M) {
    ans++;
  }
  cout<<ans<<"\n";
  return 0;
}
