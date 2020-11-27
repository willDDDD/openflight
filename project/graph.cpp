#include "graph.h"

void graph::buildhash(vector<Vertex> input) {
    int maxsize = 0;
    for (auto i : input) {
        if (i.id > maxsize) {
            maxsize = i.id;
        }
    }
    arrOfVertices = new Vertex[maxsize];
    for (auto i : input) {
        arrOfVertices[i.id] = i;
    }
}

void graph::build_icedge_listnod(vector<Edge> input) {
    // for (auto i : input) {
    //     right_list.push_back(new Listnode(i.source,i.dest,i.id));
    // }
    for (auto i : input) {
        bool check = true;
        for (auto j = arrOfVertices[i.source].incid_edgs.begin(); j != arrOfVertices[i.source].incid_edgs.end();j++) {
            if ((*j)->source == i.source) {
                check = false;
            } 
        }
        if (check) {
            arrOfVertices[i.source].incid_edgs.push_back(new Edge(i));
            
        }
    }
}
