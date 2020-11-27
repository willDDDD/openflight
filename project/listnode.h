#pragma once
#include "vertex.h"
#include "edge.h"
class Listnode{
    public:
      Listnode(int,int,int);
      int source;
      int dest;
      int route;
      Edge * so_;
      Edge * de_;
};