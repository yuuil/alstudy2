#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int from, to, w, V, E, K, dist[20001];
vector<pair<int,int> > v[20001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>V>>E>>K;
  priority_queue<pair<int,int> > pq;
  for(int i=0; i<E; i++) {
    cin>>from>>to>>w;
    v[from].push_back(make_pair(to, w));
  }
  memset(dist, -1, sizeof(dist));
  pq.push(make_pair(0, K));
  while(!pq.empty()) {
    int d = -pq.top().first, n = pq.top().second;
    pq.pop();
    if(dist[n] != -1) continue;
    dist[n] = d;
    for(int i=0; i<v[n].size(); i++) {
      pair<int,int> next = v[n][i];
      if(dist[next.first] != -1) continue;
      pq.push(make_pair(-d-next.second, next.first));
    }
  }
  for(int i=1; i<=V; i++) {
    if(dist[i] == -1) cout<<"INF\n";
    else cout<<dist[i]<<"\n";
  }
  return 0;
}
