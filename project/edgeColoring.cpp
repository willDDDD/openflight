#include "edgeColoring.h"
#include <iostream>

//get Airport pixel cooridnate on the map
Edge_coloring::Edge_coloring() {}

Edge_coloring::Edge_coloring(PNG new_png)
{
    background = new_png;
}

//Negative is South, positive is North.
//Negative is West, positive is East.

pair<int, int> Edge_coloring::findAirportCoor(Vertex target)
{
    double lat_per_pix = 180.0 / 1025;
    double long_per_pix = 360.0 / 2048;
    int center_lat_pix = 1025 / 2;
    int center_long_pix = 2048 / 2;
    int pix_lat = target.lat / lat_per_pix; //lat divded by lat_per_pix to get how many pixels we are off from the center_lat_pix
    int pix_long = target.longt / long_per_pix;
    pair<int, int> result_pix; //color underline on my side, idk why it appears.
    result_pix = make_pair(center_long_pix + pix_long, center_lat_pix - pix_lat);
    return result_pix;
}

PNG Edge_coloring::drawAirline(PNG png, Vertex source, Vertex dest, int hue)
{
    pair<int, int> source_coordinate = findAirportCoor(source);
    pair<int, int> dest_coordinate = findAirportCoor(dest);
    int x1 = source_coordinate.first;
    int y1 = source_coordinate.second;
    int x2 = dest_coordinate.first;
    int y2 = dest_coordinate.second;
    cout<<"x1: " << x1 << endl;
    cout<<"x2: " << x2 << endl;
    cout<<"y1: " << y1 << endl;
    cout<<"y2: " << y2 << endl;

    PNG image = png;
    HSLAPixel color;
    color.h = hue;
    color.s = 1;
    color.l = 0.5;
    color.a = 1;
    //可以划左下到右上
    if (x1 < x2 && y1 > y2) {
        for (int x = x1; x <= x2; x++) {
            int y = -((x-x1)*(y1-y2)/(x2-x1))+y1;
            HSLAPixel &pixel = image.getPixel(x, y);
            pixel = color;    
        }
    }

    if(x1<x2 && y1<y2){
        for(int x=x1; x<=x2;x++){
            int y = ((x-x1)*(y2-y1)/(x2-x1))+y1;
             HSLAPixel &pixel = image.getPixel(x, y);
            pixel = color;
        }
    }

    if(x1 > x2 && y1<y2){
        for(int y=y1;y<=y2;y++){
            int x = -((y-y1)*(x1-x2)/(y2-y1)) + x1;
             HSLAPixel &pixel = image.getPixel(x, y);
            pixel = color;
        }
    }

    if(x1>x2 && y1>y2){
        for(int y=y2; y<=y1;y++){
            int x =((y2-y)*(x1-x2)/(y2-y1)) + x2;
            HSLAPixel &pixel = image.getPixel(x, y);
            pixel = color;
        }
    }
    // if (x1 > x2 && y1 < y2) {
    //     int dx = 1024-x1;
    //     for (int y = y1; y <= y2; y++) {
    //         int x = ((y - y1) * (x2 - x1) / (y2 - y1)) + x2;
    //         cout<< x << endl;
    //         HSLAPixel &pixel = image.getPixel(x-dx, 1025-y);
    //         pixel = color;    
    //     }
    // }
    // if (x1 < x2 && y1 > y2) {
    //     for (int x = x1; x <= x2; x++) {
    //         int y = ((x - x1) * (y1 - y2) / (x2 - x1)) + x1;
    //         cout<< x << endl;
    //         HSLAPixel &pixel = image.getPixel(x, y);
    //         pixel = color;    
    //     }
    // }
   
    return image;
}