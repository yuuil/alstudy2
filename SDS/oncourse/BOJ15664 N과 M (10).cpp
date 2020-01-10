#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[9];
int N,M, comb[9], num[9], a, b;
vector<vector<int> > set;

bool compV(vector<int> &seq) {
  bool flag = 0;
  if(set.empty()) return 0;
  for(int i=0; i<set.size(); i++) {
    for(int j=0; j<seq.size(); j++) {
      if(seq[j] != set[i][j]) break;;
      if(j == seq.size()-1 && seq[j]==set[i][j]) return 1;
    }
  }
  return 0;
}

void select(int depth, int idx) {
  bool chk[9];
  int temp[9];
  for(int i=0; i<M; i++) {
    temp[i] = comb[i];
  }
  for(int i=0; i<9; i++) {
    chk[i] = visited[i];
  }
  if(depth == M) {
    vector<int> seq;
    for(int i=0; i<M; i++) {
      seq.push_back(comb[i]);
    }
    if(!compV(seq)) set.push_back(seq);
    memset(visited, 0, sizeof(visited));
    return;
  }
  for(int i=idx; i<N; i++) {
    if(!visited[i]) {
      comb[depth] = num[i];
      visited[i]=1;
      select(depth+1, i+1);
      for(int j=0; j<M; j++) {
        comb[j] = temp[j];
      }
      for(int j=0; j<9; j++) {
        visited[j] = chk[j];
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin>>N>>M;
  for(int i=0; i<N; i++) {
    cin>>num[i];
  }
  sort(num, num+N);
  select(0, 0);
  for(int i=0; i<set.size(); i++) {
    for(int j=0; j<set[i].size(); j++) {
      cout<<set[i][j]<<" ";
    }
    cout<<"\n";
  }
  return 0;
}
