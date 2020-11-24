#pragma once
#include <string>
#include <vector>
#include "vertex.h"
#include "edge.h"


/** 
 * Reads the airport file
 * @param filename The file to read from 
 * @return a list of airport data, each line is in a vector
 */
vector<vertex> read_airport(const string & filename);

/** 
 * to split each line of airport data by commas, 
 * then store the id, longitude, latitude, city, and ITAT
 * @param input the string to split
 * @return a vertex for each line
 */
vertex split_vertex(string input);


/** 
 * Reads the route file
 * @param filename The file to read from 
 * @return a list of route data, each line is in a vector
 */
vector<edge> read_route(const string &filename);

/** 
 * to split each line of route data by commas, 
 * then store the id, source airport id, and destination airport id
 * @param input the string to split
 * @return an edge for each line
 */
edge split_edge(string input);

int maxsize;


