#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#define LIM 1e9
using namespace std;
typedef long long ll;
int N, num;
string cmd;
vector<int> save;
vector<string> q;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  while(cin>>cmd) {
    if(cmd == "QUIT") break;
    if(cmd == "END") {
      cin>>N;
      for(int i=0; i<N; i++) {
        cin>>num;
        stack<int> s;
        int idx = 0;
        s.push(num);
        bool err = 0;
        for(int i=0; i<q.size(); i++) {
          if(q[i] == "NUM") {
            int temp = save[idx++];
            s.push(temp);
          } else {
            if(s.empty()) {
              err = 1;
              break;
            }
            if(q[i] == "POP") s.pop();
            else if(q[i] == "INV") {
              int top = s.top();
              s.pop();
              s.push(-top);
            } else if(q[i] == "DUP") s.push(s.top());
            else {
              if(s.size() < 2) {
                err = 1;
                break;
              }
              int first = s.top();
              s.pop();
              int second = s.top();
              s.pop();
              if(q[i] == "SWP") {
                s.push(first);
                s.push(second);
              } else if(q[i] == "ADD") {
                if(abs(first+second) > LIM) {
                  err = 1;
                  break;
                }
                s.push(first+second);
              } else if(q[i] == "MUL") {
                if(abs((ll)first*second) > LIM) {
                  err = 1;
                  break;
                }
                s.push(first*second);
              } else if(q[i] == "SUB") {
                if(abs(second - first) > LIM) {
                  err = 1;
                  break;
                }
                s.push(second-first);
              } else if(q[i] == "DIV") {
                if(first == 0 || abs(second/first) > LIM) {
                  err = 1;
                  break;
                }
                s.push(second/first);
              } else if(q[i] == "MOD") {
                if(first == 0 || abs(second%first) > LIM) {
                  err = 1;
                  break;
                }
                s.push(abs(second%first)*(second < 0 ? -1 : 1));
              }
            }
          }
        }
        if(err || s.size() != 1) cout<<"ERROR\n";
        else cout<<s.top()<<"\n";
      }
      cout<<"\n";
      save.clear();
      q.clear();
    } else {
      q.push_back(cmd);
      if(cmd == "NUM") {
        cin>>num;
        save.push_back(num);
      }
    }
  }
  return 0;
}
