#include "graph.h"
#include <iostream>
#include "limits.h"
#include <cmath>
using namespace std;

void Graph::buildhash(const vector<Vertex> &input) {
    int maxsize = 0;
    for (auto i : input) {
        if (i.id > maxsize) {
            maxsize = i.id;
        }
    }
    arrOfVertices_size = maxsize;
    arrOfVertices = new Vertex[maxsize*2];
    for (auto i : input) {
        arrOfVertices[i.id] = i;
        arrOfVertices[i.id].isSeted = true;
    }
    vec_of_ver = input;
}

void Graph::build(const vector<Edge> &input, const vector<Vertex> &e) {
    buildhash(e);
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
        if (arrOfVertices[list[j]->source].isSeted == true && arrOfVertices[list[j]->dest].isSeted == true) {
            arrOfVertices[list[j]->source].incid_edgs.push_back(new Edge(list[j]->id,list[j]->source,list[j]->dest, false));
            arrOfVertices[list[j]->dest].incid_edgs.push_back(new Edge(list[j]->id, list[j]->dest,list[j]->source, false));
            list[j]->so_ = arrOfVertices[list[j]->source].incid_edgs.back();
            list[j]->de_ = arrOfVertices[list[j]->dest].incid_edgs.back();
            arrOfVertices[list[j]->source].incid_edgs.back()->de_ = NULL;
            arrOfVertices[list[j]->source].incid_edgs.back()->so_ = list[j];
            arrOfVertices[list[j]->dest].incid_edgs.back()->so_ = list[j];
            arrOfVertices[list[j]->dest].incid_edgs.back()->de_ = NULL;
        }
    }
}

void Graph::BFS() {
    component = 0;
    number_of_vertices_by_BFS = 0;
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
            BFS(arrOfVertices[i]);
            component++;
        }
    }
}

void Graph::BFS(Vertex V) {
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

vector<int> Graph::shortestPath(Vertex source, Vertex target) {
    
    map<int, int> dist;
    map<int, int> pre;
    for (auto& e : vec_of_ver) {
        dist[e.id] = -2;
        pre[e.id] = -1;
    }
    dist[source.id] = 0;
    priorityQueue pq(vec_of_ver,dist);
    for(unsigned i = 0; i < vec_of_ver.size(); i++) {
        int u = pq.removeMin();
        arrOfVertices[u].short_vis = true;
        for (auto e : arrOfVertices[u].incid_edgs) {
            if (arrOfVertices[e->dest].short_vis == false) {
                int distance = getDistance(e);
                if (distCompareHelper(dist[u] + distance, dist[e->dest])) {
                    int new_dis = dist[u] + distance;
                    pq.updateDistance(dist, e->dest, new_dis);
                    dist[e->dest] = dist[u] + distance;
                    pre[e->dest] = u;
                }
            }
        }
    }
    int t = target.id;
    vector<int> r;
    r.push_back(t);
    while (pre[t] != source.id) {
        if (pre[t] == -1) {
            cout<< "no shortest path" << endl;
            return vector<int>();
        }
        t = pre[t];
        r.push_back(t);
    }
    r.push_back(source.id);
    reverse(r.begin(),r.end());
    return r;
}

int Graph::getDistance(Edge *e) {
    double lat1 = arrOfVertices[e->source].lat;
    double lon1 = arrOfVertices[e->source].longt;
    double lat2 = arrOfVertices[e->dest].lat;
    double lon2 = arrOfVertices[e->dest].longt;

   
    long double PI = 0.017453292519943295;
    // long double R = 6.371229*1e6;

    long double a = 0.5 - cos((lat2 - lat1) * PI)/2 + cos(lat1 * PI) * cos(lat2 * PI) * (1 - cos((lon2 - lon1) * PI))/2;
    return int(12742 * asin(sqrt(a))); // in km
}

bool Graph::distCompareHelper(int first, int second) {
    if (first < 0 && second < 0) {
        return false;
    }
    if (first < 0) {
        return false;
    }
    if (second < 0) {
        return true;
    }
    return first < second;
}