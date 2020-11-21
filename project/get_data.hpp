// #include "get_data.h"
#include <utility>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;


vertex get_data::split_vertex(string input) {
    int first = input.find(',');
    string id = input.substr(0, first);
    input=input.substr(first+1);
    int d1 = input.find(',');
    input = input.substr(d1+2);
    int second = input.find(',');
    string city = input.substr(0, second-1);
    input = input.substr(second+1);
    int d2 = input.find(',');
    input=input.substr(d2+2);
    int third = input.find(',');
    string IATA = input.substr(0, third-1);
    input = input.substr(third+1);
    int d3 = input.find(',');
    input = input.substr(d3+1);
    int fourth = input.find(',');
    string lat = input.substr(0 , fourth);
    input = input.substr(fourth+1);
    int fifth = input.find(',');
    string longt = input.substr(0, fifth);
    int id_=atoi(id.c_str());
    double lat_ = atof(lat.c_str());
    double longt_ = atof(longt.c_str());
    return vertex(id_,lat_,longt_ ,city,IATA);
}



