#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int> > edge[1001];
priority_queue<int> path[1001];
int n,m,k,a,b,c;

struct comp {
  bool operator()(pair<int,int> &p1, pair<int,int> &p2) {
    return p1.second > p2.second;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m>>k;
  priority_queue<pair<int,int>, vector<pair<int,int> >, comp> q;
  for(int i=0; i<m; i++) {
    cin>>a>>b>>c;
    edge[a].push_back(make_pair(b,c));
  }
  q.push(make_pair(1,0));
  path[1].push(0);
  while(!q.empty()) {
    int to = q.top().first, c = q.top().second;
    q.pop();
    for(int i=0; i<edge[to].size(); i++) {
      pair<int,int> next = edge[to][i];
      if(path[next.first].size() < k) {
        path[next.first].push(c+next.second);
      } else if(path[next.first].top() > c+next.second) {
        path[next.first].pop();
        path[next.first].push(c+next.second);
      } else continue;
      q.push(make_pair(next.first, c+next.second));
    }
  }
  for(int i=1; i<=n; i++) {
    cout<<(path[i].size() == k ? path[i].top() : -1)<<"\n";
  }
  return 0;
}
