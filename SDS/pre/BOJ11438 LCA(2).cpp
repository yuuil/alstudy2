#include <iostream>
#include <vector>
#include <cmath>

#define swap(a,b){int t = a; a = b; b = t;}
#define MAX 100001

using namespace std;

int depth[MAX], ac[MAX][20];
vector<int> tree[MAX];
int maxLevel;

void getTree(int node, int parent) {
  depth[node] = depth[parent] + 1;
  ac[node][0] = parent;
  maxLevel = (int)floor(log2(MAX));
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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M;
  cin>>N;
  for(int i=1; i<N; i++) {
    int from, to;
    cin>>from>>to;
    tree[from].push_back(to);
    tree[to].push_back(from);
  }
  depth[0] = -1;
  getTree(1, 0);
  cin>>M;
  for(int i=0; i<M; i++) {
    int a, b;
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
    int dep = depth[a];
    if(a != b) {
      for(int i=dep; i>=0; i--) {
        if(ac[a][i] != ac[b][i]) {
          a = ac[a][i];
          b = ac[b][i];
        }
        lca = ac[a][i];
      }
    }
    cout<<lca<<"\n";
  }
}
