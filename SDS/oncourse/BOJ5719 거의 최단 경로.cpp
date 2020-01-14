#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n,m,s,d,u,v,p, conn[501][501], dist[501];

void Dijkstra() {
  memset(dist, -1, sizeof(dist));
  priority_queue<pair<int,int> > pq;
  pq.push(make_pair(0,s));
  while(!pq.empty()) {
    int node = pq.top().second, c = -pq.top().first;
    pq.pop();
    if(dist[node] != -1) continue;
    dist[node] = c;
    for(int i=0; i<n; i++) {
      if(conn[node][i] == -1 || dist[i] != -1) continue;
      pq.push(make_pair(-c-conn[node][i], i));
    }
  }
}

void remove() {
  queue<int> q;
  q.push(d);
  while(!q.empty()) {
    int curr = q.front();
    q.pop();
    for(int i=0; i<n; i++) {
      if(dist[curr] == dist[i] + conn[i][curr] && conn[i][curr] != -1) {
        conn[i][curr] = -1;
        q.push(i);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  while(cin>>n>>m, !!n&&!!m) {
    cin>>s>>d;
    memset(conn, -1, sizeof(conn));
    for(int i=0; i<m; i++) {
      cin>>u>>v>>p;
      conn[u][v] = p;
    }
    Dijkstra();
    remove();
    Dijkstra();
    cout<<dist[d]<<"\n";
  }
  
  return 0;
}
