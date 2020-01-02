#include <iostream>
#include <climits>

using namespace std;

typedef struct _edge{
  int src, dest, weight;
}Edge;

int N, M;
int dist[501];
Edge bus[6001];

bool BellmanFord(int src) {
  for(int i=1; i<=N; i++) {
    dist[i] = INT_MAX;
  }
  dist[src] = 0;
  for(int i=1; i<N; i++) {
    for(int j=0; j<M; j++) {
      int u = bus[j].src;
      int v = bus[j].dest;
      int c = bus[j].weight;
      if(dist[u] != INT_MAX && (dist[u] + c < dist[v]) ) {
        dist[v] = dist[u] + c;
      }
    }
  }
  for(int i=0; i<M; i++) {
    int u = bus[i].src;
    int v = bus[i].dest;
    int c = bus[i].weight;
    if(dist[u] != INT_MAX && dist[u] + c < dist[v]) {
      return 0;
    }
  }
  return 1;
}

int main(){
  cin>>N>>M;
  for(int i=0; i<M; i++) {
    cin>>bus[i].src>>bus[i].dest>>bus[i].weight;
  }
  if(!BellmanFord(1)) {
    cout<<"-1\n";
  } else {
    for(int i=2; i<=N; i++) {
      cout<<(dist[i] < INT_MAX ? dist[i] : -1)<<"\n";
    }
  }
  return 0;
}
