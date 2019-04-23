/*
Name: Tho Nguyen
Email ID: tnn7yc
File name: HuffmanNode.cpp
Date: 11/26/18
*/
#include <iostream>
#include "HuffmanNode.h"

using namespace std;

HuffmanNode:: HuffmanNode(){
  c = '0';
  f = 0;
  left = NULL;
  right = NULL;
  height = 0;
  prefix = "";
}
HuffmanNode:: HuffmanNode(const char& g){
  c = g;
  f = 1;
  left = NULL;
  right = NULL;
  height = 0;
  prefix = "";
}

HuffmanNode:: ~HuffmanNode(){
  delete left;
  delete right;
  left = NULL;
  right = NULL;
}

bool HuffmanNode:: operator< (HuffmanNode* other) const{
  if ( this->f < other->f )
    return true;
  return false;
}

				   
