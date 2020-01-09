#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

bool flag;
int N,M;
ll num, ans=1, a[1001];
const ll lim = 1e9;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a%b);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>N;
  for(int i=0; i<N; i++) {
    cin>>a[i];
  }
  cin>>M;
  for(int i=0; i<M; i++) {
    cin>>num;
    for(int j=0; j<N; j++) {
      if(num==1) break;
      if(a[j] == 1) continue;
      ll g = gcd(num, a[j]);
      if(g!=1) {
        a[j]/=g;
        ans *= g;
        num/=g;
        if(ans > lim) {
          ans%=lim;
          flag = 1;
        }
      }
    }
  }
  if(flag) {
    string ret = to_string(ans);
    while(ret.length() < 9) {
      ret = "0" + ret;
    }
    cout<<ret<<"\n";
  } else {
    cout<<ans<<"\n";
  }
  return 0;
}
