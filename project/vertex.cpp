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
}

//get Airport pixel cooridnate on the map
// pair<int, int> Vertex::findAirport() {
//     double lat_per_pix = 180.0/1025;
//     double long_per_pix = 360.0/2048;
//     int center_lat_pix = 1025/2;
//     int center_long_pix = 2048/2;
//     int pix_lat = this->lat/lat_per_pix; //lat divded by lat_per_pix to get how many pixels we are off from the center_lat_pix
//     int pix_long = this->longt/long_per_pix;
//     pair<int, int> result_pix; //red underline on my side, idk why it appears.
//     result_pix = make_pair(center_lat_pix + pix_lat, center_long_pix+pix_long);
//     return result_pix;
// }

// void Vertex::drawAirline(cs225::PNG png, Vertex source, Vertex dest) {
//     pair<int, int> source_coordinate = source.findAirport();
//     pair<int, int> dest_coordinate = dest.findAirport();
//     int x1 = source_coordinate.first;
//     int y1 = source_coordinate.second;
//     int x2 = dest_coordinate.first;
//     int y2 = dest_coordinate.second;

    
//     PNG * image = new PNG((unsigned int)2048,(unsigned int)1025);
//     HSLAPixel red;
//     red.h = 0;
//     red.s = 1;
//     red.l = 0.5;
//     red.a = 1;

//     for (int y = y1; y <= y2; y++) {
//         for (int x = x1; x <= x2; x++) {
//             x = ((y - y1) * (x2 - x1) / (y2 - y1)) + x1;
//             HSLAPixel &pixel = image->getPixel(x, y);
//             pixel = red;
//         }
//     }
// }
    