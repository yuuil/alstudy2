#include <iostream>
#include <climits>

using namespace std;

typedef struct _bus{
  int from, to, cost;
}Bus;

int N,M;
int dist[101][101];
Bus bus[100001];

int main(){
  cin>>N>>M;
  for(int i=0; i<M; i++) {
    cin>>bus[i].from>>bus[i].to>>bus[i].cost;
    if(!dist[bus[i].from][bus[i].to]) {
      dist[bus[i].from][bus[i].to] = bus[i].cost;
    } else {
      dist[bus[i].from][bus[i].to] = min(dist[bus[i].from][bus[i].to], bus[i].cost);
    }
  }
  for(int via=1; via<=N; via++) {
    for(int f=1; f<=N; f++) {
      if(dist[f][via] == 0) {
        continue;
      }
      for(int t=1; t<=N; t++) {
        if(dist[via][t] == 0 || f == t) {
          continue;
        }
        if(dist[f][t] == 0 || dist[f][via] + dist[via][t] < dist[f][t]) {
          dist[f][t] = dist[f][via] + dist[via][t];
        }
      }
    }
  }
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      cout<<dist[i][j]<<" ";
    }
    cout<<"\n";
  }
  return 0;
}
