#include <iostream>
#define INF 987654321
using namespace std;

int N, mat[501], dp[501][501];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin>>N;
  for(int i=0; i<N; i++) {
    cin>>mat[i]>>mat[i+1];
  }
  for(int l=2; l<=N; l++) {
    for(int i=1; i<=N-l+1; i++) {
      int j = i + l -1;
      dp[i][j] = INF;
      for(int k=i; k<j; k++) {
        dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+mat[i-1]*mat[k]*mat[j]);
      }
    }
  }
  cout<<dp[1][N]<<"\n";
  return 0;
}
