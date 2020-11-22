#include "vertex.h"


/**
     * Constructor of vertex
     *
     * @param a a unique id
     * @param b the latidute of the airport
     * @param c the longitude of the airport
     * @param d the city name where the airport locates
     * @param e the ITAT code for the airport
     */
vertex::vertex(int a, double b, double c, string d, string e) {
    id = a;
    lat = b;
    longt = c;
    city = d;
    IATA = e;
}