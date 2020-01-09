#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int K, ans, accum;
string code;
const int MAX = 1e6+1;
bool pn[MAX];

int chk() {
  for(int i=2; i<K; i++) {
    if(pn[i]) {
      accum = 0;
      for(int j=0; j<code.length(); j++) {
        accum = (accum*10 + code[j]-'0')%i;
      }
      if(accum == 0) return i;
    }
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(pn, 1, sizeof(pn));
  pn[0] = pn[1] = 0;
  for(int i=2; i<=sqrt(MAX); i++) {
    if(pn[i]) {
      for(int j=i+i; j<=MAX; j+=i) {
        pn[j] = 0;
      }
    }
  }
  cin>>code>>K;
  ans = chk();
  if(ans > 1) {
    cout<<"BAD "<<ans<<"\n";
  } else {
    cout<<"GOOD\n";
  }
  return 0;
}
