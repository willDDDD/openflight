#include "edge.h"


/**
 * Constructor of Edge
 *
 * @param a id
 * @param b source airport
 * @param c destination airport
 */
Edge::Edge(int a, int b, int c,bool d) {
    isInRightList = d;
    id = a;
    source = b;
    dest = c;
    dis_cros = 0;
}

Edge::Edge() {
    
}



