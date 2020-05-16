#include <iostream>
#include <stack>
using namespace std;
int r,c,dp[42][42];
string a,b;
stack<char> ans;
int main() {
  cin>>a>>b;
  r = a.length(), c = b.length();
  for(int i=1; i<=a.length(); i++) {
    for(int j=1; j<=b.length(); j++) {
      if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
      else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    }
  }
  while(dp[r][c]) {
    if(dp[r][c] == dp[r][c-1]) c--;
    else if(dp[r][c] == dp[r-1][c]) r--;
    else if(dp[r][c] - 1 == dp[r-1][c-1]) {
      ans.push(a[r-1]);
      r--, c--;
    }
  }
  while(!ans.empty()) {
    cout<<ans.top();
    ans.pop();
  }
  return 0;
}