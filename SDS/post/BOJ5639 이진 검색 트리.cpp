#include <iostream>
using namespace std;
typedef struct _node {
  int val;
  _node* l = NULL;
  _node* r = NULL;
}Node;
void make_tree(Node *node, int x) {
  Node *ret;
  Node *newNode = new Node;
  newNode->val = x;
  while(node) {
    ret = node;
    if(node->val > x) {
      if(node->l) node = node->l;
      else break;
    } else {
      if(node->r) node = node->r;
      else break;
    }
  }
  if(ret->val > x) ret->l = newNode;
  else ret->r = newNode;
}
void search(Node* node) {
  if(!node) return;
  search(node->l);
  search(node->r);
  cout<<node->val<<"\n";
}
int main() {
  int w;
  Node *root = new Node;
  cin>>w;
  root->val = w;
  while(cin>>w) {
    make_tree(root, w);
  }
  search(root);
  return 0;
}