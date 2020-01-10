#include <iostream>

using namespace std;

int N,K,dp[11];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  dp[0] = dp[1] = 1;
  for(int i=2; i<11; i++) {
    dp[i] = dp[i-1]*i;
  }
  cin>>N>>K;
  cout<<(dp[N]/(dp[K]*dp[N-K]))<<"\n";
  return 0;
}
