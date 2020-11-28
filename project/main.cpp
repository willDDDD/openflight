#include <iostream>
#include <vector>
#include "readFromFile.h"
#include "edgeColoring.h"
#include "vertex.h"
#include "edge.h"


int main() {
	// std::cout << "airport:" << std::endl;
	// std::vector<Vertex> vectorRepr = read_airport("airport_sample.dat");
	// for (auto word : vectorRepr) {
	// 	std::cout << word.city + " " <<to_string(word.id) + " "<<to_string(word.lat)+ " "<< to_string(word.longt)+ " "<< std::endl;	
	// }
	// std::cout << "route" << std::endl;
	// std::vector<Edge> v = read_route("route_sample.dat");
	// for (auto word : v) {
	// 	//std::cout <<to_string(word.id) + " " <<to_string(word.so_)+ " "<< to_string(word.de_) + " "<< std::endl;
	// }	

	// test output image
	PNG png;
	png.readFromFile("world_map.png");
	Edge_coloring image = Edge_coloring(png);//args
	Vertex  v1 =  Vertex(111, 0, 0, "champaign", "418"); //id, lat, long, city, ITAT code
	Vertex  v2 =  Vertex(112, 2048, 1025, "urbana", "614"); // id, lat, long, city, ITAT code
	PNG result = image.drawAirline(png, v1, v2);
	result.writeToFile("output_image_test.png");

}
