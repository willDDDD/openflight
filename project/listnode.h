#pragma once
#include "edge.h"

class listnode {
    public:
      listnode(int,int,int);
      int source;
      int dest;
      int route;
      edge * so_;
      edge * de_;
};