#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int seq[1000001], lis[1000001];

int _lb(int start, int end, int target) {
  int mid;
  while(end > start) {
    mid = (start + end) / 2;
    if(lis[mid] < target) {
      start = mid + 1;
    } else {
      end = mid;
    }
  }
  return end + 1;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N, size = 0, next = 1;
  cin>>N;
  pair<int, int> p[N];
  stack<int> s;
  for(int i=0; i<N; i++) {
    cin>>seq[i];
  }
  lis[size] = seq[0];
  p[0].first = 0;
  p[0].second = seq[0];
  while(next < N) {
    if(lis[size] < seq[next]) {
      lis[++size] = p[next].second = seq[next];
      p[next].first = size;
    } else {
      int pos = _lb(0, size, seq[next]);
      lis[pos - 1] = p[next].second = seq[next];
      p[next].first = pos - 1;
    }
    next++;
  }
  cout<<size+1<<"\n";
  for(int i=N-1; i>=0; i--) {
    if(p[i].first == size) {
      s.push(p[i].second);
      size--;
    }
  }
  while(!s.empty()) {
    cout<<s.top()<<" ";
    s.pop();
  }
  cout<<"\n";
  return 0;
}
