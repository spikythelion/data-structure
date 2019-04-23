#include <iostream>
#include "HuffmanNode.h"

int main(){
  HuffmanNode* n1= new HuffmanNode();
  HuffmanNode* n2= new HuffmanNode('a');
  HuffmanNode* n3= new HuffmanNode('c');

  bool cmp = n2 < n3;

  cout << cmp;
  return 0;
}
