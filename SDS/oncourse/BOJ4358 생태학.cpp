#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> tree;
vector<string> name;

int main() {
  int cnt;
  string s;
  while(getline(cin, s)) {
    if(!tree[s]) {
      name.push_back(s);
    }
    tree[s]++;
    cnt++;
  }
  sort(name.begin(), name.end());
  for(int i=0; i<name.size(); i++) {
    double per = (double)tree[name[i]]*100/cnt;
    cout<<fixed;
    cout.precision(4);
    cout<<name[i]<<" "<<per<<"\n";
  }
  return 0;
}
