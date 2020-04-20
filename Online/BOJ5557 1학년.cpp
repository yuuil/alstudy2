/*
  dp[i][j] => i번째 수까지 사용해 j를 만드는 경우의 수
  i번째 수까지 사용해 j를 만드는 경우는
  1) i-1번째 수까지 사용해 j+num[i]을 만드는 경우에서 num[i]를 빼는 경우
  2) i-1번째 수까지 사용해 j-num[i]을 만드는 경우에서 num[i]를 더하는 경우
*/
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