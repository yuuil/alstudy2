#include <iostream>

using namespace std;

int cnt;
bool pn[1001];

int main() {
  int N, K;
  cin>>N>>K;
  for(int i=2; i<=N; i++) {
      for(int j=i; j<=N; j+=i) {
        if(!pn[j]) {
          pn[j] = 1;
          if(++cnt == K) {
            cout<<j<<"\n";
            break;
          }
        }
      }
    if(cnt == K) {
      break;
    }
  }
  return 0;
}
