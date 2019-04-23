#include <iostream>
#include <fstream>
#include <string>
/**
Name: Tho Nguyen
Email ID: tnn7yc
File name: wordPuzzle.cpp
Date: 10/22/18

Big theta of word search is  BigTheta(r*c*w) with r is number of rows of grid, c is number of columns in grid and w is number of words in the dictionary. dir refers to direction and len refers to the word being search's legnth can be dropped since it a rather small known constant
*/
#include <stdlib.h>
#include "hashTable.h"
#include "timer.h"

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

unsigned int getSize(string filename);
void readInWords(string filename, hashTable& ht);
void readInGrid(string filename, int& rows, int& cols);
char* getWordInGrid(int startRow, int startCol, int dir, int len, int numRows, int numCols);
void printOutput(int dir, int r, int c, const string& x);

int main(int agrc, char* argv[]){
  timer t;
  if (agrc < 3){//check if 2 files are inputted
    cout << "Invalid input file received" << endl;
    exit(1);
  }
  string dictFile= argv[1];
  hashTable ht(getSize(dictFile));//get number of words in dictionary file and staticly allocate a hash table
  readInWords(dictFile, ht);//read in and insert word into table
 
  int rows, cols;
  int wordFound= 0;
  string gridFile= argv[2];
  readInGrid(gridFile, rows, cols);//assume gridFile valid, read in cols, rows and construct grid
  t.start();
  for (int r= 0; r < rows; r++){//row
    for (int c= 0; c < cols; c++){//col
      for (int dir= 0; dir < 8; dir++){//direction
	for (int len= 3; len < 23; len++){
	  string word(getWordInGrid(r, c, dir, len, rows, cols));
	  if (word.length() < len){
	    break;
	  }
	  if (ht.find(word)){
	    ++wordFound;
	    printOutput(dir, r, c, word);
	  }
	}
      }
    }
  }
  cout << wordFound << " words found" << endl;
  t.stop();
  cout << "Found all words in " << t << endl;
  int time= t.getTime()*1000;
  cout << time << endl;
  return 0;
}

unsigned int getSize(string filename){
  unsigned int wordCount= 0;
  string line;
  ifstream file(filename.c_str());
  if(file.is_open()){
    while( getline(file, line))
      ++wordCount;
    file.close();
  }
  return wordCount;
}
  
void readInWords(string filename, hashTable& ht){
  string line;
  ifstream file (filename.c_str());
  if (file.is_open())
  {
    while ( getline (file,line) )
    {
      ht.insert(line);
    }
    file.close();
  }
}

void readInGrid(string filename, int& rows, int& cols){
  string line;
  ifstream file(filename.c_str());
  if (!file.is_open())
    exit(1);
  file >> rows;
  getline(file, line);
  file >> cols;
  getline(file, line);
  getline(file, line);
  file.close();
  int pos = 0; // the current position in the input data
  for ( int r = 0; r < rows; r++ ) {
    for ( int c = 0; c < cols; c++ ) {
      grid[r][c] = line[pos++];
    }
  }
}

char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols) {
    static char output[22];
    // make sure the length is not greater than the array size.
    if ( len >= 23 )
        len = 22;
    // the position in the output array, the current row, and the
    // current column
    int pos = 0, r = startRow, c = startCol;
    // iterate once for each character in the output
    for ( int i = 0; i < len; i++ ) {
        // if the current row or column is out of bounds, then break
      if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) )
            break;
        // set the next character in the output array to the next letter
        // in the grid
        output[pos++] = grid[r][c];
        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
	    case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    output[pos] = 0;
    return output;
}

void printOutput (int dir, int r, int c, const string& x){
  switch (dir){
  case 0:
    cout << "N (" << r << ", " << c << "):     " << x << endl;
    break;
  case 1:
    cout << "NE(" << r << ", " << c << "):     " << x << endl;
    break;
  case 2:
    cout << "E (" << r << ", " << c << "):     " << x << endl;
    break;
  case 3:
    cout << "SE(" << r << ", " << c << "):     " << x << endl;
    break;
  case 4:
    cout << "S (" << r << ", " << c << "):     " << x << endl;
    break;
  case 5:
    cout << "SW(" << r << ", " << c << "):     " << x << endl;
    break;
  case 6:
    cout << "W (" << r << ", " << c << "):     " << x << endl;
    break;
  case 7:
    cout << "NW(" << r << ", " << c << "):     " << x << endl;
    break;
  }
}

