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
        /*
         * The no-argument constructor of the edge class
         */
        Edge();
        /*
         * The destructor of the edge class
         */
        ~Edge();    
        /*
         * The commonly used constructor of the edge class
         * @param a id of the edge
         * @param b source airport
         * @param c destination airport
         * @param d whether the edge is in the full deque of edges
         */
        Edge(int a, int b, int c, bool d);
        
        /*
         * The source airport of the current edge
         */
        int source;
        /*
         * The destination airport of the current edge
         */
        int dest;
        /*
         * The id of the air route re
         */
        int id;
        
        int dis_cros; // 0-unexplored;1-discovery;2-cross
        
        bool isInRightList;// true-right;false-middle
        Edge * so_;
        Edge * de_;
};
