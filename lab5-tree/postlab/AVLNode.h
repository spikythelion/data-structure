/**
Name: Tho Nguyen
Email ID: tnn7yc
File name: AVLNode.h
Date: 10/18/18
*/
#ifndef AVLNODE_H
#define AVLNODE_H
#include <string>
using namespace std;

class AVLNode {
  AVLNode();
  AVLNode(const string& x);
  ~AVLNode();

  string value;
  AVLNode* left;
  AVLNode* right;
  int height;
  friend class AVLTree;
};

#endif
