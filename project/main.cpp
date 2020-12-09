#include <iostream>
#include <vector>
#include "readFromFile.h"
#include "graph.h"
#include "graphDrawing.h"
#include "vertex.h"
#include "edge.h"

int main()
{
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

	//test output image
	PNG png;
	png.readFromFile("world_map.png");
	Graph_coloring image = Graph_coloring(png);//args
	vector<Vertex> vecOfV = read_airport("airport.dat");
	vector<Edge> vecOfE = read_route("route.dat");
	Graph g;
	g.build(vecOfE, vecOfV);

	// for (auto e : vecOfE) {
	// 	Vertex dest = g.arrOfVertices[e.dest];
	// 	Vertex source = g.arrOfVertices[e.source];
	// 	image.drawAirline(png, source, dest, 270);
	// }

	
	//new york             
	// Vertex  v1 =  Vertex(111, 34, -118, "LA", "418"); //id, lat, long, city, ITAT code 10S, 10E             
	// Vertex  v2 =  Vertex(112, 18, 72,"MM", "614"); // id, lat, long, city, ITAT code
	// Vertex  v3 =  Vertex(112, 50, -150,"shanghai", "614"); // id, lat, long, city, ITAT code
	// Vertex  v4 =  Vertex(112, 0, 150,"shanghai", "614"); // id, lat, long, city, ITAT code
	// pair<int, int> p1 = image.findAirportCoor(v1);
	// pair<int, int> p2 = image.findAirportCoor(v2);
	// cout<<"x: "<< p1.first<<" y: "<< p1.second<<endl;
	// cout<<"x: "<< p2.first<<" y: "<< p2.second<<endl;
	// image.drawAirport(png,v1,0.5);
	// image.drawAirport(png,v2,0.5);
	// image.drawAirline(png, v1, v2, 270); //hue 270 is purple
	

	// png.writeToFile("output_image_test.png");
	
	// test priority queue
	// vector<Vertex> vec_of_ver_test;
	// Vertex firstV(1, -10, -10, "fc", "FIR");
	// vec_of_ver_test.push_back(firstV);
	// Vertex secondV(2, -10, 50, "sc", "SEC");
	// vec_of_ver_test.push_back(secondV);
	// Vertex thirdV(3, 50, 50, "thirdc", "THD");
	// vec_of_ver_test.push_back(thirdV);
	// Vertex fourthV(4, 50, -10, "fourthC", "FTH");
	// vec_of_ver_test.push_back(fourthV);
	// Vertex fifthV(5, 50, -10, "fourthC", "FTH");
	// vec_of_ver_test.push_back(fifthV);
	// Vertex sixthV(6, 50, -10, "fourthC", "FTH");
	// vec_of_ver_test.push_back(sixthV);
	// Vertex seventhV(7, 50, -10, "fourthC", "FTH");
	// vec_of_ver_test.push_back(seventhV);
	// Vertex eighthV(8, 50, -10, "fourthC", "FTH");
	// vec_of_ver_test.push_back(eighthV);
	// Vertex ninethV(9, 50, -10, "fourthC", "FTH");
	// vec_of_ver_test.push_back(ninethV);
	// Vertex tenthV(10, 50, -10, "fourthC", "FTH");
	// vec_of_ver_test.push_back(tenthV);
	// map<int, int> dist_map_test;
	// dist_map_test[firstV.id] = 0;
	// dist_map_test[secondV.id] = -60;
	// dist_map_test[thirdV.id] = 50;
	// dist_map_test[fourthV.id] = -60;
	// dist_map_test[fifthV.id] = 40;
	// dist_map_test[sixthV.id] = 20;
	// dist_map_test[seventhV.id] = 30;
	// dist_map_test[eighthV.id] = -30;
	// dist_map_test[ninethV.id] = -5;
	// dist_map_test[tenthV.id] = 15;

	// priorityQueue pq_test(vec_of_ver_test, dist_map_test);
	// pq_test.printElements();
	// std::cout << "----------------------" << endl;
	// pq_test.updateDistance(dist_map_test, 2, 3);
	// pq_test.printElements();
	

	// test shortest path
	Vertex source(3374, 31.780000686645508,117.2979965209961, "Baoan", "SZX");
	Vertex target(3830, 33.94250107, -118.4079971, "Chicago", "GRUSP");
	vector<int> FromJFKToLAX = g.shortestPath(source, target);
	for (size_t i = 0; i < FromJFKToLAX.size();i++) {
		std::cout << FromJFKToLAX[i] << std::endl;
		if (i+1 < FromJFKToLAX.size()) {
			image.drawAirline(png, g.arrOfVertices[FromJFKToLAX[i]], g.arrOfVertices[FromJFKToLAX[i+1]], 270);
		}
	}
	png.writeToFile("output_image_test.png");
	

	// vector<Vertex> vecOfV = read_airport("airport.dat");
	// vector<Edge> vecOfE = read_route("route.dat");
	// Graph g;
	// g.build(vecOfE, vecOfV);
	// // for (auto i : vecOfV) {
	// // 	std::cout << g.arrOfVertices[i.id].id << endl;
	// // }

	// unsigned long num = 0;
	// for (auto i : vecOfV ) {
	// 	if(num<g.arrOfVertices[i.id].incid_edgs.size()){
	// 		num=g.arrOfVertices[i.id].incid_edgs.size();
	// 	}
	// }
	// cout<< "max num incid_edges: " << num << endl;

	// g.BFS();
	// cout<<"pass"<<endl;
	// cout<<"g component have : "<<g.component<<endl;
	// cout<<"get minority group by  "<< g.getExactMinorityByNum(2).size()<<endl;
}
