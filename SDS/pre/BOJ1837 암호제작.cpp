#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int MAX = 1e6+1;
bool pn[MAX];
string P;

bool chk(int k) {
  int ret = 0;
  for(int i=0; i<P.size(); i++) {
    ret = (ret * 10 + P[i] - '0') % k;
  }
  return !ret;
}

int main() {
  bool flag = true;
  int K;
  cin>>P>>K;
  for(int i=2; i<MAX; i++) {
    pn[i] = 1;
  }
  for(int i=2; i<sqrt(MAX); i++) {
    if(!pn[i]) {
      continue;
    }
    for(int j=i*i; j<MAX; j+=i) {
      pn[j] = 0;
    }
  }
  for(int i=2; i<K; i++) {
    if(pn[i] && chk(i)) {
      cout<<"BAD "<<i<<"\n";
      flag = false;
      break;
    }
  }
  if(flag) {
    cout<<"GOOD\n";
  }
  return 0;
}
