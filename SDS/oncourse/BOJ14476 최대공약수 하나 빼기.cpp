#include <iostream>

using namespace std;

const int MAX = 1e6+1;
int N,K,ans=-1,idx=-1,num[MAX],lgcd[MAX], rgcd[MAX];

int gcd(int a, int b) {
  if(b==0) return a;
  return gcd(b, a%b);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>N;
  for(int i=1; i<=N; i++) {
    cin>>num[i];
    if(i==1) lgcd[0] = num[i];
    lgcd[i] = gcd(lgcd[i-1], num[i]);
  }
  rgcd[N]=num[N];
  for(int i=N-1; i>=1; i--) {
    rgcd[i] = gcd(rgcd[i+1], num[i]);
  }
  for(int i=1; i<=N; i++) {
    if(i==1) {
      if(rgcd[i+1] % num[i] && num[i]%rgcd[i+1]) {
        ans = max(ans, rgcd[i+1]);
        if(ans == rgcd[i+1]) idx = i;
      }
    } else if(i==N) {
      if(lgcd[i-1] % num[i] && num[i]%lgcd[i-1]) {
        ans = max(ans, lgcd[i-1]);
        if(ans == lgcd[i-1]) idx = i;
      }
    } else {
      int g = gcd(lgcd[i-1], rgcd[i+1]);
      if(g%num[i] && num[i]%g) {
        ans = max(ans, g);
        if(ans == g) idx = i;
      }
    }
  }
  if(ans > -1) {
    cout<<ans<<" "<<num[idx]<<"\n";
  } else {
    cout<<-1<<"\n";
  }
  return 0;
}
