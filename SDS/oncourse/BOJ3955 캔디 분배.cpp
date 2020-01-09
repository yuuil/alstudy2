#include <iostream>

typedef long long ll;
using namespace std;

int t;
ll K,C, ans;

ll gcd(ll a, ll b) {
  if(b==0) return a;
  return gcd(b, a%b);
}

ll extended(ll a, ll b) {
  ll q, r, t, s=a, t0=0, t1=1;
  while(b!=0) {
    q = a/b;
    r = a%b;
    t = t0- q*t1;
    a = b;
    b = r;
    t0 = t1;
    t1 = t;
  }
  while(t0 < 0) {
    t0 += s;
  }
  return t0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  for(int i=0; i<t; i++) {
    cin>>K>>C;
    if(gcd(K,C) != 1) {
      cout<<"IMPOSSIBLE\n";
      continue;
    }
    if(C==1) {
      if(K+1 > 1e9) {
        cout<<"IMPOSSIBLE\n";
      } else {
        cout<<K+1<<"\n";
      }
      continue;
    } else if(K==1) {
      cout<<1<<"\n";
      continue;
    }
    ans = extended(K, C);
    if(ans > 1e9) {
      cout<<"IMPOSSIBLE\n";
    } else {
      cout<<ans<<"\n";
    }
  }
  return 0;
}
