#include <iostream>
#include <cmath>

using namespace std;

int N,M,K,a,b;
long long c;

long long init(long long* tree, long long* num, int node, int start, int end) {
  if(start == end) {
    return tree[node] = num[start];
  }
  return tree[node] = init(tree, num, node*2, start, (start+end)/2) + init(tree, num, node*2+1, (start+end)/2+1, end);
}

void update(long long* tree, int node, int start, int end, int idx, long long diff) {
  if(idx < start || idx > end) {
    return;
  }
  tree[node]+=diff;
  if(start != end) {
    update(tree, node*2, start, (start+end)/2, idx, diff);
    update(tree, node*2+1, (start+end)/2+1, end, idx, diff);
  }
}

long long sum(long long* tree, int node, int start, int end, int l, int r) {
  if(end < l || start > r) {
    return 0;
  }
  if(l <= start && end<= r) {
    return tree[node];
  }
  return sum(tree, node*2, start, (start+end)/2, l, r) + sum(tree, node*2+1, (start+end)/2+1, end, l, r);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>N>>M>>K;
  
  int height = ceil(log2(N));
  int tree_size = 1<<(height+1);
  long long num[N], tree[tree_size];
  
  for(int i=0; i<N; i++) {
    cin>>num[i];
  }
  init(tree, num, 1, 0, N-1);
  for(int i=0; i<M+K; i++) {
    cin>>a>>b>>c;
    if(a==1) {
      long long diff = c-num[b-1];
      num[b-1]=c;
      update(tree, 1, 0, N-1, b-1, diff);
    } else {
      cout<<sum(tree, 1, 0, N-1, b-1, c-1)<<"\n";
    }
  }
  return 0;
}
