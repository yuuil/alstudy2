#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 1e6+1;
int N, temp, ans, gca = 1, gc[MAX], pf[MAX], paper[101], cmp[MAX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>N;
  for(int i=0; i<N; i++) {
    cin>>paper[i];
    temp = paper[i];
    for(int i=2; i<MAX; i++) {
      while(!(temp % i)) {
        temp/=i;
        pf[i]++;
      }
    }
  }
  for(int i=2; i<MAX; i++) {
    if(pf[i] >= N) {
      gc[i] = pf[i]/N;
      for(int j=0; j<gc[i]; j++) {
        gca *= i;
      }
    }
  }
  for(int i=0; i<N; i++) {
    temp = paper[i];
    memset(cmp, 0, sizeof(cmp));
    for(int j=2; j<=temp; j++) {
      while(!(temp%j)) {
        temp/=j;
        cmp[j]++;
      }
    }
    for(int j=2; j<MAX; j++) {
      if(cmp[j] < gc[j]) {
        ans += gc[j]-cmp[j];
      }
    }
  }
  cout<<gca<<" "<<ans<<"\n";
  return 0;
}
