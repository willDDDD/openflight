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

void graph::build_icedge_listnod(vector<edge> input) {
    // for (auto i : input) {
    //     right_list.push_back(new listnode(i.source,i.dest,i.id));
    // }
    for (auto i : input) {
        bool check = true;
        for (auto j = arrOfVertices[i.source].incid_edgs.begin(); j != arrOfVertices[i.source].incid_edgs.end();j++) {
            if ((*j)->source == i.source) {
                check = false;
            } 
        }
        if (check) {
            arrOfVertices[i.source].incid_edgs.push_back(new edge(i));
            
        }
    }
}
