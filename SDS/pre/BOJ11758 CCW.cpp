#include <iostream>

using namespace std;

typedef struct _point{
  int x, y;
}Point;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  Point p1, p2, p3;
  cin>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y;
  Point v1, v2;
  v1.x = p2.x - p1.x;
  v1.y = p2.y - p1.y;
  v2.x = p3.x - p1.x;
  v2.y = p3.y - p1.y;
  if(v1.x*v2.y - v2.x*v1.y == 0) {
    cout<<"0\n";
  } else if(v1.x*v2.y - v2.x*v1.y > 0) {
    cout<<"1\n";
  } else {
    cout<<"-1\n";
  }
  return 0;
}
