#include <iostream>

using namespace std;

const int MAX = 1e6+1;
int n,m,cmd,a,b,parent[MAX];

int findP(int x) {
  if(x==parent[x]) return x;
  return parent[x] = findP(parent[x]);
}

void merge(int x, int y) {
  x = findP(x);
  y = findP(y);
  if(x!=y) parent[x] = y;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i=0; i<=n; i++) {
    parent[i] = i;
  }
  for(int i=0; i<m; i++) {
    cin>>cmd>>a>>b;
    if(cmd == 0) merge(a,b);
    else {
      cout<<(findP(a) == findP(b) ? "YES" : "NO")<<"\n";
    }
  }
  return 0;
}
