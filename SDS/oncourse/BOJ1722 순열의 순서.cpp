#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;

bool visited[21];
int N, cmd, num, seq[21];
ll k, accum, fact[21];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  fact[0] = fact[1] = 1;
  for(int i=2; i<21; i++) {
    fact[i] = fact[i-1]*i;
  }
  cin>>N>>cmd;
  if(cmd == 1) {
    cin>>k;
    for(int i=1; i<=N; i++) {
      for(int j=1; j<=N; j++) {
        if(visited[j]) continue;
        if(k>fact[N-i]) {
          k-=fact[N-i];
        }
        else {
          cout<<j<<" ";
          visited[j]=1;
          break;
        }
      }
    }
  } else {
    for(int i=1; i<=N; i++) {
      cin>>num;
      visited[num]=1;
      for(int j=1; j<num; j++) {
        if(!visited[j]) accum += fact[N-i];
      }
    }
    cout<<accum+1<<"\n";
  }
  return 0;
}
