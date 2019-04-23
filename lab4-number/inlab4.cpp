/**
Name: Tho Nguyen
Email ID: tnn7yc
File name:inlab4.cpp
Date:9/25/18
*/

#include <string>
#include <iostream>
#include <climits>
#include <cfloat>

using namespace std;

void maxValue();

int main(){
  //Size of C++ Data Types
  maxValue();
  int iZero= 0;
  unsigned int ui= 0;
  float fZero= 0.0;
  float fOne= 1.0;
  double dZero= 0.0;
  double dOne= 1.0;
  char cZero= '0';
  char cOne= '1';
  bool bFalse= false;
  bool bTrue= true;
  int* iPointer= NULL;
  char* cPointer= NULL;
  double* dPointer= NULL;
  cout<<iZero<<endl;
  cout<<ui<<endl;
  
  //Primitive Arrays in C++
  int IntArray[10];
  char CharArray[10];

  int IntArray2D[6][5];
  char CharArray2D[6][5];

  char c= 'a';
  for (int i= 0; i<10; i++){
    IntArray[i]= i;
    CharArray[i]= c;
    //c++;
  }
  c= 'a';
  for (int i= 0; i<6; i++){
    for (int j= 0; j<5; j++){
      IntArray2D[i][j]= i*j;
      CharArray2D[i][j]= c;
      // c++;
    }
  }
  
  return 0;
}

void maxValue(){
  cout<<"int max value is "<<INT_MAX<<endl;
  cout<<"unsigned int max value is "<<UINT_MAX<<endl;
  cout<<"float max value is "<<FLT_MAX<<endl;
  cout<<"double max value is "<<DBL_MAX<<endl;
}
