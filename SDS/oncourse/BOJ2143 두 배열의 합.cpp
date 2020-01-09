#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int t, n, m, idx = 0;
  long long cnt = 0;
  int a[1001], b[1001];
  vector<long long> suma, sumb;
  cin>>t>>n;
  for(int i=1; i<=n; i++) {
    cin>>a[i];
    a[i] += a[i-1];
    for(int j=0; j<i; j++) {
      suma.push_back(a[i]-a[j]);
    }
  }
  cin>>m;
  for(int i=1; i<=m; i++) {
    cin>>b[i];
    b[i] += b[i-1];
    for(int j=0; j<i; j++) {
      sumb.push_back(b[i]-b[j]);
    }
  }
  sort(suma.begin(), suma.end());
  sort(sumb.begin(), sumb.end());
  int l = 0, r = sumb.size()-1;
  while(r>=0 && l <suma.size()) {
    long long sum = suma[l] + sumb[r];
    if(sum > t) {
      r--;
    } else if(sum < t) {
      l++;
    } else {
      int temp = l;
      long long lcnt = 0, rcnt = 0;
      while(l < suma.size() && suma[l] == suma[temp]){
        lcnt++;
        l++;
      }
      temp = r;
      while(r >= 0 && sumb[r] == sumb[temp]) {
        rcnt++;
        r--;
      }
      cnt += lcnt*rcnt;
    }
  }
  cout<<cnt<<"\n";
  return 0;
}
