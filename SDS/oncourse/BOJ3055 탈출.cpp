#include <iostream>
#include <queue>

using namespace std;

string map[51];
int r,c, ans;
bool flag, visited[51][51];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
queue<pair<int, int> > q, water;
pair<int, int> d;

void waterful() {
  int s = water.size();
  while(s--) {
    int x = water.front().first, y = water.front().second;
    water.pop();
    for(int i=0; i<4; i++) {
      int nx = x + dir[i][0], ny = y + dir[i][1];
      if(nx < 0 || nx >= r || ny < 0 || ny >= c || map[nx][ny] == '*' || map[nx][ny] == 'X' || map[nx][ny] == 'D') {
        continue;
      }
      map[nx][ny] = '*';
      water.push(make_pair(nx, ny));
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>r>>c;
  for(int i=0; i<r; i++) {
    cin>>map[i];
    for(int j=0; j<c; j++) {
      if(map[i][j] == 'S') {
        visited[i][j] = 1;
        q.push(make_pair(i, j));
      } else if(map[i][j] == 'D') {
        d = make_pair(i, j);
      } else if(map[i][j] == '*') {
        water.push(make_pair(i, j));
      }
    }
  }
  while(!q.empty()) {
    waterful();
    int s = q.size();
    while(s--) {
      int x = q.front().first, y = q.front().second;
      q.pop();
      if(x == d.first && y == d.second) {
        flag = 1;
        break;
      }
      for(int i=0; i<4; i++) {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c || map[nx][ny] == '*' || map[nx][ny] == 'X' || visited[nx][ny]) {
          continue;
        }
        visited[nx][ny] = 1;
        q.push(make_pair(nx, ny));
      }
    }
    if(flag) break;
    ans++;
  }
  if(flag) {
    cout<<ans<<"\n";
  } else {
    cout<<"KAKTUS\n";
  }
  return 0;
}
