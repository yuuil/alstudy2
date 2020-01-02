#include <iostream>

using namespace std;

int comb[1001][1001];

int main() {
  for(int i=0; i<1001; i++) {
    comb[i][0] = comb[i][i] = 1;
  }
  for(int i=2; i<1001; i++) {
    for(int j=1; j<i; j++) {
      comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % 10007;
    }
  }
  int N,K;
  cin>>N>>K;
  cout<<comb[N][K]<<"\n";
  return 0;
}
