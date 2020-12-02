#include "graph.h"
#include <iostream>
using namespace std;

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
        arrOfVertices[i.id].isSeted = true;
    }
}

void Graph::build(vector<Edge> input, vector<Vertex> v) {
    buildhash(v);
    for (auto i : input) {
        bool c = true;
        for (unsigned long m = 0; m < list.size();m++) {
            if ((i.source==list[m]->source && i.dest==list[m]->dest) || (i.source==list[m]->dest && i.dest==list[m]->source)) {
                c = false;
            }
        }
        if (c) {
            list.push_back(new Edge(i.id,i.source,i.dest, true));
        }
    }
    for (unsigned long j = 0; j < list.size();j++) {
        
        arrOfVertices[list[j]->source].incid_edgs.push_back(new Edge(list[j]->id,list[j]->source,list[j]->dest, false));
        
        arrOfVertices[list[j]->dest].incid_edgs.push_back(new Edge(list[j]->id, list[j]->source,list[j]->dest, false));
       
        list[j]->so_ = arrOfVertices[list[j]->source].incid_edgs.back();
        list[j]->de_ = arrOfVertices[list[j]->dest].incid_edgs.back();
        arrOfVertices[list[j]->source].incid_edgs.back()->de_ = NULL;

        arrOfVertices[list[j]->source].incid_edgs.back()->so_ = list[j];
        
        arrOfVertices[list[j]->dest].incid_edgs.back()->de_ = list[j];

        arrOfVertices[list[j]->dest].incid_edgs.back()->so_ = NULL;
    }
}

void Graph::BFS() {
    component = 0;
    cout<< "BFS() 1" <<endl;
    for (unsigned i = 0; i < arrOfVertices_size; i++) {
        if (arrOfVertices[i].isSeted == true) {
            arrOfVertices[i].is_explored = false;
        }
    }
    for (unsigned i = 0; i < list.size(); i++) {
        list[i]->dis_cros = 0;
    }
    for (unsigned i = 0; i < arrOfVertices_size; i++) {
        if (arrOfVertices[i].isSeted == true && arrOfVertices[i].is_explored == false) {
            cout<< "BFS() 2" <<endl;
            BFS(arrOfVertices[i]);
            component++;
        }
    }
}

void Graph::BFS(Vertex V) {
    cout<< "BFS(Vertex V) 1" <<endl;
    count = 1;
    vector<Vertex> temp;
    queue<Vertex> q;
    arrOfVertices[V.id].is_explored = true;
    q.push(V);
    temp.push_back(V);

    while (!q.empty()) {
        V=q.front();
        q.pop();
        for (size_t m = 0; m < arrOfVertices[V.id].incid_edgs.size(); m++) {
            int w = arrOfVertices[V.id].incid_edgs[m]->dest;
            if (arrOfVertices[w].is_explored == false) {
                arrOfVertices[w].is_explored = true;
                cout << arrOfVertices[w].id << endl;
                arrOfVertices[V.id].incid_edgs[m]->so_->dis_cros = 1;
                q.push(arrOfVertices[w]); // the thing that get pushed is a pointer
                count++;
                if (count <= 10) {
                    temp.push_back(arrOfVertices[w]); // the thing that get pushed is a pointer
                }
            } else {
                if (arrOfVertices[V.id].incid_edgs[m]->so_->dis_cros == 0) {
                    arrOfVertices[V.id].incid_edgs[m]->so_->dis_cros = 2;
                }
            }
        }
    }
    if (count <= 10) {
        strong_con.push_back(temp);
    }
}

vector<vector<Vertex>> Graph::getAllMinorityGroups() {
    return strong_con;
}

vector<vector<Vertex>> Graph::getExactMinorityByNum(unsigned long num) {
    vector<vector<Vertex>> temp;
    for (auto & i : strong_con) {
        if (i.size() == num) {
            temp.push_back(i);
        }
    }
    return temp;
}

vector<Vertex> Graph::getExactMinorityByV(Vertex V) {
    for (auto i : strong_con) {
        for (auto & j : i) {
            if (j.id == V.id) {
                return i;
            }
        }
    }
    return vector<Vertex>();
}	