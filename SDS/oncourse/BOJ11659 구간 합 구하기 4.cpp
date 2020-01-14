#include <iostream>

using namespace std;

int N,M,a,b,accum[100001];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin>>N>>M;
  for(int i=1; i<=N; i++) {
    cin>>accum[i];
    accum[i] += accum[i-1];
  }
  for(int i=0; i<M; i++) {
    cin>>a>>b;
    cout<<accum[b]-accum[a-1]<<"\n";
  }
  return 0;
}
