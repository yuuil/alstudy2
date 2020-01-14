#include <iostream>

using namespace std;

int N, stair[301], score[301];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin>>N;
  for(int i=1; i<=N; i++) {
    cin>>stair[i];
  }
  score[1] = stair[1];
  score[2] = score[1] + stair[2];
  score[3] = max(stair[2]+stair[3], score[1]+stair[3]);
  for(int i=4; i<=N; i++) {
    score[i] = max(score[i-3]+stair[i-1]+stair[i], score[i-2]+stair[i]);
  }
  cout<<score[N]<<"\n";
  return 0;
}
