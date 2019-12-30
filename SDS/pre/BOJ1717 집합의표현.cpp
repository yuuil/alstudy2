#include <iostream>

using namespace std;

int n, m;
int dis[1000001];

int parent(int x) {
  if(dis[x] == x) {
    return x;
  }
  return dis[x] = parent(dis[x]);
}

void makeJoint(int a, int b) {
  a= parent(a);
  b = parent(b);
  if(a > b) {
    dis[b] = a;
  } else if(a < b) {
    dis[a] = b;
  }
}

bool isJoint(int a, int b) {
  int pA = parent(a);
  int pB = parent(b);
  return pA == pB;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for(int i=0; i<1000001; i++) {
    dis[i] = i;
  }
  cin>>n>>m;
  for(int i=0; i<m; i++) {
    int flag, a, b;
    cin>>flag>>a>>b;
    if(flag == 1) {
      if(isJoint(a, b)) {
        cout<<"YES\n";
      } else {
        cout<<"NO\n";
      }
    } else {
      makeJoint(a, b);
    }
  }
  return 0;
}
