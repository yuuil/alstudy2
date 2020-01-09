#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 1e6+1;
bool flag, pn[MAX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  pn[0]=pn[1]=1;
  for(int i=2; i<sqrt(MAX); i++) {
    if(!pn[i]) {
      for(int j=i+i; j<MAX; j+=i) {
        pn[j]=1;
      }
    }
  }
  int n;
  while(cin>>n) {
    if(n == 0) {
      break;
    }
    for(int i=2; i<=n; i++) {
      if(!pn[i] && !pn[n-i]) {
        cout<<n<<" = "<<i<<" + "<<(n-i)<<"\n";
        flag = true;
        break;
      }
    }
  }
  if(!flag) cout<<"Goldbach's conjecture is wrong.\n";
  return 0;
}
