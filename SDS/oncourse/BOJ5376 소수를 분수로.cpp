#include <iostream>
#include <string>

typedef long long ll;
using namespace std;

bool flag;
int t;
string num;
ll ent, iter,l,n;

ll gcd(ll a, ll b) {
  if(!b) return a;
  return gcd(b, a%b);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  for(int i=0; i<t; i++) {
    flag = 0;
    ent = iter = 0;
    l=n=1;
    cin>>num;
    num = num.substr(2);
    for(int j=0; j<num.length(); j++) {
      if(!flag) {
        if(num[j]=='(' || num[j]==')') flag = 1;
        else {
          ent = ent*10 + num[j]-'0';
          iter = iter*10 + num[j]-'0';
          l*=10, n*=10;
        }
      } else {
        if(num[j]!='(' && num[j]!=')') {
          ent = ent*10 + num[j]-'0';
          l*=10;
        }
      }
    }
    if(l!=n) {
      ll g = gcd(ent-iter, l-n);
      cout<<(ent-iter)/g<<"/"<<(l-n)/g<<"\n";
    } else {
      ll g = gcd(ent, l);
      cout<<ent/g<<"/"<<l/g<<"\n";
    }
  }
  return 0;
}
