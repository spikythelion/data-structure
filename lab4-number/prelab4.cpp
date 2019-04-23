/**
Name: Tho Nguyen
Email ID: tnn7yc
File name:prelab4.cpp
Date: 9/24/18
*/

#include <iostream>
#include <string>
#include <climits>

using namespace std;

void sizeOfTest();
void outputBinary(unsigned int i);
void overflow();

int main(){
  sizeOfTest();
  cout<<endl;
  unsigned int x;
  cout<<"Enter a number: "<<endl;
  cin>>x;
  outputBinary(x);
  cout<<endl;
  overflow();
  return 0;
}
void sizeOfTest(){
  cout<<"sizeof() int is: "<<sizeof(int)<<endl;
  cout<<"sizeof() unsigned int is: "<<sizeof(unsigned int)<<endl;
  cout<<"sizeof() float  is: "<<sizeof(float)<<endl;
  cout<<"sizeof() double is: "<<sizeof(double)<<endl;
  cout<<"sizeof() char is: "<<sizeof(char)<<endl;
  cout<<"sizeof() bool is: "<<sizeof(bool)<<endl;
  cout<<"sizeof() int* is: "<<sizeof(int*)<<endl;
  cout<<"sizeof() char* is: "<<sizeof(char*)<<endl;
  cout<<"sizeof() double* is: "<<sizeof(double*)<<endl;
    
}

void outputBinary(unsigned int x){
  string output= "";
  for (int i= 0; i<32; i++){
    if (x%2==1)
      output= to_string(1)+output;
    else
      output= to_string(0)+output;
    x=x>>1;
  }
  
  int count= 0;
  for (int i= 1; i<=39; i++){
    if ((i-count)%4==0){
      output.insert(i, " ");
      ++count;
      ++i;
    }
  }
  cout<<"Result in binary: "<<output<<endl;
}

void overflow(){
  unsigned int max= UINT_MAX;
  cout<<"unsigned int max is "<<max<<endl;
  ++max;
  cout<<"unsigned int max plus 1 is "<<max<<endl;
  cout<<"This happens because the binary representation for unsigned max is 32 1s. When 1 is added to this number, 1 is added to the right most value of its binary representation. Since right most value is already 1, it becomes 0 and 1 is overflow to the digit next to it to the left. This value is also 1 and becomes 0. It keeps overflows like that till the left most value turn to 0. Now the result is 32 0s, which is the binary representation for 0"<<endl;
}
  
