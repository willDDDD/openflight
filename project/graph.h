#pragma once

//hash table, seperate chaining, link list
#include "vertex.h"
#include "edge.h"
#include <vector>
#include <deque>
#include <queue>

using namespace std;

class Graph {
    private:
      Vertex* arrOfVertices;
      unsigned long arrOfVertices_size;
      deque<Edge*> list;
      int component;
      int count;
      vector<vector<Vertex>> strong_con;
    public:
      void buildhash(vector<Vertex> input);
      void build_icedge_listnod(vector<Edge> input);
      void BFS();
      void BFS(Vertex);
      vector<vector<Vertex>> getAllMinorityGroups();
      vector<vector<Vertex>> getExactMinorityByNum(int);
      vector<Vertex> getExactMinorityByV(Vertex);
};
