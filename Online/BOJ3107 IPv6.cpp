#include <iostream>
#include <string>
#include <sstream>
#include <queue>

using namespace std;
string inp;
queue<string> ans;

string format(string &str) {
  if(str.length() == 4) return str;
  str = "0" + str;
  return format(str);
}

int main() {
  cin>>inp;
  istringstream ss(inp);
  string p;
  int fill = 0;
  while(getline(ss, p, ':')) {
    if(p.length()) {
      ans.push(format(p));
      fill++;
    } else ans.push(p);
  }
  fill = 8-fill;
  while(!ans.empty()) {
    string front = ans.front();
    ans.pop();
    if(front.length()) cout<<front;
    else {
      while(fill-- >0) {
        cout<<"0000";
        if(fill>0 || !ans.empty()) cout<<":";
      }
      continue;
    }
    if(!ans.empty()) cout<<":";
  }
  return 0;
}
