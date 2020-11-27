#include "graph.h"

void Graph::buildhash(vector<Vertex> input) {
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

void Graph::build_icedge_listnod(vector<Edge> input) {
    for (auto i : input) {
        bool c = true;
        for (unsigned long m = 0; m < list.size();m++) {
            if ((i.source==list[m]->source && i.dest==list[m]->dest) || (i.source==list[m]->dest && i.dest==list[m]->source)) {
                c = false;
            }
        }
        if (c) {
            list.push_back(new Edge(i.source,i.dest,i.id, true));
        }
    }
    for (unsigned long j = 0; j < list.size();j++) {
        arrOfVertices[list[j]->source].incid_edgs.push_back(new Edge(list[j]->source,list[j]->dest,list[j]->id, false));
        arrOfVertices[list[j]->dest].incid_edgs.push_back(new Edge(list[j]->source,list[j]->dest,list[j]->id, false));
        list[j]->so_ = arrOfVertices[list[j]->source].incid_edgs.back();
        list[j]->de_ = arrOfVertices[list[j]->dest].incid_edgs.back();
        arrOfVertices[list[j]->source].incid_edgs.back()->so_ = list[j];
        arrOfVertices[list[j]->dest].incid_edgs.back()->de_ = list[j];
    }
}

