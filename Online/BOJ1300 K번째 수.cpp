#include <iostream>

using namespace std;
typedef long long ll;

int main() {
  int N, K;
  cin>>N>>K;
  
  int l = 1, r = K;
  while(l <= r) {
    ll cnt = 0;
    int mid = (l + r) / 2;
    for(int i=1; i<=N; i++) cnt += min(mid/i, N);
    if(cnt < K) l = mid + 1;
    else r = mid - 1;
  }
  /*
   cnt == K 라면 r = mid - 1
   while문은 l = r = mid 가 될 때까지 반복하게 되는데
   l == r 이면서 cnt == K인 경우 r = mid - 1이 되어 l > r 로 반복문이 종료
   따라서 l이 답임을 알 수 있다.
   */
  cout<<l<<"\n";
  return 0;
}
