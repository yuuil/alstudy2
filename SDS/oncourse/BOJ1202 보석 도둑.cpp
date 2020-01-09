#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N,K,m,v,c;
  long long sum=0;
  priority_queue<pair<int,int> > gem;
  multiset<int> bag;
  cin>>N>>K;
  for(int i=0; i<N; i++) {
    cin>>m>>v;
    gem.push(make_pair(v,m));
  }
  for(int i=0; i<K; i++) {
    cin>>c;
    bag.insert(c);
  }
  while(!gem.empty()) {
    pair<int,int> top = gem.top();
    gem.pop();
    auto it = bag.lower_bound(top.second);
    if(it != bag.end()) {
      sum += top.first;
      bag.erase(it);
    }
  }
  cout<<sum<<"\n";
  return 0;
}
