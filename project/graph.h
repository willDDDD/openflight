#pragma once

//hash table, seperate chaining, link list
#include "vertex.h"
#include <vector>
using namespace std;

class graph {
    private:
      vertex *arrOfVertices;
      unsigned size;
    public:
      void buildhash(vector<vertex> input);
      void incidentedge(vector<edge> input);
};