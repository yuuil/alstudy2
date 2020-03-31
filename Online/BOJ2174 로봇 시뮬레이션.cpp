#include <iostream>
#include <string>

using namespace std;
enum D {
  N = 0,W,S,E, //방향 배열의 인덱스
  R = -1,F,L //방향 회전을 위한 값
};
bool flag = 0;
int A,B,n,m,dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
pair<int,int> robot[101],land[101][101];
string ans;

//enum에 저장된 값 리턴
int value(char c) {
  if(c == 'N') return N;
  if(c == 'W') return W;
  if(c == 'S') return S;
  if(c == 'E') return E;
  if(c == 'R') return R;
  if(c == 'F') return F;
  if(c == 'L') return L;
}

//충돌 생길 때 ans에 저장할 문자열
string crash_wall(int x) {return "Robot "+to_string(x)+" crashes into the wall";}
string crash_robot(int x, int y) {return "Robot "+to_string(x)+" crashes into robot "+to_string(y);}

int main() {
  cin>>A>>B>>n>>m;
  for(int i=1; i<=n; i++) {
    int x, y;
    char d;
    cin>>x>>y>>d;
    int val = value(d);
    land[x][y] = {i,val};
    robot[i] = {x,y};
  }
  for(int i=1; i<=m; i++) {
    int num, it;
    char cmd;
    cin>>num>>cmd>>it;
    int x = robot[num].first, y = robot[num].second;
    if(flag) continue;
    if(cmd == 'F')  {
      int idx = land[x][y].second;
      for(int j=1; j<=it; j++) {
        if(flag) break; //충돌 생기면 flag = true;
        int nx = x + dir[idx][0], ny = y + dir[idx][1];
        if(nx < 1 || nx > A || ny < 1 || ny > B) {
          ans = crash_wall(num);
          flag = 1;
        }
        else if(land[nx][ny].first > 0) {
          ans = crash_robot(num, land[nx][ny].first);
          flag = 1;
        } else {
          land[nx][ny] = land[x][y];
          land[x][y] = {0, 0};
          robot[num] = {nx,ny};
          x = nx, y = ny;
        }
      }
    } else {
      land[x][y].second += value(cmd) * it + 4;
      while(land[x][y].second < 0) land[x][y].second += 4;
      land[x][y].second %= 4;
    }
  }
  cout<<(flag ? ans : "OK")<<"\n";
  return 0;
}
