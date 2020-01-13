#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num,v,e,a,b,cnt,dis[10001];
vector<int> vc[10001];
bool isCut[10001];

int dfs(int n, bool isRoot) {
  dis[n] = ++num;
  int ret = dis[n], child = 0;
  for(int i=0; i<vc[n].size(); i++) {
    int next = vc[n][i];
    if(dis[next]) ret = min(ret, dis[next]);
    else {
      child++;
      int prev = dfs(next, 0);
      if(!isRoot && prev >= dis[n]) isCut[n] = 1;
      ret = min(ret, prev);
    }
  }
  if(isRoot) isCut[n] = child>=2;
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>v>>e;
  for(int i=0; i<e; i++) {
    cin>>a>>b;
    vc[a].push_back(b);
    vc[b].push_back(a);
  }
  for(int i=1; i<=v; i++) {
    if(!dis[i]) dfs(i, 1);
  }
  for(int i=1; i<=v; i++) {
    if(isCut[i]) cnt++;
  }
  cout<<cnt<<"\n";
  for(int i=1; i<=v; i++) {
    if(isCut[i]) cout<<i<<" ";
  }
  cout<<"\n";
  return 0;
}
