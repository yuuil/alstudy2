#include <iostream>

using namespace std;

int cnt = 1, l, r, N, step[100002], dp[5][5][100001];

int score(int from, int to) {
  if(!from) return 2;
  else return (from%2 == to%2) ? 4 : 3;
}

int move(int from, int to, int s) {
  if(step[s] == 0) return 0;
  int &ret = dp[from][to][s];
  if(ret) return ret;
  if(to == step[s] || from == step[s]) {
    ret = move(from, to, s+1) + 1;
  } else {
    ret = score(from, step[s]) + move(step[s], to, s+1);
    ret = min(ret, score(to, step[s]) + move(from, step[s], s+1));
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  while(cin>>step[cnt], step[cnt++]) {}
  cnt--;
  cout<<move(0,0,1)<<"\n";
  return 0;
}
