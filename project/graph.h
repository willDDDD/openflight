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

class Graph {
    public:
      Vertex* arrOfVertices;
      unsigned long arrOfVertices_size;
      deque<Edge*> list;
      int component;
      int count;
      int number_of_vertices_by_BFS;
      vector<vector<Vertex>> strong_con;
      vector<Vertex> vec_of_ver;

      void addVertex(Vertex);
      void buildhash(const vector<Vertex> &input);
      void build(const vector<Edge> & input, const vector<Vertex> &v);
      void BFS();
      void BFS(Vertex);
      vector<vector<Vertex>> getAllMinorityGroups();
      vector<vector<Vertex>> getExactMinorityByNum(unsigned long);
      vector<Vertex> getExactMinorityByV(Vertex);
      vector<int> shortestPath(Vertex,Vertex);
      // void buildHeap();
      int getDistance(Edge *);
      // return whether the first is smaller than the second distance
      bool distCompareHelper(int first, int second);
};