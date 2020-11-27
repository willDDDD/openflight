#pragma once

//hash table, seperate chaining, link list
#include "vertex.h"
#include "edge.h"
#include "listnode.h"
#include <vector>
#include <deque>

using namespace std;

class Graph {
    private:
      Vertex *arrOfVertices;
      Listnode * right_list;
    public:
      void buildhash(vector<Vertex> input);
      void build_icedge_listnod(vector<Edge> input);
};