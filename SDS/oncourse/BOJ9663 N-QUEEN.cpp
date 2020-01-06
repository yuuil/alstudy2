#include <iostream>

using namespace std;

int N, ans;
int chess[16];

bool possible(int curr) {
  for(int i=1; i<curr; i++) {
    if(chess[i] == chess[curr]) return 0;
    else if(abs(chess[i] - chess[curr]) == abs(i-curr)) return 0;
  }
  return 1;
}

void search(int curr) {
  if(curr == N) {
    ans++;
    return;
  }
  for(int i=1; i<=N; i++) {
    chess[curr+1] = i;
    if(possible(curr+1)) search(curr+1);
  }
}

int main(){
  cin>>N;
  search(0);
  cout<<ans<<"\n";
  return 0;
}
