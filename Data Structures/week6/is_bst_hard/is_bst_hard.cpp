#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
#define INTMAX 2147483647
#define INTMIN -2147483648

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool isBSTUtil(const vector<Node>& tree,long val,long minval,long maxval){
	if (val==-1)return true;
	Node x=tree[val];
	if (x.key==INTMIN && x.left!=-1)return false;
	if (x.key<minval || x.key>maxval)return false;
	if (isBSTUtil(tree,x.left,minval,x.key-1) && isBSTUtil(tree,x.right,x.key,maxval))return true;
	else return false;
	
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
  if (tree.size()==0)return true;
  if (isBSTUtil(tree,0,INTMIN,INTMAX))return true;
  else return false;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree) ){
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
