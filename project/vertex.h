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
        /**
         * Constructor of Vertex
         *
         * @param a a unique id
         * @param b the latidute of the airport
         * @param c the longitude of the airport
         * @param d the city name where the airport locates
         * @param e the ITAT code for the airport
         */
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
        string IATA;
        bool is_explored;
        bool isSeted;
        bool short_vis;
        /* 
         * The deque of incident edges
         */
        deque<Edge*> incid_edgs;
};