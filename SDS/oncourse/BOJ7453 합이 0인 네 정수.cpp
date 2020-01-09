#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, a[4001], b[4001], c[4001], d[4001];
long long cnt=0;
vector<int> sum1, sum2;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>a[i]>>b[i]>>c[i]>>d[i];
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      sum1.push_back(a[i]+b[j]);
      sum2.push_back(c[i]+d[j]);
    }
  }
  sort(sum1.begin(), sum1.end());
  sort(sum2.begin(), sum2.end());
  int l=0, r=sum1.size()-1;
  while(l<sum1.size() && r>=0) {
    if(sum1[l]+sum2[r] > 0) {
      r--;
    } else if(sum1[l]+sum2[r] < 0) {
      l++;
    } else {
      long long lcnt=0, rcnt=0;
      int temp=l;
      while(l<sum1.size() && sum1[l]==sum1[temp]) {
        lcnt++;
        l++;
      }
      temp=r;
      while(r>=0 && sum2[r]==sum2[temp]) {
        rcnt++;
        r--;
      }
      cnt += lcnt*rcnt;
    }
  }
  cout<<cnt<<"\n";
  return 0;
}
