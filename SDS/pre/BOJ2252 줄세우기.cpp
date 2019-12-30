#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> vortex[32001];
int N, M, ind[32001];
queue<int> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>N>>M;
  for(int i=0; i<M; i++) {
    int a, b;
    cin>>a>>b;
    vortex[a].push_back(b);
    ind[b]++;
  }
  for(int i=1; i<=N; i++) {
    if(ind[i] == 0) {
      q.push(i);
    }
  }
  while(!q.empty()) {
    int n = q.front();
    q.pop();
    cout<<n<<"\n";
    for(int i=0; i<vortex[n].size(); i++) {
      int next = vortex[n][i];
      ind[next]--;
      if(ind[next] == 0) {
        q.push(next);
      }
    }
  }
  return 0;
}
