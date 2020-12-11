#include "edge.h"

Edge::Edge(int a, int b, int c,bool d) {
    isInRightList = d;
    id = a;
    source = b;
    dest = c;
    dis_cros = 0;
}

Edge::Edge() {

}
Edge::~Edge() {
    
}



