#include <iostream>
#include <stack>
using namespace std;
bool err;
int ans,temp = 1;
string input;
stack<char> s;
int main() {
  cin>>input;
  for(int i=0; i<input.size(); i++) {
    if(input[i]=='('||input[i]=='[') {
      s.push(input[i]);
      temp *= (input[i]=='(' ? 2 : 3);
    }
    else if((input[i]==')'&&(s.empty()||s.top()!='('))||(input[i]==']'&&(s.empty()||s.top()!='['))) {
      err=1;
      break;
    } else if(input[i]==')') {
      if(input[i-1]=='(') ans+=temp;
      s.pop();
      temp/=2;
    } else if(input[i]==']') {
      if(input[i-1]=='[') ans+=temp;
      s.pop();
      temp/=3;
    }
  }
  cout<<(err||!s.empty()?0:ans);
  return 0;
}