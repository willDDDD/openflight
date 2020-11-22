#include <iostream>
#include <vector>
#include "readFromFile.h"
#include "vertex.h"
#include "edge.h"


int main() {
	std::cout << "airport:" << std::endl;
	std::vector<vertex> vectorRepr = read_airport("airport_sample.dat");
	for (auto word : vectorRepr) {
		std::cout << word.city + " " <<to_string(word.id) + " "<<to_string(word.lat)+ " "<< to_string(word.longt)+ " "<< std::endl;	
	}
	std::cout << "route" << std::endl;
	std::vector<edge> v = read_route("route_sample.dat");
	for (auto word : v) {
		std::cout <<to_string(word.id) + " " <<to_string(word.source)+ " "<< to_string(word.dest) + " "<< std::endl;
	}	
}
