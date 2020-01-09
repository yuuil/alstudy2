#include <iostream>

using namespace std;

bool pn[1001];
int N,K,cnt = 0;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
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
    if(cnt == K) break;
  }
  return 0;
}
