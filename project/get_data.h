#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "vertex.h"
using namespace std;

template <class T>
class get_data {
    public:
      vector<T> read_data(const string & filename, int);
      vector<edge> read_route(const string & filename);
      vector<vertex> read_airport(const string & filename);
      vertex split_vertex(string);
};

#include "get_data.hpp"