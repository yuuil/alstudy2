#include <iostream>
#define INF 987654321

using namespace std;

typedef struct _bus{
  int from, to, dist;
}Bus;

int N,M,t[501];
Bus bus[6001];

bool bellman_ford(int src) {
  for(int i=1; i<=N; i++) {
    t[i] = INF;
  }
  t[src] = 0;
  for(int i=1; i<=N; i++) {
    for(int j=0; j<M; j++) {
      int u = bus[j].from, v = bus[j].to, d = bus[j].dist;
      if(t[u] != INF && t[u] + d < t[v]) t[v] = t[u] + d;
    }
  }
  for(int i=0; i<M; i++) {
    int u = bus[i].from, v = bus[i].to, d = bus[i].dist;
    if(t[u] != INF && t[u] + d < t[v]) return 0;
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>N>>M;
  for(int i=0; i<M; i++) {
    cin>>bus[i].from>>bus[i].to>>bus[i].dist;
  }
  if(!bellman_ford(1)) {
    cout<<-1<<"\n";
  } else {
    for(int i=2; i<=N; i++) {
      if(t[i] == INF) cout<<-1<<"\n";
      else cout<<t[i]<<"\n";
    }
  }
  return 0;
}
