#include <iostream>

using namespace std;

int M,N,K,col[51];
double accum = 0.0;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(9);
  cin>>M;
  for(int i=0; i<M; i++) {
    cin>>col[i];
    N+=col[i];
  }
  cin>>K;
  for(int i=0; i<M; i++) {
    double part = 1;
    if(col[i] >= K) {
      for(int j=0; j<K; j++) {
        part *= (double)(col[i]-j)/(N-j);
      }
      accum += part;
    }
  }
  cout.precision(9);
  cout<<accum<<"\n";
  return 0;
}
