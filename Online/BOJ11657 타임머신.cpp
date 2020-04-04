#include <iostream>

using namespace std;

typedef struct _bus{
    int from,to,cost;
}Bus;

const int MAX = 1e9;
int N,M,a,b,c,dist[501];
Bus bus[6001];

bool bellmanFord(int src) {
    for(int i=1; i<=N; i++) dist[i] = MAX;
    dist[src] = 0;
    for(int i=1; i<=N; i++) {
        for(int j=0; j<M; j++) {
            int u = bus[j].from, v = bus[j].to, c = bus[j].cost;
            if(dist[u] != MAX && dist[u] + c < dist[v]) dist[v] = dist[u] + c;
        }
    }
    for(int i=0; i<M; i++) {
        int u = bus[i].from, v = bus[i].to, c = bus[i].cost;
        if(dist[u] != MAX && dist[u] + c < dist[v]) return 0;
    }
    return 1;
}

int main() {
    cin>>N>>M;
    for(int i=0; i<M; i++) cin>>bus[i].from>>bus[i].to>>bus[i].cost;
    if(bellmanFord(1)) {
        for(int i=2; i<=N; i++) {
            cout<<(dist[i] != MAX ? dist[i] : -1)<<"\n";
        }
    } else cout<<"-1\n";
    return 0;
}