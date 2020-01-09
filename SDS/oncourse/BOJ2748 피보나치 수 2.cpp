#include <iostream>

using namespace std;

int main() {
  int n;
  long long fibo[91];
  fibo[0] = 0;
  fibo[1] = 1;
  for(int i=2; i<=90; i++) {
    fibo[i] = fibo[i-1] + fibo[i-2];
  }
  cin>>n;
  cout<<fibo[n]<<"\n";
  return 0;
}
