#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 1e7+1;
bool pn[MAX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  for(int i=2; i<sqrt(MAX); i++) {
    if(!pn[i]) {
      for(int j=i+i; j<MAX; j+=i) {
        pn[j] = 1;
      }
    }
  }
  cin>>N;
  for(int i=2; i<=N; i++) {
    if(!pn[i]) {
      while(!(N%i)) {
        N/=i;
        cout<<i<<"\n";
      }
    }
  }
  return 0;
}
