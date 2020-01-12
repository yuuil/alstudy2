#include <iostream>

using namespace std;

int w, h, n, x, y, dp[1002][1002];
bool map[1002][1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>h>>w>>n;
  for(int i=1; i<=h; i++) {
    for(int j=1; j<=w; j++) {
      cin>>map[i][j];
    }
  }
  dp[1][1] = n;
  for(int i=1; i<=h; i++) {
    for(int j=1; j<=w; j++) {
      if(map[i][j]) {
        dp[i+1][j] += dp[i][j]/2;
        dp[i][j+1] += dp[i][j]/2 + dp[i][j]%2;
      } else {
        dp[i+1][j] += dp[i][j]/2 + dp[i][j]%2;
        dp[i][j+1] += dp[i][j]/2;
      }
    }
  }
  for(int i=1; i<=h; i++) {
    for(int j=1; j<=w; j++) {
      dp[i][j] %= 2;
    }
  }
  x = y = 1;
  while(x <= h && y <= w) {
    if(map[x][y]) {
      if(dp[x][y]) y++;
      else x++;
    } else {
      if(dp[x][y]) x++;
      else y++;
    }
  }
  cout<<x<<" "<<y<<"\n";
  return 0;
}
