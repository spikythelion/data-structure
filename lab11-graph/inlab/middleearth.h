/**
Name: Tho Nguyen
Email ID: tnn7yc
File name: middleearth.h
Date: 12/4/18
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>

#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

/*!\namespace std
 */
using namespace std;

/*!\class MiddleEarth
 * \brief Create a random 2-dimensional world.
 *
 * It will pick a given number of cities (or places), and randomly place them in the "world"
 * You can travel from any city to any other city, for a given cost (the distance).
 */

class MiddleEarth {
    private:
  /*!\var int num_city_names
     \brief Number of city names
     \var int xsize
     \brief Number of row in the 2D distance array
     \var int ysize
     \brief Number of column in the 2D distance array
  */
  int num_city_names, xsize, ysize;
  /*!\var vector<float> xpos
     \brief Array of floats that holds city's x coordinate
     \var vector<float> ypos
     \brief Array of floats that holds city's y coordinate
   */
  vector<float> xpos, ypos;
  /*!\var vector<string> cities
     \brief Array of strings that holds all cities' name
   */
  vector<string> cities;
  /*!\var float* distances
     \brief Array of floats that holds distance from one city (r) to other (c)
  */
  float *distances;
  /*!\var map<string, int> indices
     \brief Hash table that holds all cities name
  */
  map<string, int> indices;

    public:
  /*!\fn MiddleEarth (int xsize, int ysize, int numcities, int seed);Constructor
     \brief MakeEarth constructor: Allocate MakeEarth object and assigns values to object fields
  */
  MiddleEarth (int xsize, int ysize, int numcities, int seed);
  /*!\fn ~MiddleEarth();
     \brief MakeEarth destructor: Deallocate MakeEarth object and object fields
  */
  ~MiddleEarth();
  /*!\fn print()
     \brief Prints out info of created world
  */
  void print();
  /*!\fn printTable()
     \brief Prints a tab-separated table of the distances
  */
  void printTable();
  /*!\fn getDistance (string city1, string city2)
     \brief Returns the distance between the two passed cities.
     *If we assume that the hash table (i.e. the map) is O(1), then this
     *method call is also O(1)
     \return The distance between city1 and city2
     \param city1 The first city
     \param city2 The second city
  */
  float getDistance (string city1, string city2);
  /*!\fn getItinerary(unsigned int length)
     \brief Returns the list of cities to travel to
     *The first city is the original start point as well as the end point.  
     *The number of cities passed in does not include this start/end point 
     *(so there will be length+1 entries in the returned vector).
     \return The list of cities to travel to.
     \param length Number of cities to travel to (does not include start/end point)
  */
  vector<string> getItinerary(unsigned int length);
};

#endif
