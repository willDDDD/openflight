#include "edge.h"
#include "vertex.h"

/**
 * Constructor of edge
 *
 * @param a id
 * @param b source airport
 * @param c destination airport
 */
edge::edge(int a, int b, int c) {
    id = a;
    source = b;
    dest = c;
}




void edge::drawAirline(PNG png, vertex source, vertex dest) {
    pair<int, int> source_coordinate = source.findAirport();
    pair<int, int> dest_coordinate = dest.findAirport();
    int x1 = source_coordinate.first;
    int y1 = source_coordinate.second;
    int x2 = dest_coordinate.first;
    int y2 = dest_coordinate.second;

    
    PNG * image = new PNG(2048,1025);
    HSLAPixel red;
    red.h = 0;
    red.s = 1;
    red.l = 0.5;
    red.a = 1;

    for (int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++) {
            x = ((y - y1) * (x2 - x1) / (y2 - y1)) + x1;
            HSLAPixel &pixel = image->getPixel(x, y);
            pixel = red;
        }
    }
    
}

