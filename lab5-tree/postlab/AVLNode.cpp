/**
Name: Tho Nguyen
Email ID: tnn7yc
File name: AVLNode.cpp
Date: 10/18/18
*/
#include "AVLNode.h"
#include <string>
using namespace std;

AVLNode::AVLNode() {
  value = "?";
  left = NULL;
  right = NULL;
  height = 0;
}

AVLNode::AVLNode(const string& x){
  value = x;
  left = NULL;
  right = NULL;
  height = 0;
}

AVLNode::~AVLNode() {
  delete left;
  delete right;
  left = NULL;
  right = NULL;
}
