#include "graphDrawing.h"
#include <iostream>

//get Airport pixel cooridnate on the map
Graph_coloring::Graph_coloring() {}

Graph_coloring::Graph_coloring(PNG new_png)
{
    background = new_png;
}

//Negative is South, positive is North.
//Negative is West, positive is East.

pair<int, int> Graph_coloring::findAirportCoor(Vertex target)
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

void Graph_coloring::drawAirline(PNG &png, Vertex source, Vertex dest, double lum)
{
    pair<int, int> source_coordinate = findAirportCoor(source);
    pair<int, int> dest_coordinate = findAirportCoor(dest);
    //coordinate on picture
    int x1 = source_coordinate.first;
    int y1 = source_coordinate.second;
    int x2 = dest_coordinate.first;
    int y2 = dest_coordinate.second;

    HSLAPixel color;
    color.h = 300; //red
    color.s = 1;
    color.l = lum; // range from 25 to 75, the smaller the darker
    color.a = 1;

    if (x1 < x2 && y1 > y2)
    {
        if (x2 - x1 > 1024) {
            int x_diff = 2048 - x2 + x1;
            int y_diff = y1 - y2;
            int coor = y2 + (2048 - x2) * 1.0 / x_diff * y_diff;
            for (int y = coor + 1; y < y1; y++) {
                int x = (coor - y) * x1 * 1.0 / (coor - y1);
                HSLAPixel &pixel = png.getPixel(x, y);
                pixel = color;
            }
            for (int y = y2; y < coor; y++) {
                int x = (coor - y) * (2048 - x2) * 1.0/ (coor - y2);
                HSLAPixel &pixel = png.getPixel(2048 - x, y);
                pixel = color;
            }
        } else {
            for (int x = x1; x <= x2; x++)
            {
                int y = -((x - x1) * (y1 - y2) * 1.0 / (x2 - x1)) + y1;
                HSLAPixel &pixel = png.getPixel(x, y);
                pixel = color;
            }
        }
        
    }

    if (x1 < x2 && y1 < y2)
    {
        if (x2 - x1 > 1024)
        {
            int x_diff = 2048 - x2 + x1;
            int y_diff = y2 - y1;
            int coor = y2 - (2048 - x2) * 1.0 / x_diff * y_diff;
            for (int y = y1; y < coor; y++)
            {
                int x = (coor - y) * x1 * 1.0/ (coor - y1);
                HSLAPixel &pixel = png.getPixel(x, y);
                pixel = color;
            }
            for (int y = coor + 1; y < y2; y++)
            {
               
                int x = (coor - y) * (2048 - x2) * 1.0/ (coor - y2);
                HSLAPixel &pixel = png.getPixel(2048 - x, y);
                pixel = color;
            }
        }
        else
        {
            for (int x = x1; x <= x2; x++)
            {
                int y = ((x - x1) * (y2 - y1) * 1.0/ (x2 - x1)) + y1;
                HSLAPixel &pixel = png.getPixel(x, y);
                pixel = color;
            }
        }
    }

    if (x1 > x2 && y1 < y2)
    {
        if (x1 - x2 > 1024) {
            int x_diff = 2048 - x1 + x2;
            int y_diff = y2 - y1;
            int coor = y1 + (2048 - x1) * 1.0 / x_diff * y_diff;
            for (int y = coor  + 1; y < y2; y++) {
                int x = (coor - y) * x2 / (coor - y2);
                HSLAPixel &pixel = png.getPixel(x, y);
                pixel = color;
            }
            for (int y = y1; y < coor; y++) {
                int x = (coor - y) * (2048 - x1)* 1.0 / (coor - y1);
                HSLAPixel &pixel = png.getPixel(2048 - x, y);
                pixel = color;
            }
        } else {
            for (int y = y1; y <= y2; y++)
            {
                int x = -((y - y1) * (x1 - x2)* 1.0 / (y2 - y1)) + x1;
                HSLAPixel &pixel = png.getPixel(x, y);
                pixel = color;
            }
        }
        
    }

    if (x1 > x2 && y1 > y2)
    {
        if (x1 - x2 > 1024) {
            int x_diff = 2048 - x1 + x2;
            int y_diff = y1 - y2;
            int coor = y1 - (2048 - x1) * 1.0 / x_diff * y_diff;
            for (int y = y2; y < coor; y++)
            {
                
                int x = (coor - y) * x2 * 1.0/ (coor - y2);
                HSLAPixel &pixel = png.getPixel(x, y);
                pixel = color;
            }
            for (int y = coor + 1; y < y1; y++)
            {
               
                int x = (coor - y) * (2048 - x1) * 1.0/ (coor - y1);
                HSLAPixel &pixel = png.getPixel(2048 - x, y);
                pixel = color;
            }
        }
        else {
            for (int y = y2; y <= y1; y++)
            {
                int x = ((y2 - y) * (x1 - x2)* 1.0 / (y2 - y1)) + x2;
                HSLAPixel &pixel = png.getPixel(x, y);
                pixel = color;
            }
        }
    }
}

void Graph_coloring::drawAirport(PNG &png, Vertex airport, double lum)
{
    pair<int, int> airport_coordinate = findAirportCoor(airport);
    int x = airport_coordinate.first;
    int y = airport_coordinate.second;
    HSLAPixel color;
    color.h = 35;
    color.s = 1;
    color.l = lum;
    color.a = 1;

    for (int i = x - 1; i <= x + 1; i++)
    {
        for (int j = y - 1; j <= y + 1; j++)
        {
            HSLAPixel &pixel = png.getPixel(i, j);
            pixel = color;
        }
    }
}

double Graph_coloring::getLum(Vertex v)
{
    int currnum = v.incid_edgs.size(); //num of incid_edges of v
    return 0.25 + currnum / 248 * 0.5; //TODO
}

