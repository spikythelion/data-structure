#include <iostream>
/**
Name: Tho Nguyen
Email ID: tnn7yc
File name: threexinput.cpp
Date: 11/18/18
*/
#include "timer.h"
#include <cstdlib>

using namespace std;

extern "C" int threexplusone(int x);

int main(){
  int x, n;
  cout << "Enter value for x" << endl;
  cin >> x;
  cout << "Enter value for n" << endl;
  cin >> n;

  int count = 0;
  int step;
  double avg;

  timer t;
  t.start();
  while (count < n){
    step= threexplusone(x);
    ++count;
  }
  t.stop();
  avg = t.getTime()/n;
  cout << "Number of step: " <<  step << endl;
  cout << "Average time: " << avg*1000 << " miliseconds" << endl;
  
  return 0;
}
