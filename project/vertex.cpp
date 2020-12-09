#include "vertex.h"
#include "HSLA/PNG.h"
#include "HSLA/HSLAPixel.h"
using namespace std;
using namespace cs225;

Vertex::Vertex() {
    //do nothing;
}


/**
 * Constructor of Vertex
 *
 * @param a a unique id
 * @param b the latidute of the airport
 * @param c the longitude of the airport
 * @param d the city name where the airport locates
 * @param e the ITAT code for the airport
 */
Vertex::Vertex(int a, double b, double c, string d, string e) {
    id = a;
    lat = b;
    longt = c;
    city = d;
    IATA = e;
    is_explored = false;
    isSeted = false;
    short_vis = false;
}


    