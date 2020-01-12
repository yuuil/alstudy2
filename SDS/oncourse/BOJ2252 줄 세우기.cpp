#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, a, b, ind[32001];
vector<int> conn[32001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  queue<int> seq;
  cin>>N>>M;
  for(int i=0; i<M; i++) {
    cin>>a>>b;
    ind[b]++;
    conn[a].push_back(b);
  }
  for(int i=1; i<=N; i++) {
    if(!ind[i]) {
      seq.push(i);
    }
  }
  while(!seq.empty()) {
    int n = seq.front();
    seq.pop();
    cout<<n<<" ";
    for(int i=0; i<conn[n].size(); i++) {
      int next = conn[n][i];
      ind[next]--;
      if(ind[next] == 0) {
        seq.push(next);
      }
    }
  }
  cout<<"\n";
  return 0;
}
