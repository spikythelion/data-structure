/**
Name: Tho Nguyen
Email ID: tnn7yc
File name: topological.cpp
Date: 12/3/18
*/
// included so we can use cout
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <queue>

/*!\namespace std
 */
using namespace std;
/*!\class Vertex
 * \brief Vertex (or node) of a graph
 *
 * Vertex object contains constructors, fields of a vertex.
 */
class Vertex{
public:
  /*!\fn Vertex()
   * \brief Constructor: Allocate a vertex object
   */
  Vertex();
   /*!\fn Vertex(string s)
   * \brief Constructor: Allocate a vertex object and assign name = s
   * \param s Name for vertex being created.
   */
  Vertex(string s);
  /*!\var string name
   *\brief name of the vertex
   */
  string name;
   /*!\var int indegree
    * \brief indegree of the vertex
    */
  int indegree;
   /*!\var int topologicalNum
    * \brief topological order of the vertex
    */
  int topologicalNum;
};
/*!\class Graph
 * \brief It's a Graph class
 *
 */
class Graph{
public:
  /*!\fn Graph()
   * \brief Constructor: Allocate a graph object.
   */
  Graph();
   /*!\var int NUM_VERTICES
    * \brief Number of vertices in the graph
    */
  int NUM_VERTICES;
   /*!\var vector <Vertex> vertices
    * \brief Vector of Vertex that holds all vertices of the graph
    */
  vector <Vertex> vertices;
   /*!\var vector <Vertex> sorted
    * \brief Vector of Vertex that holds all ordered vertices of the graph after topological sort
    */
  vector <Vertex> sorted;
   /*!\var vector <vector <bool> > adjacency
    * \brief 2D vector that holds adjacency of the graph
    */
  vector <vector <bool> > adjacency;
   /*!\fn insert(const Vertex& v)
    * \brief insert a new vertex into the graph
    * \param v the Vertex to be inserted
    */
  void insert(const Vertex& v);
   /*!\fn topsort()
    * \brief perform topological sort on the graph and compute the sorted vector
    */
  void topsort();
   /*!\fn find(const Vertex& v)
    * \brief find whether a vertex is in the graph
    * \return Returns v's index in the graph if v is in the graph, else return -1
    * \param v Vertex to be found
    */
  int find(const Vertex& v);
  /*!\fn updateAdjacency(int r, int c);
    * \brief updates the graph's adjacency table
    * \param r row index 
    * \param c column index
    */
  void updateAdjacency(int r, int c);
};
 /*!\fn Vertex::Vertex()
   * \brief Constructor: Allocate a vertex object
   */
Vertex:: Vertex(){
  name = "NULL";
  indegree= 0;
  topologicalNum = 0;
}
 /*!\fn Vertex::Vertex(string s)
   * \brief Constructor: Allocate a vertex object and assign name = s
   * \param s Name for vertex being created.
   */
Vertex:: Vertex(string s){
  name = s;
}
/*!\fn Graph::Graph()
   * \brief Constructor: Allocate a graph object.
   */
Graph:: Graph(){
  NUM_VERTICES = 0;
  adjacency.resize( 30 , vector<bool>( 30 , false ) );
}
 /*!\fn Graph::insert(const Vertex& v)
    * \brief insert a new vertex into the graph
    * \param v the Vertex to be inserted
    */
void Graph:: insert(const Vertex& v){
  vertices.push_back(v);
  ++NUM_VERTICES;
}
   /*!\fn Graph::topsort()
    * \brief perform topological sort on the graph and compute the sorted vector
    */
void Graph:: topsort(){
  sorted.resize(NUM_VERTICES);
  queue <Vertex> q;
  int counter = 0;
  Vertex v;
  for (Vertex v : vertices){
    if (v.indegree == 0){
      q.push(v);
    }
  }
  while (!q.empty()) {
    v = q.front(); // get vertex of indegree 0
    q.pop();
    sorted[counter] = v;
    v.topologicalNum = ++counter;
    for ( int i= 0; i < NUM_VERTICES; i++){ // insert eligible verts
      if (adjacency[find(v)][i] == true){
	if (--vertices[i].indegree == 0){
	  q.push(vertices[i]);
	  }
      }
    }
  }
  if (counter != NUM_VERTICES){
    cout << "Cycle found! Exiting";
    exit(0);
  }
}
 /*!\fn Graph::find(const Vertex& v)
    * \brief find whether a vertex is in the graph
    * \return Returns v's index in the graph if v is in the graph, else return -1
    * \param v Vertex to be found
    */
int Graph::find(const Vertex& v){
  int count = 0;
  while ( count < vertices.size() ){
    if ( vertices[count].name == v.name )
      return count;
    ++count;
  }
  return -1;
}
 /*!\fn Graph::updateAdjacency(int r, int c);
    * \brief updates the graph's adjacency table
    * \param r row index
    * \param c column index 
    */
void Graph:: updateAdjacency(int r, int c){
  adjacency[r][c] = true;
}
// we want to use parameters
  /*!\fn main(int argc, char **argv)
   * \brief where all the work is done
   * Reads in the input file
   * Creates and store new vertices
   * Updates vertices' indegree
   * Updates the adjacency list
   * Calls topological sort
   * Prints output
   * \return 0 Returned 0 when the program is done
   * \param argc Number of element in command line input
   * \param argv Array of string from command line input
   */
int main (int argc, char **argv) {
  Graph* g = new Graph();
  // verify the correct number of parameters
  if ( argc != 2 ) {
    cout << "Must supply the input file name as the one and only parameter" << endl;
    exit(1);
  }
  // attempt to open the supplied file
  ifstream file(argv[1], ifstream::binary);
  // report any problems opening the file and then exit
  if ( !file.is_open() ) {
    cout << "Unable to open file '" << argv[1] << "'." << endl;
    exit(2);
  }
  // read in two strings
  string s1, s2;
  file >> s1;
  file >> s2;
  while (s1 != "0" && s2 != "0") {
    Vertex v1(s1);
    Vertex v2(s2);
    if (g->find(v1) == -1){
      g->insert(v1);
    }
    if (g->find(v2) == -1){
      g->insert(v2);
    }
    g->vertices[g->find(v2)].indegree++;
    g->updateAdjacency(g->find(v1), g->find(v2));
    file >> s1;
    file >> s2;
  }
  g->topsort();
  for (int i= 0; i < g->NUM_VERTICES; i++){
    cout << g->sorted[i].name << " ";
  }
  cout << "\n";
  // close the file before exiting
  file.close();
  delete g;
  return 0;
}
