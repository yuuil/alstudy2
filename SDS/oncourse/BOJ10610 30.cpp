#include <iostream>
#include <algorithm>

using namespace std;

bool comp(char c1, char c2) {
  return c1 > c2;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string num;
  cin>>num;
  int cnt = 0;
  bool flag = false;
  for(int i=0; i<num.length(); i++) {
    cnt += num[i]-'0';
    if(num[i] == '0') flag = true;
  }
  if(cnt%3==0 && flag) {
    sort(num.begin(), num.end(), comp);
    cout<<num<<"\n";
  } else {
    cout<<-1<<"\n";
  }
  return 0;
}
