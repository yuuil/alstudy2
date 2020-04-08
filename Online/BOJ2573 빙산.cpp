/*
매년 인접한 0의 개수만큼 빙산의 높이가 줄어든다.
빙산의 높이는 0보다 작아지지 않는다.
두 덩어리 이상으로 분리되기까지 걸리는 연 수, 모두 녹을 때까지 두 덩어리 이상 분리되지 않으면 0.
bfs를 이용한 단순 구현 문제인데 처음에 모두 녹을 때까지 두 덩어리 이상 분리되지 않으면 0 출력하는 걸 안 해서 계속 틀림^^
*/
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
bool flag,v[301][301];
int y,N,M,ice[301][301],dif[301][301],u[301][301],dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};

bool melting() {
    int cnt = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(ice[i][j] == 0) continue;
            for(int d=0; d<4; d++) {
                int nx = i + dir[d][0], ny = j + dir[d][1];
                if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if(ice[nx][ny] == 0) dif[i][j]++;
            }
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            ice[i][j] -= dif[i][j];
            if(ice[i][j] < 0) ice[i][j] = 0;
            if(ice[i][j]) cnt++;
        }
    }
    memset(dif, 0, sizeof(dif));
    return cnt > 0;
}

void bfs(int _x, int _y) {
    queue<pair<int,int> > q;
    q.push({_x,_y});
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M || ice[nx][ny] == 0 || v[nx][ny]) continue;
            v[nx][ny] = 1;
            q.push({nx,ny});
        }
    }
}

bool united() {
    int cnt = 0;
    memset(u, 0, sizeof(u));
    memset(v, 0, sizeof(v));
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(ice[i][j] && !v[i][j]) {
                if(++cnt > 1) return 0;
                v[i][j] = 1;
                bfs(i,j);
            }
        }
    }
    return 1;
}

int main() {
    cin>>N>>M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin>>ice[i][j];
        }
    }
    while(melting()) {
        y++;
        if(!united()) {
            flag = 1;
            break;
        }
    }
    cout<<(flag ? y : 0)<<"\n";
    return 0;
}