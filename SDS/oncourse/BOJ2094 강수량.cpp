#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m, Y, X;
const int MAX = 1e9;

int init(int *v, int *tree,int node,int start, int end) {
  if(start==end){
    return tree[node]=v[start];
  }
  return tree[node]=max(init(v,tree,node*2,start,(start+end)/2),
                        init(v,tree,node*2+1,(start+end)/2+1, end));
}

int query(int *tree, int node, int start, int end,int left,int right) {
  if(left>end || right<start){
    return 0;
  }
  if(left<=start&&end<=right){
    return tree[node];
  }
  return max(query(tree, node*2, start, (start+end)/2, left, right),
             query(tree, node*2+1, (start+end)/2+1, end, left, right));
}

int index(int *rain, int y) {
  return lower_bound(rain, rain+n, y) - rain;
}

bool isExist(int *year, int idx, int y) {
  if(idx == n || year[idx] != y) return 0;
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  int y[n], r[n];
  int height = ceil(log2(n));
  int tree_size = 1<<(height+1);
  int tree[tree_size];
  for(int i=0; i<n; i++) {
    cin>>y[i]>>r[i];
  }
  init(r, tree, 1, 0, n-1);
  cin>>m;
  for(int i=0; i<m; i++) {
    cin>>Y>>X;
    int yIdx = index(y, Y), xIdx = index(y, X);
    bool ye = isExist(y, yIdx, Y), xe = isExist(y, xIdx, X);
    if(ye && !xe) {
      int zm = query(tree, 1, 0, n-1, yIdx+1, xIdx-1);
      if(zm < r[yIdx]) {
        cout<<"maybe\n";
        continue;
      }
    } else if(!ye && xe) {
      int zm = query(tree, 1, 0, n-1, yIdx, xIdx-1);
      if(zm < r[xIdx]) {
        cout<<"maybe\n";
        continue;
      }
    } else if(!ye && !xe) {
      cout<<"maybe\n";
      continue;
    } else {
      int zm = query(tree, 1, 0, n-1, yIdx+1, xIdx-1);
      if(r[yIdx] >= r[xIdx] && zm < r[xIdx]) {
        if(xIdx-yIdx == X-Y) {
          cout<<"true\n";
        } else {
          cout<<"maybe\n";
        }
        continue;
      }
    }
    cout<<"false\n";
  }
  return 0;
}
