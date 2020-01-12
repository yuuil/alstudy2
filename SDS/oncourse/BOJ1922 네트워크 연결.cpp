#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _conn{
  int from, to, cost;
}Conn;

bool chk;
int N, M, w, p[1001];
vector<Conn> net;

bool comp(Conn c1, Conn c2) {
  return c1.cost < c2.cost;
}

int find(int x) {
  if(x == p[x]) return x;
  return p[x] = find(p[x]);
}

void merge(int x, int y) {
  chk = 0;
  x = find(x);
  y = find(y);
  if(x == y) return;
  p[x] = y;
  chk = 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>N>>M;
  for(int i=1; i<=N; i++) {
    p[i] = i;
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
      w += net[i].cost;
    }
  }
  cout<<w<<"\n";
  return 0;
}
