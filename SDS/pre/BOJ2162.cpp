#include <iostream>

using namespace std;

typedef struct _point{
  int x, y;
}P;

typedef struct _line{
  P start, end;
}Line;

int main(){
  int N;
  cin>>N;
  Line l[N];
  for(int i=0; i<N; i++) {
    cin>>l[i].start.x>>l[i].start.y>>l[i].end.x>>l[i].end.y;
  }
  return 0;
}
