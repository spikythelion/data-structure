/*
Name: Tho Nguyen
Email ID: tnn7yc
File name: HuffmanNode.h
Date: 11/26/18
*/
#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

using namespace std;
class HuffmanNode {
public:
  HuffmanNode();
  HuffmanNode(const char& g);
  ~HuffmanNode();
  bool operator< (HuffmanNode* other) const;
private:
  char c;
  int f;
  HuffmanNode* left;
  HuffmanNode* right;
  int height;
  string prefix;
  friend class AVLTree;
  friend class Heap;
};
#endif
