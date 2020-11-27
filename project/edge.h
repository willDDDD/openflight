#pragma once
#include <string>
#include "HSLA/HSLAPixel.h"
#include "HSLA/PNG.h"
using namespace std;

/**
 * The Edge class
 * We define each route as an Edge
 * Each Edge is initallized by a unique id, source airport id, and destination airport id
 * All of these three are in integer
 */
class Edge {
    public:
        Edge(int,int,int,bool);
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

        bool isInRightList;// true-right;false-middle
        //HSLAPixel edge_color;
        Edge * so_;
        Edge * de_;
};
