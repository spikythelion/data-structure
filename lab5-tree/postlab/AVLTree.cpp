/**
Name: Tho Nguyen
Email ID: tnn7yc
File name: AVLTree.cpp
Date: 10/18/18
*/
#include "AVLTree.h"
#include <string>
#include <iostream>
#include "AVLNode.h"
using namespace std;

AVLTree::AVLTree() { root = NULL; }

AVLTree::~AVLTree() {
  delete root;
  root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
  // YOUR IMPLEMENTATION GOES HERe
  insert(root, x);
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) { root = remove(root, x); }

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
  // YOUR IMPLEMENTATION GOES HERE
  if (!find(x))
    return "";
  else
    return pathTo(root, x);
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
  // YOUR IMPLEMENTATION GOES HERE
  return find(root, x);
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
  // YOUR IMPLEMENTATION GOES HERE
  return numNodes(root);
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
  //yoUR IMPLEMENTATION GOES HERE
  if (height(n->right) - height(n->left) == -2){
    if (height(n->left->right) - height(n->left->left) == -1){//case 1: left of left child of n
      n= rotateRight(n);
    }
    
    else if (height(n->left->right) - height(n->left->left) == 1){//case 2: right of left child of n
      n->left= rotateLeft(n->left);
      n->left->height = 1 + max(height(n->left->right), height(n->left->left));
      n= rotateRight(n);
    }
    else if (height(n->left->right) - height(n->left->left) == 0){
      n= rotateRight(n);
    }
  }
  
  else if (height(n->right) - height(n->left) == 2){
    if (height(n->right->right) - height(n->right->left) == -1){// case 3: left of right child of n
      n->right= rotateRight(n->right);
      n->right->height= 1 + max(height(n->right->left), height(n->right->left));
      n= rotateLeft(n);
    }
    
    else if (height(n->right->right) - height(n->right->left) == 1){//case 4: right of right child of n
      n= rotateLeft(n);
    }
    else if (height(n->left->right) - height(n->left->left) == 0){
      n= rotateLeft(n);
    }
  }
  n->height = 1 + max(height(n->left), height(n->right));
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
  // YOUR IMPLEMENTATION GOES HERE
  AVLNode* temp= n->right;
  n->right = temp->left;
  temp->left = n;
  n->height = 1 + max(height(n->left), height(n->right));
  return temp;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
  // YOUR IMPLEMENTATION GOES HERE
  AVLNode* temp= n->left;
  n->left= temp->right;
  temp->right= n;
  n->height = 1 + max(height(n->left), height(n->right));
  return temp;
}

// private helper for remove to allow recursion over different nodes. returns
// an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
  if (n == NULL) {
    return NULL;
  }
  // first look for x
  if (x == n->value) {
    // found
    // no children
    if (n->left == NULL && n->right == NULL) {
      delete n;
      n = NULL;
      return NULL;
    }
    // single child
    if (n->left == NULL) {
      AVLNode* temp = n->right;
      n->right = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    if (n->right == NULL) {
      AVLNode* temp = n->left;
      n->left = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    // two children -- tree may become unbalanced after deleting n
    string sr = min(n->right);
    n->value = sr;
    n->right = remove(n->right, sr);
  } else if (x < n->value) {
    n->left = remove(n->left, x);
  } else {
    n->right = remove(n->right, x);
  }
  n->height = 1 + max(height(n->left), height(n->right));
  balance(n);
  return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
  // go to bottom-left node
  if (node->left == NULL) {
    return node->value;
  }
  return min(node->left);
}

// height returns the value of the height field in a node. If the node is
// null, it returns -1.
int AVLTree::height(AVLNode* node) const {
  if (node == NULL) {
    return -1;
  }
  return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

// Helper function to print branches of the binary tree
void showTrunks(Trunk* p) {
  if (p == NULL) return;
  showTrunks(p->prev);
  cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isLeft) {
  if (root == NULL) return;

  string prev_str = "    ";
  Trunk* trunk = new Trunk(prev, prev_str);

  printTree(root->left, trunk, true);

  if (!prev)
    trunk->str = "---";
  else if (isLeft) {
    trunk->str = ".---";
    prev_str = "   |";
  } else {
    trunk->str = "`---";
    prev->str = prev_str;
  }

  showTrunks(trunk);
  cout << root->value << endl;

  if (prev) prev->str = prev_str;
  trunk->str = "   |";

  printTree(root->right, trunk, false);
}

void AVLTree::printTree() { printTree(root, NULL, false); }

void AVLTree::insert(AVLNode*& n, const string& x){
  if (n==NULL)
    n= new AVLNode(x);
  else if (x < n->value){
    insert(n->left, x);
  }
  else if (x > n->value){
    insert(n->right, x);
  }
  else
    ;
  n->height = 1 + max(height(n->left), height(n->right));
  balance(n);
}

bool AVLTree::find(const AVLNode* n, const string& x) const{
   if (n==NULL)
    return false;
  else if (x < n->value)
    return find(n->left, x);
  else if (x > n->value)
    return find(n->right, x);
  else
    return true;
}

string AVLTree::pathTo(const AVLNode* n, const string& x) const{
  string s= "";
  if (n->value==x)
    s= n->value;
  else if (x < n->value)
    s= n->value + " " + pathTo(n->left, x);
  else if (x > n->value)
    s= n->value + " " + pathTo(n->right, x);
  return s;
}

int AVLTree::numNodes(const AVLNode* n) const{
  int count= 0;
  if (n->left==NULL && n->right==NULL)
    return ++count;
  else{
    if (n->left!=NULL){
      count+= numNodes(n->left);
    }
    if (n->right!=NULL){
      count+= numNodes(n->right);
    }
  }
  return ++count;
}  
