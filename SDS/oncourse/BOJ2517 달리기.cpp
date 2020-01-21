#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int MAX = 5e5+1;
int N;
pair<int,int> athe[MAX];

int update(vector<int> &tree, int node, int val, int start, int end) {
  if(val < start || val > end) return tree[node];
  if(start == end) return tree[node] = 1;
  return tree[node] = update(tree, node*2, val, start, (start+end)/2)
  + update(tree, node*2+1, val, (start+end)/2+1, end);
}

int query(vector<int> &tree, int node, int val, int start, int end) {
  if(val < start) return tree[node];
  if(val > end || start == end) return 0;
  return query(tree, node*2, val, start, (start+end)/2) + query(tree, node*2+1, val, (start+end)/2+1, end);
}

bool comp(pair<int,int> a, pair<int,int> b) {
  return a.second < b.second;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>N;
  for(int i=0; i<N; i++) {
    cin>>athe[i].first;
    athe[i].second = i;
  }
  sort(athe, athe+N);
  for(int i=0; i<N; i++) athe[i].first = i;
  sort(athe, athe+N, comp);
  int height = ceil(log2(N));
  int tree_size = 1<<(height+1);
  vector<int> tree(tree_size);
  for(int i=0; i<N; i++) {
    cout<<1+query(tree, 1, athe[i].first, 0, N-1)<<"\n";
    update(tree, 1, athe[i].first, 0, N-1);
  }
  return 0;
}
