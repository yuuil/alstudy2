#include <iostream>
#include <cstring>

using namespace std;

bool flag, visited[51][51], finished[51][51];
int N,M,ans,board[51][51],dp[51][51];
char in;
int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

int play(int x, int y) {
  visited[x][y] = 1;
  int score = board[x][y];
  int &ret = dp[x][y];
  ret = 1;
  for(int i=0; i<4; i++) {
    int nx = x + dir[i][0]*score, ny = y + dir[i][1]*score;
    if(nx < 0 || nx >=N || ny < 0 || ny >=M || board[nx][ny] == -1) continue;
    if(visited[nx][ny]) {
      if(finished[nx][ny]) ret = max(ret, dp[nx][ny] + 1);
      else flag = 1;
    }
    else ret = max(ret, play(nx,ny)+1);
  }
  finished[x][y] = 1;
  return ret;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin>>N>>M;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      cin>>in;
      if(in == 'H') board[i][j] = -1;
      else board[i][j] = in - '0';
    }
  }
  memset(dp, -1, sizeof(dp));
  ans = play(0,0);
  if(flag) cout<<-1<<"\n";
  else cout<<ans<<"\n";
  return 0;
}
