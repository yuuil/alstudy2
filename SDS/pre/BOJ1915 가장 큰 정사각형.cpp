#include <cstdio>
#include <algorithm>

using namespace std;

int d[1001][1001];

int main() {
  int N, M, temp, s = 0;
  scanf("%d %d", &N, &M);
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=M; j++) {
      scanf("%1d", &temp);
      if(temp) {
        d[i][j] = min(min(d[i-1][j], d[i][j-1]), d[i-1][j-1]) + 1;
        s = max(s, d[i][j]);
      }
    }
  }
  printf("%d\n", s*s);
  return 0;
}
