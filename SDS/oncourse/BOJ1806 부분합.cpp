#include <iostream>

using namespace std;

int accum[100001];

int main() {
  int N, S, len = 100001;
  cin>>N>>S;
  for(int i=1; i<=N; i++) {
    cin>>accum[i];
    accum[i] += accum[i-1];
  }
  int l=0, r=1;
  while(r<=N) {
    if(accum[r]-accum[l] >= S) {
      len = min(len, r-l);
      l++;
    } else {
      r++;
    }
  }
  cout<<(len==100001 ? 0 : len)<<"\n";
  return 0;
}
