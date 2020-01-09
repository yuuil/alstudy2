#include <iostream>

using namespace std;

int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a%b);
}

int main() {
  int d1, d2, n1,n2;
  cin>>d1>>n1>>d2>>n2;
  int mul = d1*n2+d2*n1, n = gcd(mul, n1*n2);
  cout<<mul/n<<" "<<(n1*n2)/n<<"\n";
  return 0;
}
