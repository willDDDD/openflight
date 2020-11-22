#pragma once
#include <string>
using namespace std;


    /**
     * The edge class
     * We define each route as an edge
     * Each edge is initallize by a unique id, source airport id, and destination airport id
     * All of these three are in integer
     */
class edge {
    public:
     edge(int,int,int);     
     int id; 
     int source;
     int dest;
};