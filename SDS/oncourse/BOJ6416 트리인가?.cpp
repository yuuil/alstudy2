#include <iostream>
#include <set>

using namespace std;

bool flag;
int parent[21];
set<int> node;

void init() {
  flag = true;
  for(int i=1; i<21; i++) {
    parent[i] = i;
  }
}

int findP(int x) {
  if(x==parent[x]) {
    return x;
  }
  return parent[x] = findP(parent[x]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int u,v, cnt=0, k=1, curr, temp;
  init();
  while(cin>>u>>v) {
    if(u==v && u==0) {
      temp=0;
      for(set<int>::iterator it=node.begin(); it!= node.end(); it++) {
        curr = findP(*it);
        if(temp != curr) {
          temp = curr;
          cnt++;
        }
      }
      if(cnt > 1) flag = false;
      cout<<"Case "<<k++<<" is "<<(flag ? "": "not ")<<"a tree.\n";
      init();
      cnt=0;
      node.clear();
    } else if(u==v && u==-1) {
      break;
    } else {
      node.insert(u);
      node.insert(v);
      if(findP(u) == findP(v)) flag = false;
      if(parent[v] != v) flag = false;
      parent[v] = findP(u);
    }
  }
  return 0;
}
