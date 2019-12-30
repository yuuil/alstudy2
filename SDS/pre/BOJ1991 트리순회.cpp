#include <iostream>
#include <map>

using namespace std;

typedef struct _node {
  char lc;
  char rc;
}Node;

map<char, Node> bt;

void preorder(char key) {
    if(key == '.') {
      return;
    }
    cout<<key;
    preorder(bt[key].lc);
    preorder(bt[key].rc);
}

void inorder(char key) {
  if(key == '.') {
    return;
  }
  inorder(bt[key].lc);
  cout<<key;
  inorder(bt[key].rc);
}

void postorder(char key) {
  if(key == '.') {
    return;
  }
  postorder(bt[key].lc);
  postorder(bt[key].rc);
  cout<<key;
}

int main() {
  int N;
  char root, head;
  cin>>N;
  for(int i=0; i<N; i++) {
    Node newNode;
    cin>>root;
    if(i == 0) {
      head = root;
    }
    cin>>newNode.lc>>newNode.rc;
    bt[root] = newNode;
  }
  
  preorder(head);
  cout<<"\n";
  inorder(head);
  cout<<"\n";
  postorder(head);
  cout<<"\n";
  
  return 0;
}
