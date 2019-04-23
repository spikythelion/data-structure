/**
Name: Tho Nguyen
Email ID: tnn7yc
File name:testPostfixCalc.cpp
Date:9/20/18
*/


#include <iostream>
#include "postfixCalculator.h"

using namespace std;

int main(){
  PostfixCalculator p;
  /*
  p.pushNum(200);
  p.pushNum(4);
  p.pushNum(-6);
  p.pushNum(8);
  p.pushNum(10);
  cout<<"top value after push "<< p.getTopValue()<<endl;

  p.add();
  cout<<"top value after add "<<p.getTopValue()<<endl;

  p.subtract();
  cout<<"top value after substract "<<p.getTopValue()<<endl;

  p.multiply();
  cout<<"top value after multiphy "<<p.getTopValue()<<endl;

  p.divide();
  cout<<"top value after divide "<<p.getTopValue()<<endl;

  p.unaryNeg();
  cout<<"Result is: "<<p.getTopValue()<<endl;
  */
  
   string s;
    while (cin >> s) {
      p.readString(s);
    }
    cout<<"Result is: "<<p.getTopValue()<<endl;
    
  return 0;
}
