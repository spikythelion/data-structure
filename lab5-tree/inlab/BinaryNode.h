/**
Name: Tho Nguyen
Email ID: tnn7yc
File name: BinaryNode.h
Date: 10/16/18
*/
#ifndef BINARYNODE_H
#define BINARYNODE_H
#include <string>
using namespace std;

class BinaryNode {
  BinaryNode();
  BinaryNode(const string& x);
  ~BinaryNode();

  string value;
  BinaryNode* left;
  BinaryNode* right;

  friend class BinarySearchTree;
};

#endif
