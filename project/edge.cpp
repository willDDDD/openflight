#include "edge.h"

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