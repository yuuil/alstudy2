/*
  처음에 문제를 잘못 이해해서 포함이 되면 안 되는 줄 알았다.
  접두어만 아니면 되기 때문에 사전순으로 정렬.
  인접한 두 문자열 중 뒤의 문자열이 앞의 문자열로 시작하는지 판별하면 된다.
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool flag;
int t,n;
string tel[10001];
int main() {
  ios::sync_with_stdio(0),cin.tie(0);
  cin>>t;
  while(t--) {
    cin>>n;
    flag=0;
    for(int i=0; i<n; i++) cin>>tel[i];
    sort(tel,tel+n);
    for(int i=1;i<n; i++){
      if(tel[i-1][0]==tel[i][0]) {
        if(tel[i-1]==tel[i].substr(0,tel[i-1].size())) {
          flag=1;
          break;
        }
      }
    }
    cout<<(flag?"NO":"YES")<<"\n";
  }
  return 0;
}