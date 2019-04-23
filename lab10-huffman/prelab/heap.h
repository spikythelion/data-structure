/*
Name: Tho Nguyen
Email ID: tnn7yc
File name: heap.h
Date: 11/26/18
*/
#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "HuffmanNode.h"
#include "AVLTree.h"

using namespace std;
class Heap {
 public:
  Heap();
  ~Heap();
  void insert(HuffmanNode* nptr);
  void storeHeap(HuffmanNode* nptr);
  HuffmanNode* deleteMin();
  void printHeap();
  void buildPrefixTree();
  void setPrefixCode(AVLTree* fTree);
private:
  vector<HuffmanNode*> heap;
  int heap_size;
  void percolateUp(int hole);
  void percolateDown(int hole);
  void setPrefixCode(HuffmanNode* nptr, string code, AVLTree* fTree);
  friend class Heap;
};
#endif
