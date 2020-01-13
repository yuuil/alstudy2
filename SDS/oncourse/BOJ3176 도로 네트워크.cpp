#include <iostream>
#include <vector>
#define INF 21e8
using namespace std;

const int MAX = 1e5+1;
bool visited[MAX];
int N,K,a,b,c, d[MAX], parent[MAX][21], mind[MAX][21], maxd[MAX][21];
vector<pair<int,int> > vc[MAX];

void dfs(int node, int depth) {
  visited[node] = 1;
  d[node] = depth;
  for(int i=0; i<vc[node].size(); i++) {
    pair<int, int> next = vc[node][i];
    if(!visited[next.first]) {
      dfs(next.first, depth+1);
      parent[next.first][0] = node;
      mind[next.first][0] = maxd[next.first][0] = next.second;
    }
  }
}

void find() {
  for(int j=1; j<21; j++) {
    for(int i=1; i<=N; i++) {
      parent[i][j] = parent[parent[i][j-1]][j-1];
      mind[i][j] = min(mind[i][j-1], mind[parent[i][j-1]][j-1]);
      maxd[i][j] = max(maxd[i][j-1], maxd[parent[i][j-1]][j-1]);
    }
  }
}

pair<int,int> lca(int x, int y) {
  int rmin = INF, rmax = -INF;
  if(d[x] > d[y]) swap(x,y);
  for(int i=20; i>=0; i--) {
    if(d[y] - d[x] >= (1<<i)) {
      rmin = min(rmin, mind[y][i]);
      rmax = max(rmax, maxd[y][i]);
      y = parent[y][i];
    }
  }
  if(x == y) return make_pair(rmin, rmax);
  for(int i=20; i>=0; i--) {
    if(parent[x][i] != parent[y][i]) {
      rmin = min(rmin, min(mind[x][i], mind[y][i]));
      rmax = max(rmax, max(maxd[x][i], maxd[y][i]));
      x = parent[x][i];
      y = parent[y][i];
    }
  }
  rmin = min(rmin, min(mind[x][0], mind[y][0]));
  rmax = max(rmax, max(maxd[x][0], maxd[y][0]));
  return make_pair(rmin, rmax);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>N;
  for(int i=1; i<N; i++) {
    cin>>a>>b>>c;
    vc[a].push_back(make_pair(b,c));
    vc[b].push_back(make_pair(a,c));
  }
  dfs(1, 0);
  find();
  cin>>K;
  while(K--) {
    cin>>a>>b;
    pair<int,int> r = lca(a,b);
    cout<<r.first<<" "<<r.second<<"\n";
  }
  return 0;
}
