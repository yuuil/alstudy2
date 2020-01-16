#include <iostream>
#include <cstring>
#define INF 987654321

using namespace std;
typedef pair<int,int> pii;
int N, W, ans, dp[1001][1001], t[1001];
pii accid[1001];

int dist(pii p1, pii p2) {
  return abs(p1.first-p2.first) + abs(p1.second-p2.second);
}

int send(int x, int y) {
  if(x == W || y == W) return 0;
  int &ret = dp[x][y];
  if(ret != -1) return ret;
  int p1, p2;
  if(!x) p1 = send(max(x,y)+1, y) + dist(accid[max(x,y)+1], make_pair(1,1));
  else p1 = send(max(x,y)+1, y) + dist(accid[max(x,y)+1], accid[x]);
  if(!y) p2 = send(x, max(x,y)+1) + dist(accid[max(x,y)+1], make_pair(N,N));
  else p2 = send(x, max(x,y)+1) + dist(accid[max(x,y)+1], accid[y]);
  return ret = min(p1,p2);
}

void solve(int x, int y) {
  if(x == W || y == W) return;
  int p1, p2;
  if(!x) p1 = send(max(x,y)+1, y) + dist(accid[max(x,y)+1], make_pair(1,1));
  else p1 = send(max(x,y)+1, y) + dist(accid[max(x,y)+1], accid[x]);
  if(!y) p2 = send(x, max(x,y)+1) + dist(accid[max(x,y)+1], make_pair(N,N));
  else p2 = send(x, max(x,y)+1) + dist(accid[max(x,y)+1], accid[y]);
  if(p1 < p2) {
    t[max(x,y)+1] = 1;
    solve(max(x,y)+1, y);
  }
  else {
    t[max(x,y)+1] = 2;
    solve(x, max(x,y)+1);
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin>>N>>W;
  for(int i=1; i<=W; i++) cin>>accid[i].first>>accid[i].second;
  memset(dp, -1, sizeof(dp));
  cout<<send(0,0)<<"\n";
  solve(0,0);
  for(int i=1; i<=W; i++) {
    cout<<t[i]<<"\n";
  }
  return 0;
}
