#pragma once
#include <string>
#include "HSLA/HSLAPixel.h"
#include "HSLA/PNG.h"
#include "listnode.h"
using namespace std;
using namespace cs225;


/**
 * The Edge class
 * We define each route as an Edge
 * Each Edge is initallized by a unique id, source airport id, and destination airport id
 * All of these three are in integer
 */
class Edge {
    public:
        Edge(int,int,int);
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


        void drawAirline(PNG png, Vertex source, Vertex dest);
        void drawAirlines(PNG png);

        Listnode* sou_;
        Listnode* des_;
};