#include <iostream>
#include <vector>
#include "readFromFile.h"
#include "graph.h"
#include "graphColoring.h"
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
	// PNG png;
	// png.readFromFile("world_map.png");
	// Graph_coloring image = Graph_coloring(png);//args

	// //new york             
	// Vertex  v1 =  Vertex(111, 40, -74, "champaign", "418"); //id, lat, long, city, ITAT code 10S, 10E
	
	// //shanghai             
	// Vertex  v2 =  Vertex(112, 31, 121, "urbana", "614"); // id, lat, long, city, ITAT code
	// pair<int, int> p1 = image.findAirportCoor(v1);
	// pair<int, int> p2 = image.findAirportCoor(v2);
	// cout<<"x: "<< p1.first<<" y: "<< p1.second<<endl;
	// cout<<"x: "<< p2.first<<" y: "<< p2.second<<endl;
	//  PNG result = image.drawAirline(png, v1, v2, 270); //hue 270 is purple
	//  result.writeToFile("output_image_test.png");
	 //
	 //
	vector<Vertex> vecOfV = read_airport("testbfs_airport.dat");
	vector<Edge> vecOfE = read_route("testbfs_route.dat");
	Graph g;
	g.build(vecOfE, vecOfV);
	// for (auto i : vecOfV) {
	// 	std::cout << g.arrOfVertices[i.id].id << endl;
	// }

	unsigned long num = 0;
	for (auto i : vecOfV ) {
		if(num<g.arrOfVertices[i.id].incid_edgs.size()){
			num=g.arrOfVertices[i.id].incid_edgs.size();
		}
	}
	cout<< "max num incid_edges: " << num << endl;


	g.BFS();
	cout<<"pass"<<endl;
	cout<<"g component have : "<<g.component<<endl;
	cout<<"get minority group by  "<< g.getExactMinorityByNum(2).size()<<endl;
}
