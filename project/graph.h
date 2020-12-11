#pragma once

//hash table, seperate chaining, link list
#include "vertex.h"
#include "edge.h"
#include "priorityQueue.h"
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

/**
 * The Graph class
 * We define each route as an Edge and each airport as a vertex
 * Implemented in Adjacency list
 * This is where our major graph algorithms are defined
 */
class Graph {
    public:
      /*
       * arrOfVertices the array for storing all the vertices
       * vertices are indexed by the airport id
       */
      Vertex* arrOfVertices;
      /*
       * arrOfVertices_size this variable keep record of the size of arrOfVertices
       */
      unsigned long arrOfVertices_size;
      /*
       * list The container of the list of edges
       */
      deque<Edge*> list;
      /*
       * component The number of connected component in this graph instance, must be updated using BFS first
       */
      int component;
      /*
       * count the helper variable for "get monority group methods"
       */
      int count;
      /*
       * number_of_vertices_by_BFS the number of vertices treversed by BFS, must be updated using BFS first
       */
      int number_of_vertices_by_BFS;
      /*
       * minority_groups the variable that stores the connected components that contains all the minority groups
       * minority group: the connected component that contains less than or equal to 10 
       */
      vector<vector<Vertex>> minority_groups;
      /*
       * vec_of_ver the container of the list of all vertices
       */
      vector<Vertex> vec_of_ver;
      /*
       * The destrtuctor of the class
       */
      ~Graph();
      /*
       * Builds the array of vertices for our adjacency list implementation
       * @param input the vector of the full list of vertices
       */
      void buildArrOfVertices(const vector<Vertex> &input);
      /*
       * Builds our adjacency list
       * @param input the vector of the full list of edges
       * @param v the vector of the fulll list of vertices
       */
      void build(const vector<Edge> & input, const vector<Vertex> &v);
      /*
       * Breadth-first traversal of our graph data structure
       */
      void BFS();
      /*
       * The helper-function of the breadth-first traversal of our graph data structure
       * @param v one vertex in the current connected component being visited
       */
      void BFS(Vertex);
      /*
       * Return the count of vertices (number_of_vertices_by_BFS) traversed by our BFS traversal
       * @return the number of vertices traversed by BFS
       */
      int getNumberOfVTraversed();
      /*
       * Get the vectors of vertices of all the connected components that has less than or equal
       * to 10 vertices (the component is then called a minority group, as opposed to the majority
       * of the airports in the word that are connected by plenty of edges)
       * @return the vector of vectors of vertices that live in minority groups
       */
      vector<vector<Vertex>> getAllMinorityGroups();
      /*
       * Get the vectors of vertices of all the connected components that has exactly the number
       * of edges indicated by the function argument
       * @param num the number that the user is curious about
       * @return the vector of vectors of vertices that live in the minority groups that contain
       * exactly num vertices
       */
      vector<vector<Vertex>> getExactMinorityByNum(unsigned long num);
      /*
       * Get the minority group that V belongs to
       * An empty vector will be returned if V does not belong to any of the minority groups
       * (i.e. V is connected to many other airports in the world)
       * @param V the target vertex that user expect to be in certain minority group
       * @return the minority group that contains V
       */
      vector<Vertex> getExactMinorityByV(Vertex V);
      /*
       * Implementation of Dijkstra's algorithm to find the shortest path between
       * indicated source and destination
       * @param source the source airport
       * @target the destination airport
       * @return the vertex representation of the shortest path between source and target
       */
      vector<int> shortestPath(Vertex source, Vertex target);
      /*
       * compute the distance bewteen two airport based on their latitude and longitude
       * @param e the edge that connects the two vertices
       * @return the distance between the two vertices connected by e
       */
      int getDistance(Edge * e);
      /*
       * Determine whether the first distance is smaller than the second distance
       * We use negative numbers to represent infinity in our Dijkstra's algorithm
       * @param first the first distance in integer
       * @param second the second distance in integer
       * @return true if the first distance is smaller than the second distance, false otherwise
       */
      bool distCompareHelper(int first, int second);
};