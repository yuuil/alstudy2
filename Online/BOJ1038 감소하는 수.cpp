#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

int N;
vector<ll> ans;

void increasing(int n, ll sum) {
  if(n == -1) {
    ans.push_back(sum);
    return;
  }
  increasing(n-1, sum*10+n); //n을 선택하는 경우
  increasing(n-1, sum); //n을 선택하지 않는 경우
}

int main() {
  increasing(9, 0);
  cin>>N;
  sort(ans.begin(), ans.end());
  if(N >= ans.size() - 1) cout<<"-1\n";
  else cout<<ans[N+1]<<"\n"; //0은 0을 선택하는 경우와 아무것도 선택하지 않은 경우 2번 들어감
  return 0;
}
