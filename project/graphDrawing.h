#pragma once
#include <string>
#include "HSLA/HSLAPixel.h"
#include "HSLA/PNG.h"
#include "vertex.h"
#include "edge.h"
#include <cmath>
using namespace std;
using namespace cs225;

/**
 * The Graph_drawing class
 * Everything related to the project-data-onto-map algorithms are included here
 */
class Graph_drawing {
    public:
        /*
         * We usually use the next constructor instead of this no-argument one
         */
        Graph_drawing();
        /*
         * The constructor of Graph_drawing class
         * @param png the png object on which we will be drawing things
         */
        Graph_drawing(cs225::PNG png);
        /*
         * Help us to determing the coordinate where the airport should be
         * @param the airport of which we want to find the coordinate on world map png
         * @return the number pair that represents the coordinate on png
         */
        pair<int, int> findAirportCoor(Vertex);
        /*
         * Draws the airline on the world map
         * @param png the png object on which we are drawing the airline
         * @param source the source airport
         * @param dest the destination airport
         * @param lum sets luminance
         */
        void drawAirline(PNG & png, Vertex source, Vertex dest, double lum);
        /*
         * Draws the airline on the world map
         * @param png the png object on which we are drawing the airline
         * @param airport the airport that we are grawing
         */
        void drawAirport(PNG & png, Vertex airport);
        /*
         * The map we are drawing on
         */
        PNG background;



};

