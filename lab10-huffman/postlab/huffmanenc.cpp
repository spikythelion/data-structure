/*
Name: Tho Nguyen
Email ID: tnn7yc
File name: huffmanenc.cpp
Date: 11/26/18
*/

#include <iostream>
#include <stdlib.h>
#include "AVLTree.h"
#include "heap.h"

using namespace std;

#include <stdio.h>

int main (int argc, char **argv) {
  AVLTree* fTree = new AVLTree();
  Heap* fHeap = new Heap();
  int totalSymbol= 0, distinctSymbol= 0, oriBit, comBit;
  double ratio, cost;

  // verify the correct number of parameters
  if ( argc != 2 ) {
    cout << "Must supply the input file name as the one and only parameter" << endl;
    exit(1);
  }
  FILE *fp = fopen(argv[1], "r");
  // if the file wasn't found, output and error message and exit
  if ( fp == NULL ) {
    cout << "File '" << argv[1] << "' does not exist!" << endl;
    exit(2);
  }
  char g;
  while ( (g = fgetc(fp)) != EOF && g >= 32 && g <= 126){
    ++totalSymbol;
    if (fTree->find(g))
      fTree->incF(g);
    else{
      ++distinctSymbol;
      fTree->insert(g);
    }
  }
  fHeap->storeHeap(fTree->root);
  fHeap->buildPrefixTree();
  fHeap->setPrefixCode(fTree);
  fTree->printTree();
  cout << "------------------------------------------------" << endl;

  rewind(fp);
  while ( (g = fgetc(fp)) != EOF && (g != '\n')){
    fTree->printPrefix(g);
  }
  cout << endl;
  fclose(fp);
  cout << "------------------------------------------------" << endl;

  oriBit = totalSymbol*8;
  comBit = fTree->getComBit();
  ratio = (double)oriBit/(double)comBit;
  cost = (double)comBit/(double)totalSymbol;
  cout << "There are a total of " <<  totalSymbol << " symbols that are encoded." << endl;
  cout << "There are " << distinctSymbol << " distinct symbols used." << endl;
  cout << "There were " << oriBit << " bits in the original file." << endl;
  cout << "There were " << comBit << " bits in the compressed file." << endl;
  cout << "This gives a compression ratio of " << ratio << endl;
  cout << "The cost of the Huffman tree is " << cost << " bits per character." << endl;
  delete fTree;
  delete fHeap;
}


  
