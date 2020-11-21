#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "vertex.h"
#include "edge.h"
using namespace std;


class get_data {
    public:
      vector<edge> read_route_from_file(string file_name);
      vector<vertex> read_airport_from_file(string file_name);
      vertex split_vertex(string);
};

#include "get_data.hpp"