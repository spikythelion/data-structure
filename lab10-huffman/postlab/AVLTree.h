/**
   Name: Tho Nguyen
   Email ID: tnn7yc
   File name: AVLTree.h
   Date: 11/26/18
*/
#ifndef AVL_H
#define AVL_H

#include <string>
#include "HuffmanNode.h"

using namespace std;

struct Trunk {
  Trunk* prev;
  string str;

  Trunk(Trunk* prev, string str) {
    this->prev = prev;
    this->str = str;
  }
};

class AVLTree {
public:
  AVLTree();
  AVLTree(HuffmanNode* r);
  ~AVLTree();
  // Declare a root node
  HuffmanNode* root;
  // insert finds a position for x in the tree and places it there, rebalancing
  // as necessary.
  void insert(const char& x);
  void printTree();
  bool find(const char& x) const;
  // numNodes returns the total number of nodes in the tree.
  int numNodes() const;
  // increment frequency of x if x exists in tree
  void incF(const char& x);
  void setPrefix(const char& x, const string& s);
  void printPrefix(const char& x);
  int getComBit();

private:
  // balance makes sure that the subtree with root n maintains the AVL tree
  // property, namely that the balance factor of n is either -1, 0, or 1.
  void balance(HuffmanNode*& n);
  // rotateLeft performs a single rotation on node n with its right child.
  HuffmanNode* rotateLeft(HuffmanNode*& n);
  // rotateRight performs a single rotation on node n with its left child.
  HuffmanNode* rotateRight(HuffmanNode*& n);
  // min finds the string with the smallest value in a subtree.
  char min(HuffmanNode* node) const;
  // height returns the value of the height field in a node. If the node is
  // null, it returns -1.
  int height(HuffmanNode* node) const;

  // private helper for printTree to allow recursion over different nodes.
  void printTree(HuffmanNode* nptr);

  // Any other methods you need...
  void insert(HuffmanNode*& n, const char& x);

  bool find(const HuffmanNode* n, const char& x) const;

  int numNodes(const HuffmanNode* n) const;

  void incF(HuffmanNode* n, const char& x);

  void setPrefix(HuffmanNode* n, const char& x, const string& s);

  void printPrefix(HuffmanNode* n, const char& x);

  int getComBit(HuffmanNode* n, int bit);
};

// max returns the greater of two integers.
int max(int a, int b);

#endif
