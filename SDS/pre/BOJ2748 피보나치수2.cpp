#include <iostream>

using namespace std;

long long fibo[91];

int main() {
  int N;
  
  fibo[1] = 1;
  for(int i=2; i<=90; i++) {
    fibo[i] = fibo[i-1] + fibo[i-2];
  }
  cin>>N;
  cout<<fibo[N]<<"\n";

  return 0;
}
