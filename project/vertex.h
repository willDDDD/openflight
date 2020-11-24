#pragma once
#include <string>
#include <deque>
#include "edge.h"
using namespace std;


/**
 * The vertex class
 * We define each airport as an vertex
 * Each vertex is initallize by a unique id, latitude, longitude, city and ITAT code
 */
class vertex {
    public:
        vertex();
        vertex(int a, double b, double c, string d, string e);
        /* 
         * id the Airport ID: unique OpenFlights identifier for this airport.
         */
        int id;
        /*
         * lat the latitude of the airport: Decimal degrees, usually to six significant digits. Negative is South, positive is North.
         */
        double lat;
        /*
         * longt the longitude of the airport: Decimal degrees, usually to six significant digits. Negative is West, positive is East.
         */
        double longt;
        /* 
         * city the main city served by airport. May be spelled differently from Name.
         */
        string city;
        /* 
         * IATA the 3-letter IATA code. Null if not asssigned/unknown.
         */
        string IATA;   //3-letter IATA code. Null if not assigned/unknown.

        pair<int, int> findAirport(vertex v); //result should be int since pixel coor is represented by ints
        deque<edge> incid_edgs;
};