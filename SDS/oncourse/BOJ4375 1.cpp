#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  int N;
  while(cin>>N) {
    int cnt = 0, q = -1;
    while(q) {
      if(q<0) q=0;
      q = (q*10 + 1)%N;
      cnt++;
    }
    cout<<cnt<<"\n";
  }
  return 0;
}
