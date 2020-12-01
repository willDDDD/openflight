#pragma once

//hash table, seperate chaining, link list
#include "vertex.h"
#include "edge.h"
#include <vector>
#include <deque>
#include <queue>

using namespace std;

class Graph {
    public:
      Vertex* arrOfVertices;
      unsigned long arrOfVertices_size;
      deque<Edge*> list;
      int component;
      int count;
      vector<vector<Vertex>> strong_con;
   
      void buildhash(vector<Vertex> input);
      void build(vector<Edge> input, vector<Vertex> v);
      void BFS();
      void BFS(Vertex);
      vector<vector<Vertex>> getAllMinorityGroups();
      vector<vector<Vertex>> getExactMinorityByNum(unsigned long);
      vector<Vertex> getExactMinorityByV(Vertex);
};
