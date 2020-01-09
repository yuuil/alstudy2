#include <iostream>
#include <algorithm>

using namespace std;

int N, sum, score = 9;
int alpha[26];
string word[10];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>N;
  for(int i=0; i<N; i++) {
    cin>>word[i];
    int base = 1;
    for(int j=word[i].length()-1; j>=0; j--) {
      alpha[word[i][j]-'A'] += base;
      base *= 10;
    }
  }
  sort(alpha, alpha+26);
  for(int i=25; i>=0; i--) {
    if(alpha[i]) {
      sum += alpha[i] * score--;
    }
  }
  cout<<sum<<"\n";
  return 0;
}
