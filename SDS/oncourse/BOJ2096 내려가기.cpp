#include <iostream>

using namespace std;

int n, pan[100001][3], mins[2][3], maxs[2][3];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>pan[i][0]>>pan[i][1]>>pan[i][2];
  }
  mins[0][0] = maxs[0][0] = pan[0][0];
  mins[0][1] = maxs[0][1] = pan[0][1];
  mins[0][2] = maxs[0][2] = pan[0][2];
  for(int i=1; i<n; i++) {
    mins[1][0]=min(mins[0][0], mins[0][1]);
    mins[1][1]=min(min(mins[0][0],mins[0][1]),mins[0][2]);
    mins[1][2]=min(mins[0][1], mins[0][2]);
    mins[0][0]=pan[i][0]+mins[1][0];
    mins[0][1]=pan[i][1]+mins[1][1];
    mins[0][2]=pan[i][2]+mins[1][2];
    maxs[1][0]=max(maxs[0][0], maxs[0][1]);
    maxs[1][1]=max(max(maxs[0][0],maxs[0][1]),maxs[0][2]);
    maxs[1][2]=max(maxs[0][1], maxs[0][2]);
    maxs[0][0]=pan[i][0]+maxs[1][0];
    maxs[0][1]=pan[i][1]+maxs[1][1];
    maxs[0][2]=pan[i][2]+maxs[1][2];
  }
  cout<<max(max(maxs[0][0], maxs[0][1]), maxs[0][2])<<" ";
  cout<<min(min(mins[0][0], mins[0][1]), mins[0][2])<<"\n";
  return 0;
}
