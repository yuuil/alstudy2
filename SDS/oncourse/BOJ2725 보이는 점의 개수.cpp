#include <iostream>

using namespace std;

int gcd(int a, int b) {
  return b ? gcd(b, a%b) : a;
}

int C,N, cnt;
long long arr[1001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  arr[1] = 3;
  for(int i=2; i<=1000; i++) {
    cnt = 0;
    for(int j=1; j<=i; j++) {
      if(gcd(i,j)==1) cnt++;
    }
    arr[i] = arr[i-1] + cnt*2;
  }
  cin>>C;
  for(int i=0; i<C; i++) {
    cin>>N;
    cout<<arr[N]<<"\n";
  }
  return 0;
}
