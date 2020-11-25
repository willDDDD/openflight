#pragma once

//hash table, seperate chaining, link list
#include "vertex.h"
#include <vector>
#include <deque>
#include "listnode.h"
using namespace std;

class graph {
    private:
      vertex *arrOfVertices;
      listnode * right_list;
    public:
      void buildhash(vector<vertex> input);
      void build_icedge_listnod(vector<edge> input);
};