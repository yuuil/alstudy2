#include <iostream>
#include <string>

using namespace std;
const int MAX = 1e6+1;
string inp, bomb;
int len, idx;
bool flag;
char ans[MAX];
int main() {
  cin>>inp>>bomb;
  len = bomb.length();
  for(int i=0; i<inp.length(); i++) {
    ans[idx++] = inp[i];
    if(ans[idx-1] == bomb[len-1]) {
      if(idx < len) continue;
      flag = 1;
      for(int j=0; j<len; j++) {
        if(ans[idx-j-1] != bomb[len-j-1])  {
          flag^=1;
          break;
        }
      }
      if(flag) idx -= len;
    }
  }
  if(idx) {
    for(int i=0; i<idx; i++) cout<<ans[i];
  } else cout<<"FRULA";
  return 0;
}