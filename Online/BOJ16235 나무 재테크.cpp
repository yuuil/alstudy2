#include <iostream>
#include <deque>
#define dq deque<int>

using namespace std;
int ans,x,y,z,N,M,K,A[11][11],feed[11][11],dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
dq tree[11][11],dead[11][11];

void spring() {
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      int l = tree[i][j].size();
      for(int k=0; k<l; k++) {
        int y = tree[i][j].front();
        tree[i][j].pop_front();
        if(feed[i][j] >= y) {
          feed[i][j] -= y;
          tree[i][j].push_back(y+1);
        } else dead[i][j].push_back(y);
      }
    }
  }
}

void summer() {
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      while(!dead[i][j].empty()) {
        int y = dead[i][j].front();
        dead[i][j].pop_front();
        feed[i][j] += y/2;
      }
    }
  }
}

void autumn() {
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      int l = tree[i][j].size();
      for(int k=0; k<l; k++) {
        if(!(tree[i][j][k]%5)) {
          for(int d=0; d<8; d++) {
            int nx = i+dir[d][0], ny = j+dir[d][1];
            if(nx<1 || nx>N || ny<1 || ny>N) continue;
            tree[nx][ny].push_front(1);
          }
        }
      }
    }
  }
}

void winter() {
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      feed[i][j] += A[i][j];
    }
  }
}


int main() {
  cin>>N>>M>>K;
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      cin>>A[i][j];
      feed[i][j] = 5;
    }
  }
  for(int i=0; i<M; i++) {
    cin>>x>>y>>z;
    tree[x][y].push_back(z);
  }
  while(K--) {
    spring();
    summer();
    autumn();
    winter();
  }
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      ans += tree[i][j].size();
    }
  }
  cout<<ans<<"\n";
  return 0;
}