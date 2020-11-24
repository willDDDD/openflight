#include "graph.h"

void graph::buildhash(vector<vertex> input) {
    int maxsize = 0;
    for (auto i : input) {
        if (i.id > maxsize) {
            maxsize = i.id;
        }
    }
    arrOfVertices = new vertex[maxsize];
    for (auto i : input) {
        arrOfVertices[i.id] = i;
    }
}

void graph::incidentedge(vector<edge> input) {
    for (auto i : input) {
        
    }
}