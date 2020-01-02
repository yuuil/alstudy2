#include <iostream>

using namespace std;

int accum[100001];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin>>N>>M;
  for(int i=1; i<=N; i++) {
    int temp;
    cin>>temp;
    accum[i] = accum[i-1] + temp;
  }
  for(int i=0; i<M; i++) {
    int s, e;
    cin>>s>>e;
    cout<<accum[e]-accum[s-1]<<"\n";
  }
  return 0;
}
