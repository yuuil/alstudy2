/*
 LIS 알고리즘을 이용해 가장 긴 부분수열의 길이를 찾으면 된다.
 Time Complexity : O(NlgN)
 최대값을 뒤에 붙여나가면서, 최대값보다 작은 경우 lower_bound를 이용해 들어갈 수 있는 자리의 값을 덮어쓴다.
 */
#include <iostream>
#include <algorithm>

using namespace std;

int N, port[40001], cache[40001];

int main() {
  cin>>N;
  for(int i=1; i<=N; i++) cin>>port[i];
  cache[1] = port[1];
  int ans = 1;
  for(int i=2; i<=N; i++) {
    if(cache[ans] < port[i]) {
      cache[++ans] = port[i];
    } else {
      int idx = lower_bound(cache, cache+ans+1, port[i]) - cache;
      cache[idx] = port[i];
    }
  }
  cout<<ans<<"\n";
  return 0;
}
