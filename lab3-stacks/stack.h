/**
Name: Tho Nguyen
Email ID: tnn7yc
File name:stack.h
Date:9/20/18
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "stackNode.h"

using namespace std;

class stack{
 public:
  stack();
  void push(int n);
  void pop();
  int top();
  bool empty();

 private:
  stackNode* head;
  int size;
};

#endif
