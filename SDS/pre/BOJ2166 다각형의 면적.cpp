#include <cstdio>
#include <cmath>

using namespace std;

typedef struct _point{
  long long x, y;
}Point;

int N;
Point v[10001];

long double surface(Point& p1, Point& p2) {
  Point v1, v2;
  v1.x = p1.x - v[0].x;
  v1.y = p1.y - v[0].y;
  v2.x = p2.x - v[0].x;
  v2.y = p2.y - v[0].y;
  return (v1.x*v2.y - v2.x*v1.y);
}

int main(){
  scanf("%d", &N);
  long double sum = 0;
  for(int i=0; i<N; i++) {
    scanf("%lld %lld", &v[i].x, &v[i].y);
  }
  for(int i=1; i<N-1; i++) {
    sum += surface(v[i], v[i+1]);
  }
  sum = abs(sum);
  printf("%.1Lf\n", sum/2);
  return 0;
}
