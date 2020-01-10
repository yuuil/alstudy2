#include <iostream>

using namespace std;

int N,K,dp[1001][1001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i=0; i<1001; i++) {
    dp[i][0] = dp[i][i] = 1;
  }
  for(int i=1; i<1001; i++) {
    for(int j=1; j<=i; j++) {
      dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
    }
  }
  cin>>N>>K;
  cout<<dp[N][K]<<"\n";
  return 0;
}
