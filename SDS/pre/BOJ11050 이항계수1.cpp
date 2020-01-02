#include <iostream>

using namespace std;

int fact[11];

int main() {
  fact[0] = fact[1] = 1;
  for(int i=2; i<=10; i++) {
    fact[i] = fact[i-1] * i;
  }
  int N, K;
  cin>>N>>K;
  cout<<fact[N]/fact[K]/fact[N-K]<<"\n";
  return 0;
}
