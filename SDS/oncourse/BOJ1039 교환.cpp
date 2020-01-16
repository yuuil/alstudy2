#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int N, K, len;
bool visited[1000001];

int bfs() {
  int ans = -1, cnt = 0;
  queue<int> q;
  q.push(N);
  visited[N] = 1;
  while(!q.empty()) {
    int s = q.size();
    memset(visited, 0, sizeof(visited));
    cnt++;
    for(int i=0; i<s; i++) {
      int node = q.front();
      string temp = to_string(node);
      q.pop();
      for(int j=0; j<len; j++) {
        for(int k=j+1; k<len; k++) {
          string bef = temp;
          if(j == 0 && temp[k] == '0') continue;
          swap(bef[j], bef[k]);
          int changed = stoi(bef);
          if(!visited[changed]) {
            visited[changed] = 1;
            q.push(changed);
            if(cnt == K) ans = max(ans, changed);
          }
        }
      }
    }
    if(cnt == K) break;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>N>>K;
  len = to_string(N).length();
  cout<<bfs()<<"\n";
  return 0;
}
