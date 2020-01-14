#include <iostream>
#include <vector>
#define INF 2e9

using namespace std;

typedef struct _hole{
  int tx,ty, t;
}Hole;
typedef struct _edge {
  int fx,fy,tx,ty,t;
}Edge;

int w,h,g,e,x,y,map[31][31], dist[31][31];
int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
Hole hole[31][31];
vector<Edge> graph;

void search() {
  for(int i=0; i<w; i++) {
    for(int j=0; j<h; j++) {
      if(i==w-1 && j==h-1) break;
      if(map[i][j] == 1) continue;
      if(map[i][j] == 2) graph.push_back({i,j,hole[i][j].tx,hole[i][j].ty, hole[i][j].t});
      else if(map[i][j] == 0) {
        for(int k=0; k<4; k++) {
          int nx = i + dir[k][0], ny = j + dir[k][1];
          if(nx < 0 || nx >= w || ny < 0 || ny >= h || map[nx][ny] == 1) continue;
          graph.push_back({i,j,nx,ny,1});
        }
      }
    }
  }
}

bool bellmanFord() {
  dist[0][0] = 0;
  for(int i=0; i<w*h-1; i++) {
    for(int j=0; j<graph.size(); j++) {
      Edge e = graph[j];
      if(dist[e.fx][e.fy] == INF) continue;
      if(dist[e.fx][e.fy]+e.t < dist[e.tx][e.ty]) dist[e.tx][e.ty] = dist[e.fx][e.fy] + e.t;
    }
  }
  for(int i=0; i<graph.size(); i++) {
    Edge e = graph[i];
    if(dist[e.fx][e.fy] == INF) continue;
    if(dist[e.fx][e.fy]+e.t < dist[e.tx][e.ty]) return 1;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while(cin>>w>>h, w&&h) {
    for(int i=0; i<w; i++) {
      for(int j=0; j<h; j++) {
        map[i][j] = 0; //0: 잔디, 1: 묘비, 2: 귀신구멍
        hole[i][j] = {i,j,0};
        dist[i][j] = INF;
      }
    }
    graph.clear();
    cin>>g;
    for(int i=0; i<g; i++) {
      cin>>x>>y;
      map[x][y] = 1;
    }
    cin>>e;
    for(int i=0; i<e; i++) {
      Hole h;
      cin>>x>>y>>h.tx>>h.ty>>h.t;
      hole[x][y] = h;
      map[x][y] = 2;
    }
    search();
    bool flag = bellmanFord();
    if(flag) cout<<"Never\n";
    else if(dist[w-1][h-1] == INF) cout<<"Impossible\n";
    else cout<<dist[w-1][h-1]<<"\n";
  }
  return 0;
}
