/**
Name: Tho Nguyen
Email ID: tnn7yc
File name: stackNode.cpp
Date:9/20/18
*/

#include <iostream>
#include "stackNode.h"

using namespace std;

stackNode::stackNode(){
  value= 0;
  next= NULL;
}

stackNode::stackNode(int n){
  value= n;
  next= NULL;
}
