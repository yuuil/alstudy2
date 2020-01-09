#include <iostream>
#include <vector>
#include <cmath>

typedef long long ll;
using namespace std;

int n,a,b,c;
const int MAX = 1e6;

void update(vector<ll> &tree, int node, int start, int end, int idx, ll diff) {
  if(idx < start || idx > end) {
    return;
  }
  tree[node] += diff;
  if(start!=end) {
    update(tree, node*2, start, (start+end)/2, idx, diff);
    update(tree, node*2+1, (start+end)/2+1, end, idx, diff);
  }
}

ll query(vector<ll> &tree, int node, int start, int end, int k) {
  if(start == end) {
    return start;
  }
  int mid = (start+end)/2;
  if(tree[node*2] >= k) return query(tree, node*2, start, mid, k);
  else return query(tree, node*2+1, mid+1, end, k-tree[node*2]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int height = ceil(log2(MAX));
  int tree_size = 1<<(height+1);
  vector<ll> tree(tree_size);
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>a;
    if(a==1) {
      cin>>b;
      b = query(tree, 1, 0, MAX-1, b);
      cout<<b<<"\n";
      update(tree, 1, 0, MAX-1, b, -1);
    } else {
      cin>>b>>c;
      update(tree, 1, 0, MAX-1, b, c);
    }
  }
  return 0;
}
