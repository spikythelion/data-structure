/**
Name: Tho Nguyen
Email ID: tnn7yc
File name: mathfun.cpp
Date: 11/5/18
*/

#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" int product(int, int);
extern "C" int power(int, int);

int main(){
  int x, y, prod, pow;
  
  cout << "Enter value for x: ";
  cin >> x;
  cout << "Enter value for y: ";
  cin >> y;

  prod = product(x, y);
  cout << "Product is " << prod << endl;
  
  pow = power(x, y);
  cout << "Power is " << pow << endl;
  
  return 0;
}
