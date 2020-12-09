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
    double pix_lat = target.lat / lat_per_pix; //lat divded by lat_per_pix to get how many pixels we are off from the center_lat_pix
    double pix_long = target.longt / long_per_pix;
    pair<double, double> result_pix; //color underline on my side, idk why it appears.
    result_pix = make_pair(center_long_pix + pix_long, center_lat_pix - pix_lat);
    return result_pix;
}

void Graph_coloring::drawAirline(PNG &png, Vertex source, Vertex dest, double lum)
{
    pair<double, double> source_coordinate = findAirportCoor(source);
    pair<double, double> dest_coordinate = findAirportCoor(dest);
    //coordinate on picture
    double x1 = source_coordinate.first;
    double y1 = source_coordinate.second;
    double x2 = dest_coordinate.first;
    double y2 = dest_coordinate.second;

    HSLAPixel color;
    color.h = 300; //red
    color.s = 1;
    color.l = lum; // range from 25 to 75, the smaller the darker
    color.a = 1;

    //case 1
    if (x1 < x2 && y1 > y2)
    {
        if (x2 - x1 > 1024) {
            double x_diff = 2048 - x2 + x1;
            double y_diff = y1 - y2;
            double coor = y1 - (y_diff / x_diff) * x1;
            cout<<"y1: "<<y1<<endl;
            cout<<"coor: "<<coor<<endl;
            cout<<"y2: "<<y2<<endl;
            for (int x = 0; x < x1; x++) {
                double y = ((x - 0) * (y1 - coor) / (x1 - 0)) + coor;
                HSLAPixel &pixel = png.getPixel(x, y);
                pixel = color;
            }
            for (int x = x2 + 1; x < 2048; x++) {
                double y = ((x - x2) * (coor - y2) / (2048 - x2)) + y2;
                HSLAPixel &pixel = png.getPixel(x, y);
                pixel = color;
            }
        } else {
            for (int x = x1; x <= x2; x++)
            {
                double y = -((x - x1) * (y1 - y2) / (x2 - x1)) + y1;
                HSLAPixel &pixel = png.getPixel(x, y);
                pixel = color;
            }
        }
        
    }


    //case 2
    if (x1 < x2 && y1 < y2)
    {
        if (x2 - x1 > 1024)
        {
            double x_diff = 2048 - x2 + x1;
            double y_diff = y1 - y2;
            double coor = y1 - (y_diff / x_diff) * x1;
            
            for (int x = 0; x < x1; x++)
            {
                double y = -((x - 0) * (coor - y1) / (x1 - 0)) + coor;
                HSLAPixel &pixel = png.getPixel(x, y);
                pixel = color;
            }
            for (int x = x2 +1; x < 2048; x++)
            {
                double y = -((x - x2) * (y2 - coor) / (2048 - x2)) + y2;
                HSLAPixel &pixel = png.getPixel(x, y);
                pixel = color;
            }
        }
        else
        {
            for (int x = x1; x <= x2; x++)
            {
                double y = ((x - x1) * (y2 - y1) / (x2 - x1)) + y1;
                HSLAPixel &pixel = png.getPixel(x, y);
                pixel = color;
            }
        }
    }

    //case 3
    if (x1 > x2 && y1 < y2)
    {
        if (x1 - x2 > 1024) {
            double x_diff = 2048 - x1 + x2;
            double y_diff = y2 - y1;
            double coor = y2 - (y_diff/ x_diff) * x2;
            for (int x = 0; x < x2; x++) {
                double y = ((x - 0) * (y2 - coor) / (x2 - 0)) + coor;
                HSLAPixel &pixel = png.getPixel(x, y);
                pixel = color;
            }
            for (int x = x1 + 1; x < 2048; x++) {
                double y = ((x - x1) * (coor - y1) / (2048 - x1)) + y1;
                HSLAPixel &pixel = png.getPixel(x, y);
                pixel = color;
            }
        } else {
            for (int y = y1; y <= y2; y++)
            {
                double x = -((y - y1) * (x1 - x2) / (y2 - y1)) + x1;
                HSLAPixel &pixel = png.getPixel(x, y);
                pixel = color;
            }
        }
        
    }

    //case 4
    if (x1 > x2 && y1 > y2)
    {
        if (x1 - x2 > 1024) {
            double x_diff = 2048 - x1 + x2;
            double y_diff = y2 - y1;
            double coor = y2 - (y_diff/ x_diff) * x2;
            for (int x = 0; x < x2; x++)
            {
                double y = -((x - 0) * (coor - y2) / (x2 - 0)) + coor;
                HSLAPixel &pixel = png.getPixel(x, y);
                pixel = color;
            }
            for (int x = x1 + 1; x < 2048; x++)
            {
               
                double y = -((x - x1) * (y1 - coor) / (2048 - x1)) + y1;
                HSLAPixel &pixel = png.getPixel( x, y);
                pixel = color;
            }
        }
        else {
            for (int y = y2; y <= y1; y++)
            {
                double x = ((y2 - y) * (x1 - x2) / (y2 - y1)) + x2;
                HSLAPixel &pixel = png.getPixel(x, y);
                pixel = color;
            }
        }
    }
}


void Graph_coloring::drawAirport(PNG &png, Vertex airport)
{
    pair<int, int> airport_coordinate = findAirportCoor(airport);
    int x = airport_coordinate.first;
    int y = airport_coordinate.second;
    HSLAPixel color;
    int hue = airport.incid_edgs.size();
    color.h = hue + 100;
    color.s = 1;
    color.l = 0.5;
    color.a = 1;
    
    

    for (int i = x - 2; i <= x + 2; i++)
    {
        for (int j = y - 2; j <= y + 2; j++)
        {
            HSLAPixel &pixel = png.getPixel(i, j);
            pixel = color;
        }
    }
}



