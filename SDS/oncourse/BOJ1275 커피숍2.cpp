#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

ll init(ll tree[], ll num[], int node, int start, int end) {
  if(start == end) {
    return tree[node] = num[start];
  }
  return tree[node] = init(tree, num, node*2, start, (start+end)/2) + init(tree, num, node*2+1, (start+end)/2+1, end);
}

void update(ll tree[], int node, int start, int end, int idx, ll diff) {
  if(idx < start || idx > end) {
    return;
  }
  tree[node] += diff;
  if(start != end) {
    update(tree, node*2, start, (start+end)/2, idx, diff);
    update(tree, node*2+1, (start+end)/2+1, end, idx, diff);
  }
}

ll sum(ll tree[], int node, int start, int end, int l, int r) {
  if(r < start || end < l) {
    return 0;
  }
  if(l <= start && end <= r) {
    return tree[node];
  }
  return sum(tree, node*2, start, (start+end)/2, l, r) + sum(tree, node*2+1, (start+end)/2+1, end, l, r);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N,Q,x,y,a,b;
  cin>>N>>Q;
  int height = ceil(log2(N));
  int tree_size = 1<<(height+1);
  ll num[N], tree[tree_size];
  for(int i=0; i<N; i++) {
    cin>>num[i];
  }
  init(tree, num, 1, 0, N-1);
  for(int i=0; i<Q; i++) {
    cin>>x>>y>>a>>b;
    if(x<=y) {
      cout<<sum(tree, 1, 0, N-1, x-1, y-1)<<"\n";
    } else {
      cout<<sum(tree, 1, 0, N-1, y-1, x-1)<<"\n";
    }
    ll diff = b - num[a-1];
    num[a-1] = b;
    update(tree, 1, 0, N-1, a-1, diff);
  }
  return 0;
}
