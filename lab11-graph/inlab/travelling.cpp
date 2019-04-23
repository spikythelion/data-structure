/**
Name: Tho Nguyen
Email ID: tnn7yc
File name: travelling.cpp
Date: 12/4/18
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cfloat>
//\namespace std
using namespace std;
//\file middleearth.h
#include "middleearth.h"

float computeDistance (MiddleEarth &me, string start, vector<string> dests);
void printRoute (string start, vector<string> dests);

/*!\fn main  (int argc, char **argv)
 *\brief Main function
 * Scans command line inputs, creates a world for computation and calls computeDistance
 *\return 0 when program done
 *\param argc Number of elements in the command line input array
 *\param argv Array of string from command line input
 */
int main (int argc, char **argv) {
  // check the number of parameters
  if ( argc != 6 ) {
    cout << "Usage: " << argv[0] << " <world_height> <world_width> "
	 << "<num_cities> <random_seed> <cities_to_visit>" << endl;
    exit(0);
  }
  // we'll assume the parameters are all well-formed
  int width, height, num_cities, rand_seed, cities_to_visit;
  sscanf (argv[1], "%d", &width);
  sscanf (argv[2], "%d", &height);
  sscanf (argv[3], "%d", &num_cities);
  sscanf (argv[4], "%d", &rand_seed);
  sscanf (argv[5], "%d", &cities_to_visit);
  // Create the world, and select your itinerary
  MiddleEarth me(width, height, num_cities, rand_seed);
  vector<string> dests = me.getItinerary(cities_to_visit);
  // YOUR CODE HERE
  string start = dests[0];
  computeDistance (me, start, dests);
  return 0;
}
/*!\fn computeDistance (MiddleEarth &me, string start, vector<string> dests)
 *
 * This method will compute the full distance of the cycle that starts
 * at the 'start' parameter, goes to each of the cities in the dests
 * vector IN ORDER, and ends back at the 'start' parameter.
 *\return The shortest distance from start city to seleted number of other cities and go back to start
 *\param me The world where cities are located
 *\param start The starting (home) city
 *\param dests List of destination cities
 */
float computeDistance (MiddleEarth &me, string start, vector<string> dests) {
  dests.erase(dests.begin());
  float minDistance = FLT_MAX;
  float distance = 0;
  vector<string> min;
  sort(dests.begin(), dests.end());
  do {
    distance = distance + me.getDistance(start, dests[0]) + me.getDistance(start, dests[dests.size()-1]);
    for (int i = 0; i < dests.size() - 1; i++){
      distance += me.getDistance(dests[i], dests[i+1]);
    }
    if (distance < minDistance){
      minDistance = distance;
      min = dests;
    }
    distance = 0;
  } while (next_permutation(dests.begin(), dests.end()));
  cout << "Minimum path has distance " << minDistance << ": ";
  printRoute (start, min);
  return minDistance;
}

/*!\fn printRoute (strig start, vector<string> dests)
 *
 * This method will print the entire route, starting and ending at the
 * 'start' parameter.  The output should be of the form:
 * Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
 *\param start The starting (home) city
 *\param dests List of destination cities
 */

void printRoute (string start, vector<string> dests) {
  // YOUR CODE HERE
  cout << start << " -> ";
  for (int i= 0; i < dests.size(); i++){
    if (i == dests.size() -1)
      cout << dests[i];
    else
      cout << dests[i] << " -> ";
  }
  cout << " -> " << start << endl;;
}
