/**
   Name: Tho Nguyen
   Email ID: tnn7yc
   File name: AVLTree.cpp
   Date: 11/26/18
*/
#include "AVLTree.h"
#include <string>
#include <iostream>
#include "HuffmanNode.h"
using namespace std;

AVLTree::AVLTree() { root = NULL; }

AVLTree::AVLTree(HuffmanNode* r){
  root = r;
}

AVLTree::~AVLTree() {
  delete root;
  root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const char& x) {
  // YOUR IMPLEMENTATION GOES HERe
  insert(root, x);
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const char& x) const {
  // YOUR IMPLEMENTATION GOES HERE
  return find(root, x);
}

void AVLTree::incF(const char& x){
  incF(root, x);
}

void AVLTree::incF(HuffmanNode* n, const char& x){
  if (x < n->c)
    incF(n->left, x);
  else if (x > n->c)
    incF(n->right, x);
  else
    ++n->f;
}

void AVLTree::setPrefix(const char& x, const string& s){
  setPrefix(root, x, s);
}

void AVLTree::setPrefix(HuffmanNode* n, const char& x, const string& s){
  if (x < n->c)
    setPrefix(n->left, x, s);
  else if (x > n->c)
    setPrefix(n->right, x, s);
  else
    n->prefix = s;
}

void AVLTree::printPrefix(const char& x){
  printPrefix(root, x);
}

void AVLTree::printPrefix(HuffmanNode* n, const char& x){
  if (x < n->c)
    printPrefix(n->left, x);
  else if (x > n->c)
    printPrefix(n->right, x);
  else
    cout << n->prefix << " ";
}

int AVLTree::getComBit(){
  return getComBit(root, 0);
}

int AVLTree::getComBit(HuffmanNode* n, int bit){
  if (n != NULL){
    bit += (n->prefix.length() * n->f);
    if (n->left != NULL)
      bit = getComBit(n->left, bit);
    if (n->right != NULL)
      bit = getComBit(n->right, bit);
  }
  return bit;
  
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
  // YOUR IMPLEMENTATION GOES HERE
  return numNodes(root);
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(HuffmanNode*& n) {
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
HuffmanNode* AVLTree::rotateLeft(HuffmanNode*& n) {
  // YOUR IMPLEMENTATION GOES HERE
  HuffmanNode* temp= n->right;
  n->right = temp->left;
  temp->left = n;
  n->height = 1 + max(height(n->left), height(n->right));
  return temp;
}

// rotateRight performs a single rotation on node n with its left child.
HuffmanNode* AVLTree::rotateRight(HuffmanNode*& n) {
  // YOUR IMPLEMENTATION GOES HERE
  HuffmanNode* temp= n->left;
  n->left= temp->right;
  temp->right= n;
  n->height = 1 + max(height(n->left), height(n->right));
  return temp;
}

// min finds the string with the smallest value in a subtree.
char AVLTree::min(HuffmanNode* node) const {
  // go to bottom-left node
  if (node->left == NULL) {
    return node->c;
  }
  return min(node->left);
}

// height returns the value of the height field in a node. If the node is
// null, it returns -1.
int AVLTree::height(HuffmanNode* node) const {
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
void AVLTree::printTree(HuffmanNode* nptr) {
  if ( nptr->left != NULL )
    printTree(nptr->left);
  if ( nptr->c == ' ' )
    cout << "space" << "  " << nptr->prefix << endl;
  else
    cout << nptr->c << "  " << nptr->prefix << endl;
  if ( nptr->right != NULL )
    printTree(nptr->right);
}

void AVLTree::printTree() { printTree(root); }

void AVLTree::insert(HuffmanNode*& n, const char& x){
  if (n==NULL)
    n= new HuffmanNode(x);
  else if (x < n->c){
    insert(n->left, x);
  }
  else if (x > n->c){
    insert(n->right, x);
  }
  else
    ;
  n->height = 1 + max(height(n->left), height(n->right));
  balance(n);
}

bool AVLTree::find(const HuffmanNode* n, const char& x) const{
  if (n==NULL)
    return false;
  else if (x < n->c)
    return find(n->left, x);
  else if (x > n->c)
    return find(n->right, x);
  else
    return true;
}

int AVLTree::numNodes(const HuffmanNode* n) const{
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
