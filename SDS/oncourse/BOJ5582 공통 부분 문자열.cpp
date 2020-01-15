#include <iostream>

using namespace std;

string str1,str2;
int ms, dp[4001][4001];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin>>str1>>str2;
  str1 = '0' + str1, str2 = '0' + str2;
  for(int i=1; i<str1.length(); i++) {
    for(int j=1; j<str2.length(); j++) {
      if(str1[i] == str2[j]) {
        dp[i][j] = 1;
        if(dp[i-1][j-1]) dp[i][j] += dp[i-1][j-1];
        ms = max(ms, dp[i][j]);
      }
    }
  }
  cout<<ms<<"\n";
  return 0;
}
