/**
Name: Tho Nguyen
Email ID: tnn7yc
File name:postfixCalculator.h
Date:9/20/18
*/

#include <iostream>
#include "stack.h"

using namespace std;

class PostfixCalculator{
 public:
  PostfixCalculator();
  void pushNum(int n);
  void add();
  void subtract();
  void multiply();
  void divide();
  void unaryNeg();
  int getTopValue();
  void readString(string& str);
 private:
  stack* s;
  void removeTopValue();
};
