#include "get_data.h"
#include <utility>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;


template <class T>
vector<T> get_data<T>::read_data(const string & filename, int check) {
    if (check == 0) {
        return read_airport_from_file(filename);
    }
    // if (check == 1) {
    //     return read_route(filename);
    // }
}

template <class T>
vector<vertex> get_data<T>::read_airport_from_file() {
    vector<vertex> out;
    ifstream wordsFile("airport.dat");
    string line;
    if (wordsFile.is_open()) {
        while (getline(wordsFile, line)) {
            string s = line;
            out.push_back(split_vertex(s));
        }
    }
    return out;
}

template <class T>
vector<edge> get_data<T>::read_route_from_file() {
    vector<edge> out;
    ifstream wordsFile("route.dat");
    string line;
    if (wordsFile.is_open()) {
        while (getline(wordsFile, line)) {
            string s = line;
            out.push_back(split_vertex(s));
        }
    }
    return out;
}


template <class T>
vertex get_data<T>::split_vertex(string input) {
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


// AnagramDict::AnagramDict(const string& filename)
// {
//     /* Your code goes here! */
//     ifstream wordsFile(filename);
//     string word;
//     if (wordsFile.is_open()) {
//         /* Reads a line from `wordsFile` into `word` until the file ends. */
//         while (getline(wordsFile, word)) {
//             string s = word;
//             std::sort(s.begin(),s.end());
//             dict[s].push_back(word);
//         }
//     }
// }

