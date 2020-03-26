#include <iostream>

using namespace std;

string str1, str2;
int len1, len2, dp[1001][1001] = {0};

int main() {
  cin>>str1>>str2;
  len1 = str1.length();
  len2 = str2.length();
  
  if(str1[0] == str2[0]) dp[0][0] = 1;
  for(int i=1; i<len1; i++) {
    dp[i][0] = max(dp[i-1][0], str1[i] == str2[0] ? 1: 0);
  }
  for(int i=1; i<len2; i++) {
    dp[0][i] = max(dp[0][i-1], str2[i] == str1[0] ? 1: 0);
  }
  
  for(int i=1; i<len1; i++) {
    for(int j=1; j<len2; j++) {
      if(str1[i] == str2[j]) dp[i][j] = dp[i-1][j-1] + 1;
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  cout<<dp[len1-1][len2-1]<<"\n";
  return 0;
}
