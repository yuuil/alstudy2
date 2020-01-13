#include <iostream>
#define INF 987654321

using namespace std;
typedef long long ll;

const int MAX = 1e5+1;
int N,M,a,b,w,parent[MAX], s[MAX];
ll dist[MAX];
char cmd;

pair<int, ll> find(int x, ll ret) {
  if(x == parent[x]) return {x, ret};
  return find(parent[x], ret + dist[x]);
}

void merge(int x, int y, int dis) {
  auto a = find(x, 0), b = find(y, 0);
  if(a.first != b.first) {
    if(s[a.first] > s[b.first]) {
      dist[b.first] -= b.second - a.second - dis;
      parent[b.first] = a.first;
      s[a.first] += s[b.first];
      s[b.first] = 1;
    } else {
      dist[a.first] += b.second - a.second - dis;
      parent[a.first] = b.first;
      s[b.first] += s[a.first];
      s[a.first] = 1;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while(cin>>N>>M, !(N==0 && M==0)) {
    for(int i=1; i<=N; i++) {
      parent[i] = i;
      dist[i] = 0;
      s[i] = 1;
    }
    for(int i=0; i<M; i++) {
      cin>>cmd>>a>>b;
      if(cmd == '!') {
        cin>>w;
        merge(a,b,w);
      } else if(cmd == '?') {
        auto pa = find(a, 0), pb = find(b, 0);
        if(pa.first != pb.first) cout<<"UNKNOWN\n";
        else cout<<pb.second-pa.second<<"\n";
      }
    }
  }
  
  return 0;
}
