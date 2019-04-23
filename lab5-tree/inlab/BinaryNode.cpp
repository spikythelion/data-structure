/**
Name: Tho Nguyen
Email ID: tnn7yc
File name:BinaryNode.cpp
Date:10/16/18
*/
#include "BinaryNode.h"
#include <string>
using namespace std;

BinaryNode::BinaryNode() {
  value = "?";
  left = NULL;
  right = NULL;
}

BinaryNode::BinaryNode(const string& x){
  value = x;
  left = NULL;
  right = NULL;
}

BinaryNode::~BinaryNode() {
  delete left;
  delete right;
  left = NULL;
  right = NULL;
}
