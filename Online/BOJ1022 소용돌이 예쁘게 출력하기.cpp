#include <iostream>
#include <iomanip>

using namespace std;

int r1, r2, c1, c2, m = 0, digit = 1, s[51][5];

int value(int r, int c) {
  int n = max(abs(r), abs(c)),
  edge = (2*n+1) * (2*n+1);
  if(r == n) return edge - (n-c);
  else if(c == -n) return edge - (2*n) - (n-r);
  else if(r == -n) return edge - (4*n) - (n+c);
  else return edge - (6*n) - (n+r);
}

int main() {
  cin>>r1>>c1>>r2>>c2;
  int r = r2 - r1 + 1, c = c2 - c1 + 1;
  for(int i=0; i<r; i++) {
    for(int j=0; j<c; j++) {
      s[i][j] = value(r1 + i, c1 + j);
      m = max(m, s[i][j]);
    }
  }
  while(m /= 10) digit++;
  for(int i=0; i<r; i++) {
    for(int j=0; j<c; j++) {
      cout<<setw(digit)<<s[i][j]<<" ";
    }
    cout<<"\n";
  }
  return 0;
}
