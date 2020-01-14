#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N, x;
  priority_queue<int> maxh;
  priority_queue<int, vector<int>, greater<int> > minh;
  cin>>N;
  for(int i=0; i<N; i++) {
    cin>>x;
    if(maxh.size() == minh.size()) {
      minh.push(x);
    } else {
      maxh.push(x);
    }
    if(!maxh.empty()) {
      if(maxh.top() > minh.top()) {
        int maxtop = maxh.top(), mintop = minh.top();
        maxh.pop();
        minh.pop();
        minh.push(maxtop);
        maxh.push(mintop);
      }
    }
    cout<<(minh.size()>maxh.size()? minh.top() : maxh.top())<<"\n";
  }
  return 0;
}
