#include <iostream>
#include <cstring>

using namespace std;
int T, N, l, r, card[1001], dp[1001][1001][2];

int solve(int i, int j, bool flag) {
  int &ret = dp[i][j][flag];
  if(ret != -1) return ret;
  if(i >= j) {
    if(flag) return ret = 0;
    else return ret = card[i];
  }
  if(flag) return ret = min(solve(i+1, j, !flag), solve(i, j-1, !flag));
  else return ret = max(solve(i+1, j, !flag)+card[i], solve(i,j-1, !flag) + card[j]);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin>>T;
  for(int t=0; t<T; t++) {
    cin>>N;
    for(int i=0; i<N; i++) cin>>card[i];
    memset(dp, -1, sizeof(dp));
    cout<<solve(0, N-1, 0)<<"\n";
  }
  return 0;
}
