/**
Name: Tho Nguyen
Email ID: tnn7yc
File name: AVLPathTest.cpp
Date: 10/18/18
*/

#include "AVLTree.h"

#include <iostream>
using namespace std;

int main() {
  AVLTree avl;
  while (cin.good()) {
    string instr, word;
    cin >> instr;
    cin >> word;
    if (instr == "I") {
      avl.insert(word);
    } else if (instr == "R") {
      avl.remove(word);
    } else if (instr == "L") {
      cout << "AVL path: " << avl.pathTo(word) << endl;
      }
  }
  cout << "AVL numNodes: " << avl.numNodes() << endl;
}
