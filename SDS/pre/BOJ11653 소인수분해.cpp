#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 1e7+1;
bool pn[MAX];

void make_pn() {
  for(int i=2; i<MAX; i++) {
    pn[i] = 1;
  }
  for(int i=2; i<=sqrt(MAX); i++) {
    if(pn[i]) {
      for(int j=i+i; j<MAX; j+=i) {
        pn[j] = 0;
      }
    }
  }
}

int main(){
  int N;
  cin>>N;
  make_pn();
  for(int i=2; i<=N; i++) {
    if(pn[i]) {
      while(N % i == 0) {
        cout<<i<<"\n";
        N /= i;
      }
    }
  }
  return 0;
}
