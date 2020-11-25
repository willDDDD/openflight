#pragma once
#include <string>
#include "vertex.h"
#include "HSLA/HSLAPixel.h"
#include "HSLA/PNG.h"
using namespace std;
using namespace cs225;


/**
 * The edge class
 * We define each route as an edge
 * Each edge is initallized by a unique id, source airport id, and destination airport id
 * All of these three are in integer
 */
class edge {
    public:
        edge(int,int,int);
        /*
         * id the Airline ID
         */
        int id;
        /*
         * source the Source Airport ID
         */
        int source;
        /*
         * dest the Destination Airport ID
         */
        int dest;


        HSLAPixel edge_color;


        void drawAirline(vertex source, vertex dest);

};