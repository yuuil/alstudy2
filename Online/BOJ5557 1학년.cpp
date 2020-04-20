#include <iostream>
using namespace std;
int N, num[101];
long long dp[101][21];

int main() {
  cin>>N;
  for(int i=0; i<N; i++) cin>>num[i];
  dp[0][num[0]] = 1;
  for(int i=1; i<N-1; i++) {
    for(int j=0; j<=20; j++) {
      if(j+num[i]<=20) dp[i][j] += dp[i-1][j+num[i]];
      if(j-num[i]>=0) dp[i][j] += dp[i-1][j-num[i]];
    }
  }
  cout<<dp[N-2][num[N-1]];
  return 0;
}