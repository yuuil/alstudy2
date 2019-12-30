#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N, M, K;

long long init(vector<long long> &num, vector<long long> &tree, int node, int start, int end) {
  if(start == end) {
    return tree[node] = num[start];
  } else {
    return tree[node] = init(num, tree, node*2, start, (start+end)/2) + init(num, tree, node*2+1, (start+end)/2
    +1, end);
  }
}

void update(vector<long long > &tree, int node, int start, int end, int idx, long long diff) {
  if(idx < start || idx > end) {
    return;
  }
  tree[node] = tree[node] + diff;
  if(start != end) {
    update(tree, node*2, start, (start+end)/2, idx, diff);
    update(tree, node*2+1, (start+end)/2+1, end, idx, diff);
  }
}

long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
  if(left > end || right < start) {
    return 0;
  }
  if(left <= start && end <= right) {
    return tree[node];
  }
  return sum(tree, node*2, start, (start+end)/2, left, right) + sum(tree, node*2+1, (start+end)/2+1, end, left, right);
}

int main() {
  cin>>N>>M>>K;
  vector<long long> num(N);
  int height = (int)ceil(log2(N));
  int tree_size = (1 << (height+1));
  vector<long long>tree(tree_size);
  for(int i=0; i<N; i++)  {
    cin>>num[i];
  }
  init(num, tree, 1, 0, N-1);
  for(int i=0; i<M+K; i++) {
    int a, b;
    long long c;
    cin>>a>>b>>c;
    if(a == 1) {
      long long diff = c - num[b-1];
      num[b-1] = c;
      update(tree, 1, 0, N-1, b-1, diff);
    } else {
      cout<<sum(tree, 1, 0, N-1, b-1, c-1)<<"\n";
    }
  }
  return 0;
}
