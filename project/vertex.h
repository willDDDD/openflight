#pragma once
#include <string>
#include <deque>
#include "vertex.h"
#include "edge.h"
#include "HSLA/PNG.h"
#include "HSLA/HSLAPixel.h"
using namespace cs225;
using namespace std;


/**
 * The Vertex class
 * We define each airport as an Vertex
 * Each Vertex is initallize by a unique id, latitude, longitude, city and ITAT code
 */
class Vertex {
    public:
        Vertex();
        Vertex(int a, double b, double c, string d, string e);
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
        bool is_explored;

        
        deque<Edge*> incid_edgs;
};