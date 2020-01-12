#include <iostream>
#include <queue>

using namespace std;

int N, b, ind[501], t[501], res[501];
vector<int> v[501];

int main() {
  cin>>N;
  queue<int> q;
  for(int i=1; i<=N; i++) {
    cin>>t[i];
    while(cin>>b) {
      if(b == -1) break;
      v[b].push_back(i);
      ind[i]++;
    }
  }
  for(int i=1; i<=N; i++) {
    if(ind[i] == 0) q.push(i);
    res[i] = t[i];
  }
  while(!q.empty()) {
    int n = q.front();
    q.pop();
    for(int i=0; i<v[n].size(); i++) {
      int next = v[n][i];
      res[next] = max(res[next], res[n]+t[next]);
      if(--ind[next] == 0) {
        q.push(next);
      }
    }
  }
  for(int i=1; i<=N; i++) {
    cout<<res[i]<<"\n";
  }
  return 0;
}
