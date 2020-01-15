#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;
int N;
ll ans, cake[2001], dp[2001][2001];

ll ioi(int l, int r);
ll joi(int l, int r);

int left(int x) {return (x+N-1)%N;}
int right(int x) {return (x+1)%N;}

ll ioi(int l, int r) {
  if(right(r) == l) return 0;
  if(cake[left(l)] > cake[right(r)]) return joi(left(l), r);
  return joi(l, right(r));
}

ll joi(int l, int r) {
  ll &ret = dp[l][r];
  if(ret != -1) return ret;
  if(right(r) == l) return 0;
  ll t1 = cake[left(l)] + ioi(left(l), r), t2 = cake[right(r)] + ioi(l, right(r));
  return ret = max(t1, t2);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin>>N;
  for(int i=0; i<N; i++) cin>>cake[i];
  memset(dp, -1, sizeof(dp));
  for(int i=0; i<N; i++) {
    ans = max(ans, cake[i] + ioi(i,i));
  }
  cout<<ans<<"\n";
  return 0;
}
