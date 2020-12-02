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
vector<Vertex> read_airport(const string & filename);

/** 
 * to split each line of airport data by commas, 
 * then store the id, longitude, latitude, city, and ITAT
 * @param input the string to split
 * @return a Vertex for each line
 */
Vertex split_vertex(string &input);


/** 
 * Reads the route file
 * @param filename The file to read from 
 * @return a list of route data, each line is in a vector
 */
vector<Edge> read_route(const string &filename);

/** 
 * to split each line of route data by commas, 
 * then store the id, source airport id, and destination airport id
 * @param input the string to split
 * @return an Edge for each line
 */
Edge split_edge(string &input);


