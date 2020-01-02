#include <iostream>

using namespace std;

long long comb[31][31];

int main() {
  for(int i=0; i<31; i++) {
    comb[i][0] = comb[i][i] = 1;
  }
  for(int i=2; i<31; i++) {
    for(int j=1; j<i; j++) {
      comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
    }
  }
  int T, N, M;
  cin>>T;
  for(int i=0; i<T; i++) {
    cin>>N>>M;
    cout<<comb[M][N]<<"\n";
  }
  return 0;
}
