#include "graph.h"

void Graph::buildhash(vector<Vertex> input) {
    int maxsize = 0;
    for (auto i : input) {
        if (i.id > maxsize) {
            maxsize = i.id;
        }
    }
    arrOfVertices_size = maxsize;
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

void Graph::BFS() {
    component = 0;
    for (unsigned i = 0; i < arrOfVertices_size; i++) {
        arrOfVertices[i].is_explored = false;
    }
    for (unsigned i = 0; i < list.size(); i++) {
        list[i]->dis_cros = 0;
    }
    for (unsigned i = 0; i < arrOfVertices_size; i++) {
        if (arrOfVertices[i].is_explored == false) {
            BFS(arrOfVertices[i]);
            component++;
        }
    }
}

void Graph::BFS(Vertex V) {
    queue<Vertex> q;
    arrOfVertices[V.id].is_explored = true;
    q.push(V);

    while (!q.empty()) {
        V=q.front();
        q.pop();
        for (size_t m = 0; m < arrOfVertices[V.id].incid_edgs.size(); m++) {
            int w = arrOfVertices[V.id].incid_edgs[m]->dest;
            if (arrOfVertices[w].is_explored == false) {
                arrOfVertices[w].is_explored = true;
                arrOfVertices[V.id].incid_edgs[m]->so_->dis_cros = 1;
                q.push(arrOfVertices[w]);
            } else {
                if (arrOfVertices[V.id].incid_edgs[m]->so_->dis_cros == 0) {
                    arrOfVertices[V.id].incid_edgs[m]->so_->dis_cros = 2;
                }
            }
        }
    } 
}

