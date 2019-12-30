#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int number;
vector<int> vc[10002];
int discovered[10002];
bool isCut[10002];

int dfs(int v, bool isRoot) {
  discovered[v] = ++number;
  int ret = discovered[v];
  int child = 0;
  for(int i=0; i<vc[v].size(); i++) {
    int next = vc[v][i];
    if(discovered[next]) {
      ret = min(ret, discovered[next]);
      continue;
    }
    child++;
    int prev = dfs(next, false);
    
    if(!isRoot && prev >= discovered[v]) {
      isCut[v] = true;
    }
    ret = min(ret, prev);
  }
  if(isRoot) {
    isCut[v] = (child >= 2);
  }
  
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int V, E, cnt = 0;
  cin>>V>>E;
  
  for(int i=0; i<E; i++) {
    int from, to;
    cin>>from>>to;
    vc[from].push_back(to);
    vc[to].push_back(from);
  }
  
  for(int i=1; i<=V; i++) {
    if(!discovered[i]) {
      dfs(i, true);
    }
  }
  
  for(int i=1; i<=V; i++) {
    if(isCut[i]) {
      cnt++;
    }
  }
  cout<<cnt<<"\n";
  
  for(int i=1; i<=V; i++) {
    if(isCut[i]) {
      cout<<i<<" ";
    }
  }
  cout<<"\n";
  return 0;
}
