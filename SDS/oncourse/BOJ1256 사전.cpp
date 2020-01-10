#include <iostream>

using namespace std;
typedef long long ll;

const int MAX = 1e9+1;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m, k;
  ll comb[201][201];
  
  for(int i=0; i<201; i++) {
    comb[i][0] = comb[i][i] = 1;
  }
  for(int i=2; i<201; i++) {
    for(int j=1; j<101 && j<i; j++) {
      comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
      if(comb[i][j] > 1e9) {
        comb[i][j] = MAX;
      }
    }
  }
  cin>>n>>m>>k;
  if(k > comb[n+m][m]) {
    cout<<-1<<"\n";
    return 0;
  }
  int cnt=n+m;
  while(cnt--) {
    if(k <= comb[n+m-1][m]) {
      cout<<"a";
      n--;
    } else {
      cout<<"z";
      k -= comb[n+m-1][m];
      m--;
    }
  }
  return 0;
}
