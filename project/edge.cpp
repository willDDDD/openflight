#include "edge.h"
#include "HSLA/HSLAPixel.h"
#include "HSLA/PNG.h"
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

void drawAirline(vertex source, vertex dest) {
    pair<int, int> source_coordinate = vertex::findAirport(source);
    pair<int, int> dest_coordinate = vertex::findAirport(dest);
    int source_lat = source_coordinate.first();
    int source_long = source_coordinate.second();
    int dest_lat = source_coordinate.first();
    int dest_long = source_coordinate.second();

    for (int i = source_lat; i < dest_lat; i++) {
        for (int j = source_long; j < dest_long; j++) {
            HSLAPixel &pixel = 
        }
    }
}