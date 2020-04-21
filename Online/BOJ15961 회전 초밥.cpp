/*
  처음에 덱 대신에 dp[MAX] 배열을 선언했다가 TLE => cin.tie(0)으로 sync 끊으면 AC
  0부터 길이만큼 일단 서로 다른 초밥의 종류를 카운팅.
  l, r을 이동하면서 l-1을 뺐을 때 해당 초밥 카운트가 0이면 종류 -1
  r을 추가했을 때 해당 초밥 카운트가 1이면 종류 + 1
  회전해야 하므로 r++한 다음 %N 해준다.
  l이 마지막 초밥이 될 때까지 반복.
*/
#include <iostream>
using namespace std;
const int MAX=3e6+1;
int cnt,l,r,N,d,k,c,sushi[MAX],kind[3001];
int main() {
  cin>>N>>d>>k>>c;
  for(int i=0; i<N; i++) cin>>sushi[i];
  for(;r<k;r++) {
    if(kind[sushi[r]]++ < 1) cnt++;
  }
  int ans=cnt;
  for(l=1;l<N;l++) {
    if(--kind[sushi[l-1]]==0) cnt--;
    if(kind[sushi[r++]]++ < 1) cnt++;
    r%=N;
    if(kind[c]==0) ans=max(ans,cnt+1);
    else ans=max(ans,cnt);
  }
  cout<<ans<<"\n";
  return 0;
}