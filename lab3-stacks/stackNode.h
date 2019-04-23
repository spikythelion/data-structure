/**
Name: Tho Nguyen
Email ID: tnn7yc
File name:stackNode.h
Date:9/20/18
*/

#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>

using namespace std;

class stackNode{
 public:
  stackNode();
  stackNode(int n);
 private:
  int value;
  stackNode* next;
  friend class stack;
};

#endif
