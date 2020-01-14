#include <iostream>
#include <stack>

using namespace std;

const int MAX = 1e6+1;
int N, size, n=1, num[MAX], lis[MAX];

int _lb(int start, int end, int v) {
  while(start < end) {
    int mid = (start+end)/2;
    if(lis[mid] < v) start = mid +1;
    else end = mid;
  }
  return end+1;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin>>N;
  pair<int,int> p[N];
  stack<int> s;
  for(int i=0; i<N; i++) {
    cin>>num[i];
  }
  lis[size] = num[0];
  p[0].first = 0, p[0].second = num[0];
  while(n < N) {
    if(lis[size] < num[n]) {
      lis[++size] = p[n].second = num[n];
      p[n].first = size;
    } else {
      int pos = _lb(0, size, num[n]);
      lis[pos-1] = p[n].second = num[n];
      p[n].first = pos - 1;
    }
    n++;
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
