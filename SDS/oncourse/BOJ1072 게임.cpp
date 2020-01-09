#include <iostream>

using namespace std;

int main() {
  int l=0, r=1000000000;
  long long x,y;
  cin>>x>>y;
  int z = y*100/x;
  if(z>=99) {
    cout<<"-1\n";
  } else {
    while(l<=r) {
      int mid = (l+r)/2;
      if((y+mid)*100/(x+mid) > z) {
        r=mid-1;
      } else {
        l=mid+1;
      }
    }
    cout<<l<<"\n";
  }
  return 0;
}
