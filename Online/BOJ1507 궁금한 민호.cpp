#include <iostream>

using namespace std;

bool conn[21][21];
int N,dist[21][21];

bool floyd() {
    for(int v=1; v<=N; v++) {
        for(int f=1; f<=N; f++) {
            for(int t=1; t<=N; t++) {
                if(v==f || v==t || f==t) continue;
                if(dist[f][t] > dist[f][v]+dist[v][t]) return 0;
                if(dist[f][t] == dist[f][v]+dist[v][t]) conn[f][t]=0;
            }
        }
    }
    return 1;
}


int main() {
    cin>>N;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin>>dist[i][j];
            conn[i][j]=1;
        }
    }
    if(floyd()) {
        int res = 0;
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                if(conn[i][j]) res += dist[i][j];
            }
        }
        cout<<res/2<<"\n";
    } else cout<<"-1\n";
    return 0;
}