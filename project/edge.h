#pragma once
#include <string>
using namespace std;


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
};