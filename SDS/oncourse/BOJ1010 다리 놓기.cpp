#include <iostream>

using namespace std;
typedef long long ll;

int t, n, m;
ll perm[31][31];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i=0; i<31; i++) {
    perm[i][0] = perm[i][i] = 1;
  }
  for(int i=1; i<31; i++) {
    for(int j=1; j<=i; j++) {
      perm[i][j] = perm[i-1][j-1] + perm[i-1][j];
    }
  }
  cin>>t;
  for(int i=0; i<t; i++) {
    cin>>n>>m;
    cout<<perm[m][n]<<"\n";
  }
  return 0;
}
