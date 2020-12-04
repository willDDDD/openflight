#pragma once
#include <string>
#include "HSLA/HSLAPixel.h"
#include "HSLA/PNG.h"
#include "vertex.h"
#include "edge.h"
using namespace std;
using namespace cs225;


class Graph_coloring {
    public:
        Graph_coloring();

        Graph_coloring(cs225::PNG png);
        
        pair<int, int> findAirportCoor(Vertex); //result should be int since pixel coor is represented by ints
        
        void drawAirline(PNG & png, Vertex source, Vertex dest, double lum);

        void drawAirport(PNG & png, Vertex airport, double lum);

        double getLum(Vertex v);

        PNG background;

};