#include "vertex.h"
#include "HSLA/HSLAPixel.h"
#include "HSLA/PNG.h"
using namespace std;

vertex::vertex() {
    //do nothing;
}


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

//get Airport pixel cooridnate on the map
pair<int, int> vertex::findAirport() {
    double lat_per_pix = 180.0/1025;
    double long_per_pix = 360.0/2048;
    int center_lat_pix = 1025/2;
    int center_long_pix = 2048/2;
    int pix_lat = this->lat/lat_per_pix; //lat divded by lat_per_pix to get how many pixels we are off from the center_lat_pix
    int pix_long = this->longt/long_per_pix;
    pair<int, int> result_pix; //red underline on my side, idk why it appears.
    result_pix = make_pair(center_lat_pix + pix_lat, center_long_pix+pix_long);
    return result_pix;
}