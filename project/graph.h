#pragma once

//hash table, seperate chaining, link list
#include "vertex.h"
#include "edge.h"
#include <vector>
#include <deque>
#include <queue>
#include <map>

using namespace std;

class Graph {
    public:
      Vertex* arrOfVertices;
      unsigned long arrOfVertices_size;
      deque<Edge*> list;
      int component;
      int count;
      vector<vector<Vertex>> strong_con;
      vector<Vertex> vec_of_ver;
   
      void buildhash(const vector<Vertex> &input);
      void build(const vector<Edge> & input, const vector<Vertex> &v);
      void BFS();
      void BFS(Vertex);
      vector<vector<Vertex>> getAllMinorityGroups();
      vector<vector<Vertex>> getExactMinorityByNum(unsigned long);
      vector<Vertex> getExactMinorityByV(Vertex);
      // vector<Vertex> shortestPath(Vertex);
      // void buildHeap();
      
};
