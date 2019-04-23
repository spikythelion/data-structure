/**
Name: Tho Nguyen
Email ID: tnn7yc
File name: hashTable.cpp
Date: 10/22/18
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include "hashTable.h"


using namespace std;

hashTable::hashTable(unsigned int x){
  size= getNextPrime(x*5);
  table.resize(size);
  maxQuad= 0;
}

void hashTable::insert(const string& x){
  unsigned int h= hash(x, x.length());
  unsigned int index= h % size;
  if (table[index] == ""){
    table[index]= x;
  }
  else{
    int count= 1;
    while(table[index] != ""){//opening address with quadratic probing
      index= h % size + pow(count, 2);
      index= index % size;
      ++count;
    }
    if (count > maxQuad)
      maxQuad= count;
    table[index]= x;
  }
}

bool hashTable::find (const string& x){
  unsigned int h= hash(x, x.length());
  unsigned int index= h % size;
  if (table[index] == x){
    return true;
  }
  int count= 1;
  while(count <= maxQuad){
    index= h % size + pow(count, 2);
    index= index % size;
    if (table[index] == x)
      return true;
    ++count;
  }
  return false;
}
  
unsigned int hashTable::hash(string x, int l){
  unsigned int h= 0;
  for (int i= 0; i<l ; ++i){
     h+= x[i] * pow(19, i);
  }
  return h;
}

bool hashTable::checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}


  
