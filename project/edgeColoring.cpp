#include "edgeColoring.h"


//get Airport pixel cooridnate on the map
Edge_coloring::Edge_coloring() {}

Edge_coloring::Edge_coloring(PNG new_png) {
    background = new_png;
}

pair<int, int> Edge_coloring::findAirportCoor(Vertex target) {
    double lat_per_pix = 180.0/1025;
    double long_per_pix = 360.0/2048;
    int center_lat_pix = 1025/2;
    int center_long_pix = 2048/2;
    int pix_lat = target.lat/lat_per_pix; //lat divded by lat_per_pix to get how many pixels we are off from the center_lat_pix
    int pix_long = target.longt/long_per_pix;
    pair<int, int> result_pix; //white underline on my side, idk why it appears.
    result_pix = make_pair(center_lat_pix + pix_lat, center_long_pix+pix_long);
    return result_pix;
}

PNG Edge_coloring::drawAirline(PNG png, Vertex source, Vertex dest) {
    pair<int, int> source_coordinate = findAirportCoor(source);
    pair<int, int> dest_coordinate = findAirportCoor(dest);
    int x1 = source_coordinate.first;
    int y1 = source_coordinate.second;
    int x2 = dest_coordinate.first;
    int y2 = dest_coordinate.second;

    
    PNG  image = png;

    
    HSLAPixel white;
    white.h = 0;
    white.s = 1;
    white.l = 1;
    white.a = 1;

    for (int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++) {
            x = ((y - y1) * (x2 - x1) / (y2 - y1)) + x1;
            HSLAPixel &pixel = image.getPixel(x, y);
            pixel = white;
        }
    }
    return png;
}

