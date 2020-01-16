#include <iostream>
#include <algorithm>

using namespace std;

int L,C, flag;
char code[16];

void solve(int bits, int idx, int cnt) {
  if(cnt == L) {
    int v = 0, c = 0;
    string temp;
    for(int i=0; i<C; i++) {
      if(bits & (1<<i)) {
        if(code[i] == 'a' || code[i] == 'e' || code[i] == 'i' || code[i] == 'o' || code[i] == 'u') v++;
        else c++;
        temp += code[i];
      }
    }
    if(v && c>=2) cout<<temp<<"\n";
    return;
  }
  for(int i=idx; i<C; i++) {
    solve(bits|(1<<i), i+1, cnt+1);
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin>>L>>C;
  for(int i=0; i<C; i++) cin>>code[i];
  sort(code, code+C);
  solve(0, 0, 0);
  return 0;
}
