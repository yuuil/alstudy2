#include <iostream>
#include <stack>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N, num;
  string cmd;
  stack<int> s;
  cin>>N;
  for(int i=0; i<N; i++) {
    cin>>cmd;
    if(cmd=="push") {
      cin>>num;
      s.push(num);
    } else if(cmd=="pop") {
      if(!s.empty()){
        cout<<s.top()<<"\n";
        s.pop();
      } else {
        cout<<-1<<"\n";
      }
    } else if(cmd=="top") {
      if(!s.empty()) {
        cout<<s.top()<<"\n";
      } else {
        cout<<-1<<"\n";
      }
    } else if(cmd=="empty") {
      cout<<s.empty()<<"\n";
    } else if(cmd=="size") {
      cout<<s.size()<<"\n";
    }
  }
  return 0;
}
