#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,t,reco,s[101];
vector<int> v;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin>>N>>t;
  for(int i=0; i<t; i++) {
    cin>>reco;
    s[reco]++;
    auto it = find(v.begin(), v.end(), reco);
    if(it != v.end()) continue;
    if(v.size() < N) v.push_back(reco);
    else {
      int idx = v[0], pos = 0;
      for(int i=0; i<N; i++) {
        if(s[idx] > s[v[i]]) {
          idx = v[i];
          pos = i;
        }
      }
      s[idx] = 0;
      v.erase(pos+v.begin());
      v.push_back(reco);
    }
  }
  sort(v.begin(), v.end());
  for(int i=0; i<N; i++) cout<<v[i]<<" ";
  cout<<"\n";
  return 0;
}
