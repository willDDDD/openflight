#include "vertex.h"
#include "HSLA/PNG.h"
#include "HSLA/HSLAPixel.h"
using namespace std;
using namespace cs225;

Vertex::Vertex() {
    //do nothing;
}

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


    