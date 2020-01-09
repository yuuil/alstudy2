#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 4e6+1;
bool pn[MAX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,cnt=0;
  for(int i=2; i<=sqrt(MAX); i++) {
    if(!pn[i]) {
      for(int j=i+i; j<=MAX; j+=i) {
        pn[j] = 1;
      }
    }
  }
  cin>>N;
  for(int i=2; i<=N; i++) {
    int sum = 0;
    if(!pn[i]) {
      sum += i;
      if(sum == N) {
        cnt++;
        continue;
      }
      for(int j=i+1; j<=N; j++) {
        if(!pn[j]) sum += j;
        if(sum == N) cnt++;
        if(sum >= N) break;
      }
    }
  }
  cout<<cnt<<"\n";
  return 0;
}
