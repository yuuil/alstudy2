#include <iostream>
#include <deque>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  deque<pair<int,int> > dq;
  int N,L,num;
  cin>>N>>L;
  for(int i=0; i<N; i++) {
    cin>>num;
    while(!dq.empty()) {
      if(num <= dq.back().first) {
        dq.pop_back();
      } else break;
    }
    dq.push_back(make_pair(num, i));
    if(dq.front().second < i-L+1) dq.pop_front();
    cout<<dq.front().first<<" ";
  }
  cout<<"\n";
  return 0;
}
