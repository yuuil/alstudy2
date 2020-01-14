#include <iostream>

using namespace std;

int N,M,x1,y1,x2,y2,square[1025][1025];
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin>>N>>M;
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      cin>>square[i][j];
      square[i][j] += square[i][j-1];
    }
  }
  for(int i=0; i<M; i++) {
    int accum = 0;
    cin>>x1>>y1>>x2>>y2;
    for(int i=x1; i<=x2; i++) {
      accum += square[i][y2] - square[i][y1-1];
    }
    cout<<accum<<"\n";
  }
  return 0;
}
