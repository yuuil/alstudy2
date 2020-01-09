#include <iostream>

using namespace std;

long long sum[10001];

int main() {
  int N, cnt = 0;
  long long M;
  cin>>N>>M;
  for(int i=1; i<=N; i++) {
    cin>>sum[i];
    sum[i] += sum[i-1];
    if(sum[i]==M) cnt++;
  }
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=i-1; j++) {
      if(sum[i]-sum[j] == M) {
        cnt++;
      }
    }
  }
  cout<<cnt<<"\n";
  return 0;
}
