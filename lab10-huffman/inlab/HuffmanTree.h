/*
Name: Tho Nguyen
Email ID: tnn7yc
File name: HuffmanTree.h
Date: 11/27/18
*/
#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <iostream>
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

class HuffmanTree{
 public:
  HuffmanNode* root;
  HuffmanTree();
  ~HuffmanTree();
  void createNode(const string& c, const string& p);
  void decode(const string& bits);
 private:
  void createNode(HuffmanNode* &n, const string& c, const string& curP, const string& p);
  void decode(HuffmanNode* n, const string& bits);
  void showTrunks(Trunk* p);
  void printTree(HuffmanNode* n, Trunk* prev, bool isLeft);
};

#endif
