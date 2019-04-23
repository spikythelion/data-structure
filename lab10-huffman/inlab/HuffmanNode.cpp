/*
Name: Tho Nguyen
Email ID: tnn7yc
File name: HuffmanNode.cpp
Date: 11/27/18
*/
#include <iostream>
#include "HuffmanNode.h"

using namespace std;

HuffmanNode:: HuffmanNode(){
  c = "NULL";
  left = NULL;
  right = NULL;
  prefix = "";
}
HuffmanNode:: HuffmanNode(const string& g, const string& p){
  c = g;
  left = NULL;
  right = NULL;
  prefix = p;
}

HuffmanNode:: ~HuffmanNode(){
  delete left;
  delete right;
  left = NULL;
  right = NULL;
}


				   
