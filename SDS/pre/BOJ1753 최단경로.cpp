#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int dist[20001];
vector<pair<int,int> > vt[20001];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int V, E, K;
  cin>>V>>E>>K;
  for(int i=0; i<E; i++) {
    int from, to, weight;
    cin>>from>>to>>weight;
    vt[from].push_back(make_pair(to, weight));
  }
  memset(dist, -1, sizeof(dist));
  
  priority_queue<pair<int, int> > pq; //(거리, 정점)으로 큐에 담음.
  pq.push(make_pair(0, K));
  while(!pq.empty()) {
    int to = pq.top().second;
    int cost = -pq.top().first;
    pq.pop();
    if(dist[to] != -1) {
      continue;
    }
    dist[to] = cost;
    vector<pair<int,int> >::iterator it;
    for(it = vt[to].begin(); it!=vt[to].end(); it++) {
      int next = it->first;
      int accum = -(it->second) - cost;
      if(dist[next] != -1) {
        continue;
      }
      pq.push(make_pair(accum, next));
    }
  }
  for(int i=1; i<=V; i++) {
    if(dist[i] == -1) {
      cout<<"INF\n";
    } else {
      cout<<dist[i]<<"\n";
    }
  }
  return 0;
}
