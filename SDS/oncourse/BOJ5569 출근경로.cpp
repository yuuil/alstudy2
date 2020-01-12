#include <iostream>

using namespace std;

int w, h, ans, dp[101][101][2][2];

int main() {
  cin>>w>>h;
  for(int i=2; i<101; i++) {
    dp[i][1][0][0] = dp[1][i][1][0] = 1;
  }
  for(int i=2; i<=w; i++) {
    for(int j=2; j<=h; j++) {
      dp[i][j][0][0] = (dp[i-1][j][0][0] + dp[i-1][j][0][1]) % 100000;
      dp[i][j][0][1] = dp[i-1][j][1][0];
      dp[i][j][1][0] = (dp[i][j-1][1][0] + dp[i][j-1][1][1]) % 100000;
      dp[i][j][1][1] = dp[i][j-1][0][0];
    }
  }
  for(int i=0; i<2; i++) {
    for(int j=0; j<2; j++) {
      ans += dp[w][h][i][j];
    }
  }
  cout<<ans%100000<<"\n";
  return 0;
}
