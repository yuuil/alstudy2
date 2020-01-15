#include <iostream>
#include <stack>

using namespace std;

string str1, str2;
int dp[1002][1002];
stack<int> s;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin>>str1>>str2;
  str1 = '0' + str1, str2 = '0' + str2;
  for(int i=1; i<str1.length(); i++) {
    for(int j=1; j<str2.length(); j++) {
      if(str1[i] == str2[j]) dp[i][j] = dp[i-1][j-1]+1;
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  int i=str1.length()-1, j=str2.length()-1;
  while(dp[i][j]) {
    if(dp[i][j] == dp[i][j-1]) j--;
    else if(dp[i][j] == dp[i-1][j]) i--;
    else if(dp[i][j] -1 == dp[i-1][j-1]) {
      s.push(i);
      i--;
      j--;
    }
  }
  cout<<s.size()<<"\n";
  while(!s.empty()) {
    cout<<str1[s.top()];
    s.pop();
  }
  cout<<"\n";
  return 0;
}
