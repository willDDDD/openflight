#pragma once

//hash table, seperate chaining, link list
#include "vertex.h"
#include "edge.h"
#include <vector>
#include <deque>
#include "listnode.h"
using namespace std;

class graph {
    private:
      Vertex *arrOfVertices;
      Listnode * right_list;
    public:
      void buildhash(vector<Vertex> input);
      void build_icedge_listnod(vector<Edge> input);
};