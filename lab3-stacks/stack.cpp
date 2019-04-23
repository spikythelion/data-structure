/**
Name: Tho Nguyen
Email ID: tnn7yc
File name:stack.cpp
Date:9/20/18
*/

#include <iostream>
#include "stack.h"

using namespace std;

stack::stack(){
  head= NULL;
  size= 0;
}

void stack::push(int n){
  stackNode* sn= new stackNode(n);
  if (empty())
    head= sn;
  else{
    sn->next= head;
    head= sn;
  }
  ++size;
}

void stack::pop(){
  stackNode* temp= head->next;
  delete head;
  head= temp;
  --size;
}

int stack::top(){
  return head->value;
}

bool stack::empty(){
  if (size== 0)
    return true;
  return false;
}
  
    
