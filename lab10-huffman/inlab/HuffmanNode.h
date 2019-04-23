/*
Name: Tho Nguyen
Email ID: tnn7yc
File name: HuffmanNode.h
Date: 11/27/18
*/
#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

using namespace std;
class HuffmanNode {
public:
  HuffmanNode();
  HuffmanNode(const string& g, const string& p);
  ~HuffmanNode();
private:
  string c;
  HuffmanNode* left;
  HuffmanNode* right;
  string prefix;
  friend class HuffmanTree;
};
#endif
