#pragma once
#include <string>
using namespace std;

class edge {
    public:
     edge(int,int,int);     
     int id; //Unique OpenFlights identifier for this airport.
     int source;//	Unique OpenFlights identifier for source airport (see Airport)
     int dest;//Unique OpenFlights identifier for destination airport (see Airport)
};