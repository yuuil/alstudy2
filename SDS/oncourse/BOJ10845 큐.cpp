#include <iostream>
#include <queue>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N, num;
  string cmd;
  queue<int> q;
  cin>>N;
  for(int i=0; i<N; i++) {
    cin>>cmd;
    if(cmd=="push") {
      cin>>num;
      q.push(num);
    } else if(cmd=="pop") {
      if(!q.empty()) {
        cout<<q.front()<<"\n";
        q.pop();
      } else {
        cout<<-1<<"\n";
      }
    } else if(cmd=="empty") {
      cout<<q.empty()<<"\n";
    } else if(cmd=="size") {
      cout<<q.size()<<"\n";
    } else if(cmd=="front") {
      if(!q.empty()) {
        cout<<q.front()<<"\n";
      } else {
        cout<<-1<<"\n";
      }
    } else if(cmd=="back") {
      if(!q.empty()) {
        cout<<q.back()<<"\n";
      } else {
        cout<<-1<<"\n";
      }
    }
  }
  return 0;
}
