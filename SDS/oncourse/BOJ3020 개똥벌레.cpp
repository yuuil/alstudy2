#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N,H,l,h,cnt,lower[500001],higher[500001];
vector<int> ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin>>N>>H;
  for(int i=0; i<N/2; i++) {
    cin>>l>>h;
    lower[l]++;
    higher[h]++;
  }
  for(int i=H; i>=2; i--) {
    lower[i-1] += lower[i];
    higher[i-1] += higher[i];
  }
  for(int i=1; i<=H; i++) {
    ans.push_back(lower[i]+higher[H-i+1]);
  }
  sort(ans.begin(), ans.end());
  for(int i=0; i<H; i++) {
    if(ans[0]==ans[i]) cnt++;
  }
  cout<<ans[0]<<" "<<cnt<<"\n";
  return 0;
}
