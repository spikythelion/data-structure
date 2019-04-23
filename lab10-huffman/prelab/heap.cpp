/*
Name: Tho Nguyen
Email ID: tnn7yc
File name: heap.cpp
Date: 11/26/18
*/
#include <iostream>
#include "heap.h"
#include "AVLTree.h"

using namespace std;

Heap:: Heap(){
  heap.push_back(NULL);
  heap_size= 0;
}

Heap:: ~Heap(){
}

void Heap:: insert(HuffmanNode* nptr){
  // a vector push_back will resize as necessary
  heap.push_back(nptr);
  // move it up into the right position
  percolateUp(++heap_size);
}

void Heap::storeHeap(HuffmanNode* nptr){
  if (nptr != NULL){
    HuffmanNode* tmp= new HuffmanNode();
    tmp->c = nptr->c;
    tmp->f = nptr->f;
    insert(tmp);
    storeHeap(nptr->left);
    storeHeap(nptr->right);
  }
}

HuffmanNode* Heap:: deleteMin(){
  // make sure the heap is not empty
  if ( heap_size == 0 )
    throw "deleteMin() called on empty heap";
  // save the value to be returned
  HuffmanNode* ret = heap[1];
  // move the last inserted position into the root
  heap[1] = heap[heap_size--];
  // make sure the vector knows that there is one less 
  // element
  heap.pop_back();
  // percolate the root down to the proper position
  percolateDown(1);
  // return the old root node
  return ret;
}
  
void Heap::printHeap(){
  cout << "heap_size: " << heap_size << endl;
  for (int i=1; i<=heap_size; ++i){
    cout << heap[i]->c << ", " << heap[i]->f << endl;
  }
}

void Heap::buildPrefixTree(){
  while (heap_size > 1){
    HuffmanNode* t = new HuffmanNode();
    t->left = deleteMin();
    t->right = deleteMin();
    t->f = t->left->f + t->right->f;
    insert(t);
  }
}

void Heap::setPrefixCode(AVLTree* fTree){
  setPrefixCode(heap[1], "", fTree);
}

void Heap::setPrefixCode(HuffmanNode* nptr, string code, AVLTree* fTree){
  if (nptr->left != NULL){
    string c = code + "0";
    setPrefixCode(nptr->left, c, fTree);
  }

  if (nptr->right != NULL){
    string c = code + "1";
    setPrefixCode(nptr->right, c, fTree);
  }
  else if (nptr->left == NULL && nptr->right == NULL){
    nptr->prefix = code;
    fTree->setPrefix(nptr->c, nptr->prefix);
  }
}

void Heap:: percolateUp(int hole){
  // get the value just inserted
  HuffmanNode* x = heap[hole];
  // while we haven't run off the top and while the 
  // value is less than the parent...
  for ( ; (hole > 1) && (x->operator<(heap[hole/2])); hole /= 2 )
    heap[hole] = heap[hole/2]; // move parent down
  // correct position found!  insert at that spot
  heap[hole] = x;
}

void Heap:: percolateDown(int hole){
  // get the value to percolate down
  HuffmanNode* x = heap[hole];
  // while there is a left child...
  while ( hole*2 <= heap_size ) {
    int child = hole*2; // the left child
    // is there a right child?  if so, is it lesser?
    if ( (child+1 <= heap_size) && (heap[child+1]->operator<(heap[child])) )
      child++;
    // if the child is greater than the node...
    if ( heap[child]->operator<(x) ) {
      heap[hole] = heap[child]; // move child up
      hole = child;             // move hole down
    } else
      break;
  }
  // correct position found!  insert at that spot
  heap[hole] = x;
}
