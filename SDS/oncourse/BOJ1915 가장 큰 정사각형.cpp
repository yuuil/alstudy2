#include <cstdio>
#include <algorithm>

using namespace std;

int n,m,temp,s,dp[1001][1001];

int main() {
  scanf("%d %d", &n, &m);
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m;j++) {
      scanf("%1d",&temp);
      if(temp) {
        dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
        s = max(s, dp[i][j]);
      }
    }
  }
  printf("%d\n", s*s);
  return 0;
}
