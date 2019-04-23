/**
Name: Tho Nguyen
Email ID: tnn7yc
File name: hashTable.h
Date: 10/22/18
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class hashTable{
 public:
  hashTable(unsigned int x);
  void insert(const string& x);
  bool find(const string& x);

 private:
  vector<string> table;
  int size;
  int maxQuad;
  unsigned int hash(string x, int l);
  bool checkprime(unsigned int p);
  int getNextPrime(unsigned int n);
};

#endif
