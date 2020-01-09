#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int num[100001], bs[100001];

bool isExist(int n) {
  int l = 0, r = N-1;
  while(l <= r) {
    int mid = (l+r)/2;
    if(num[mid] < n) {
      l = mid + 1;
    } else if(num[mid] > n) {
      r = mid - 1;
    } else {
      return 1;
    }
  }
  return 0;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>N;
  for(int i=0; i<N; i++) {
    cin>>num[i];
  }
  sort(num, num+N);
  cin>>M;
  for(int i=0; i<M; i++) {
    cin>>bs[i];
    if(bs[i] > num[N-1] || bs[i] < num[0]) cout<<"0\n";
    else cout<<isExist(bs[i])<<"\n";
  }
  return 0;
}
