#include <iostream>
using namespace std;

int N;
char tree[27][2];

void preorder(int n) {
  cout<<char(n+'A');
  for(int i=0; i<2; i++) {
    if(tree[n][i] != '.') {
      preorder(tree[n][i]-'A');
    }
  }
}

void inorder(int n) {
  if(tree[n][0] != '.') {
    inorder(tree[n][0]-'A');
  }
  cout<<char(n+'A');
  if(tree[n][1] != '.') {
    inorder(tree[n][1]-'A');
  }
}

void postorder(int n) {
  for(int i=0; i<2; i++) {
    if(tree[n][i] != '.') {
      postorder(tree[n][i]-'A');
    }
  }
  cout<<char(n+'A');
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>N;
  char key;
  for(int i=0; i<N; i++) {
    cin>>key;
    cin>>tree[key-'A'][0]>>tree[key-'A'][1];
  }
  preorder(0);
  cout<<"\n";
  inorder(0);
  cout<<"\n";
  postorder(0);
  cout<<"\n";
  return 0;
}
