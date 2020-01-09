#include <iostream>
#include <algorithm>

using namespace std;

int tree[1000001];

int main() {
  int n,m, maxh=0;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>tree[i];
    maxh = max(maxh, tree[i]);
  }
  int l=0, r=maxh;
  while(l<=r) {
    long long sum=0;
    int mid = (l+r)/2;
    for(int i=0; i<n; i++) {
      sum += tree[i]>=mid ? tree[i]-mid : 0;
    }
    if(sum>=m) {
      l=mid+1;
    } else {
      r=mid-1;
    }
  }
  cout<<r<<"\n";
  return 0;
}
