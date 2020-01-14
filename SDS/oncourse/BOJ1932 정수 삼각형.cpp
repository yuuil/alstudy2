#include <iostream>

using namespace std;

int N, m,tri[501][501];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin>>N;
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=i; j++) {
      cin>>tri[i][j];
      tri[i][j] += max(tri[i-1][j], tri[i-1][j-1]);
    }
  }
  for(int i=1; i<=N; i++) {
    m = max(m, tri[N][i]);
  }
  cout<<m<<"\n";
  return 0;
}
