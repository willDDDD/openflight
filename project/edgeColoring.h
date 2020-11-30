#pragma once
#include <string>
#include "HSLA/HSLAPixel.h"
#include "HSLA/PNG.h"
#include "vertex.h"
#include "edge.h"
using namespace std;
using namespace cs225;


class Edge_coloring {
    public:
        Edge_coloring();

        Edge_coloring(cs225::PNG png);
        
        pair<int, int> findAirportCoor(Vertex); //result should be int since pixel coor is represented by ints
        
        PNG drawAirline(PNG png, Vertex source, Vertex dest, int hue);



        PNG background;

};