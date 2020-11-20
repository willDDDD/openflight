#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "vertex.h"
#include "edge.h"
using namespace std;

template <class T>
class get_data {
    public:
      vector<T> read_data(const string & filename, int);
      vector<edge> read_route_from_file();
      vector<vertex> read_airport_from_file();
      vertex split_vertex(string);
};

#include "get_data.hpp"