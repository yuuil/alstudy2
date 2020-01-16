#include <iostream>

using namespace std;

int N, K, ans;
string word[51];

void solve(int idx, int flag, int cnt) {
  if(cnt > K) return;
  if(cnt == K) {
    int temp = 0;
    for(int i=0; i<N; i++) {
      bool poss = 1;
      for(int j=4; j<word[i].length()-4; j++) {
        if(!(flag & (1<<word[i][j]-'a'))) {
          poss = 0;
          break;
        }
      }
      if(poss) temp++;
    }
    ans = max(ans, temp);
    return;
  }
  for(int i=idx; i<26; i++) {
    if(!(flag & (1<<i))) solve(i, flag|(1<<i), cnt+1);
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin>>N>>K;
  for(int i=0; i<N; i++) cin>>word[i];
  int flag = 0;
  flag |= 1<<('a'-'a') | 1<<('c'-'a') | 1<<('i'-'a') | 1<<('n'-'a') | 1<<('t'-'a');
  solve(0, flag, 5);
  cout<<ans<<"\n";
  return 0;
}
