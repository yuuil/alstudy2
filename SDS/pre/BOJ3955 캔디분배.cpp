#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
  if(b == 0) {
    return a;
  }
  return gcd(b, a%b);
}

long long exteded_gcd(long long a, long long b) {
  long long r, q, ta = a, t, t1 = 0, t2 = 1;
  while(b != 0) {
    q = a/b;
    r = a%b;
    t = t1 - q*t2;
    a = b;
    b = r;
    t1 = t2;
    t2 = t;
  }
  while(t1 < 0) {
    t1 += ta;
  }
  return t1;
}

int main(){
  int T;
  long long K, C;
  cin>>T;
  for(int i=0; i<T; i++) {
    cin>>K>>C;
    if(C == 1) {
      if(K +1 > 1e9) {
        cout<<"IMPOSSIBLE\n";
        continue;
      } else {
        cout<<K+1<<"\n";
        continue;
      }
    } else if(K == 1) {
      cout<<"1\n";
      continue;
    } else if(gcd(K, C) != 1) {
      cout<<"IMPOSSIBLE\n";
      continue;
    }
    long long ans = exteded_gcd(K, C);
    if(ans > 1e9) {
      cout<<"IMPOSSIBLE\n";
    } else {
      cout<<ans<<"\n";
    }
  }
  return 0;
}
