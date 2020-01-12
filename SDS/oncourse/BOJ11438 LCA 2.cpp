#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1e6+1;
int N, M, a, b, maxLevel, depth[MAX], ac[MAX][20];
vector<int> tree[MAX];

void getTree(int node, int parent) {
  depth[node] = depth[parent] + 1;
  ac[node][0] = parent;
  maxLevel = floor(log2(MAX));
  for(int i=1; i<=maxLevel; i++) {
    int tmp = ac[node][i-1];
    ac[node][i] = ac[tmp][i-1];
  }
  int len = tree[node].size();
  for(int i=0; i<len; i++) {
    int conn = tree[node][i];
    if(conn != parent) {
      getTree(conn, node);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>N;
  for(int i=1; i<N; i++) {
    cin>>a>>b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  depth[0] = -1;
  getTree(1, 0);
  cin>>M;
  for(int i=0; i<M; i++) {
    cin>>a>>b;
    if(depth[a] != depth[b]) {
      if(depth[a] > depth[b]) {
        swap(a,b);
      }
      for(int i=maxLevel; i>=0; i--) {
        if(depth[a] <= depth[ac[b][i]]) {
          b = ac[b][i];
        }
      }
    }
    int lca = a;
    if(a != b) {
      for(int i=maxLevel; i>=0; i--) {
        if(ac[a][i] != ac[b][i]) {
          a = ac[a][i];
          b = ac[b][i];
        }
        lca = ac[a][i];
      }
    }
    cout<<lca<<"\n";
  }
  return 0;
}
