#include <iostream>
#include <cstring>
#define INF 987654321

using namespace std;

string dev;
int N, P, on, onCnt, cost[17][17], dp[1<<17];

int solve(int state, int cnt) {
  if(cnt >= P) return 0;
  int &ret = dp[state];
  if(ret != -1) return ret;
  ret = INF;
  for(int i=0; i<N; i++) {
    if(!(state & (1<<i))) continue;
    for(int j=0; j<N; j++) {
      if(state & (1<<j)) continue;
      ret = min(ret, solve(state | (1<<j), cnt+1)+cost[i][j]);
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin>>N;
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cin>>cost[i][j];
    }
  }
  cin>>dev>>P;
  for(int i=0; i<N; i++) {
    if(dev[i] == 'Y') {
      on |= (1<<i);
      onCnt++;
    }
  }
  memset(dp, -1, sizeof(dp));
  int ans = solve(on, onCnt);
  if(ans == INF) cout<<-1<<"\n";
  else cout<<ans<<"\n";
  return 0;
}
