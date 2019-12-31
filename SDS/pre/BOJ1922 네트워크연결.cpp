#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _connection {
  int from;
  int to;
  int cost;
}Conn;

int N, M;
int parent[1001];
vector<Conn> net;
bool chk;

bool comp(Conn c1, Conn c2) {
  return c1.cost < c2.cost;
}

int find(int p) {
  if(p == parent[p]) {
    return p;
  }
  return parent[p] = find(parent[p]);
}

void merge(int x, int y) {
  chk = false;
  x = find(x);
  y = find(y);
  if(x == y) {
    return;
  }
  parent[x] = y;
  chk = true;
}

int main() {
  int weight = 0;
  cin>>N>>M;
  for(int i=1; i<=N; i++) {
    parent[i] = i;
  }
  for(int i=0; i<M; i++) {
    Conn conn;
    cin>>conn.from>>conn.to>>conn.cost;
    net.push_back(conn);
  }
  sort(net.begin(), net.end(), comp);
  
  for(int i=0; i<M; i++) {
    merge(net[i].from, net[i].to);
    if(chk) {
      weight += net[i].cost;
    }
  }
  cout<<weight<<"\n";
  return 0;
}
