#include <iostream>

using namespace std;

int gcd(int a, int b) {
  if(b == 0) {
    return a;
  }
  return gcd(b, a%b);
}

int main() {
  int ox, oy, tx, ty;
  cin>>ox>>oy>>tx>>ty;
  int numer = ox * ty + tx * oy;
  int denom = oy * ty;
  int fraction = gcd(numer, denom);
  cout<<numer/fraction<<" "<<denom/fraction<<"\n";
  return 0;
}
