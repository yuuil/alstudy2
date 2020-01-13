#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1e6+1;
int V,E, a,b, cnt, number, disc[MAX];
vector<int> vc[MAX];
vector<pair<int,int> > isCut;

int dfs(int node, int p) {
  disc[node] = ++number;
  int ret = disc[node];
  for(int i=0; i<vc[node].size(); i++) {
    int next = vc[node][i];
    if(next == p) continue;
    if(disc[next]) {
      ret = min(ret, disc[next]);
      continue;
    }
    int prev = dfs(next, node);
    if(prev > disc[node]) {
      isCut.push_back(make_pair(min(node, next), max(node, next)));
    }
    ret = min(ret, prev);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>V>>E;
  for(int i=0; i<E; i++) {
    cin>>a>>b;
    vc[a].push_back(b);
    vc[b].push_back(a);
  }
  for(int i=1; i<=V; i++) {
    if(!disc[i]) dfs(i,0);
  }
  sort(isCut.begin(), isCut.end());
  cout<<isCut.size()<<"\n";
  for(int i=0; i<isCut.size(); i++) {
    cout<<isCut[i].first<<" "<<isCut[i].second<<"\n";
  }
  return 0;
}
