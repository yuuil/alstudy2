#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

bool visited[11];
int n,k, comb[11];
string num[11];
set<int> integer;

bool cmp(string str1, string str2) {
  if(str1.length() == str2.length()) {
    for(int i=0; i<str1.length(); i++) {
      if(str1[i] != str2[i]) return str1[i] < str2[i];
    }
  }
  return str1.length() < str2.length();
}

void make_num(int depth) {
  bool chk[11];
  int temp[11];
  for(int i=0; i<11; i++) {
    chk[i] = visited[i];
  }
  for(int i=0; i<n; i++) {
    temp[i] = comb[i];
  }
  if(depth == k) {
    string str = "";
    for(int i=0; i<k; i++) {
      str += to_string(comb[i]);
    }
    integer.insert(stoi(str));
    return;
  }
  for(int i=0; i<n; i++) {
    if(!visited[i]) {
      comb[depth] = stoi(num[i]);
      visited[i] = 1;
      make_num(depth+1);
      for(int j=0; j<11; j++) {
        visited[j] = chk[j];
      }
      for(int j=0; j<k; j++) {
        comb[j] = temp[j];
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  for(int i=0; i<n; i++) {
    cin>>num[i];
  }
  sort(num, num+n, cmp);
  make_num(0);
  cout<<integer.size()<<"\n";
  return 0;
}
