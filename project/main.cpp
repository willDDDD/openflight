#include <iostream>
#include <vector>
#include "readFromFile.h"
#include "graph.h"
#include "graphDrawing.h"
#include "vertex.h"
#include "edge.h"

int main()
{	
	//readFromFile small database
	Graph g_small;	
	vector<Vertex> vecOfV_small = read_airport("testbfs_airport.dat");
	vector<Edge> vecOfE_small = read_route("testbfs_route.dat");
	// bulid graph and BFS
	g_small.build(vecOfE_small, vecOfV_small);
	g_small.BFS();
	cout << "g_samll.getNumberOfVTraversed(): "<< g_small.getNumberOfVTraversed() << endl;
	// readFromFile original database
	vector<Vertex> vecOfV = read_airport("airport.dat");
	vector<Edge> vecOfE = read_route("route.dat");
	//build graph and BFS
	Graph g;
	g.build(vecOfE, vecOfV);
	g.BFS();
	cout <<"g.getNumberOfVTraversed(): " << g.getNumberOfVTraversed() << endl;
	// create graphDrawing
	PNG draw_all_airports;
	PNG draw_all_airlines;
	PNG draw_shortest_path;
	draw_all_airports.readFromFile("world_map.png");
	draw_all_airlines.readFromFile("world_map.png");
	draw_shortest_path.readFromFile("world_map.png");
	Graph_drawing ap = Graph_drawing(draw_all_airports);
	Graph_drawing al = Graph_drawing(draw_all_airlines);
	Graph_drawing sp = Graph_drawing(draw_shortest_path);
	

	//BFS
	cout<<"components: "<<g.component<<endl;
	cout<<"getAllMinorityGroups: "<< g.getAllMinorityGroups().size() <<endl;
	cout<<"getExactMinorityByNum(1): "<< g.getExactMinorityByNum(1).size() <<endl;
	//Shortest Path
	/*
	6341,"Beijing Nanyuan Airport","Beijing","China","NAY","ZBNY",39.782798767089844,116.38800048828125,0,8,"U","Asia/Shanghai","airport","OurAirports"
	6466,"Donskoye Airport","Tambow","Russia","TBW","UUOT",52.806098937988,41.482799530029,413,3,"N","Europe/Moscow","airport","OurAirports"
	6048,"Port Stanley Airport","Stanley","Falkland Islands","PSY","SFAL",-51.685699462891,-57.777599334717,75,-3,"U","Atlantic/Stanley","airport","OurAirports"
	6985,"Nelspruit Airport","Nelspruit","South Africa","NLP","FANS",-25.5,30.9137992859,2875,2,"U","Africa/Johannesburg","airport","OurAirports"
	3830,"Chicago O'Hare International Airport","Chicago","United States","ORD","KORD",41.9786,-87.9048,672,-6,"A","America/Chicago","airport","OurAirports"
	813,"OR Tambo International Airport","Johannesburg","South Africa","JNB","FAOR",-26.1392,28.246,5558,2,"U","Africa/Johannesburg","airport","OurAirports"
	2654,"María Dolores Airport","Los Angeles","Chile","LSQ","SCGE",-37.40169906616211,-72.42539978027344,374,-4,"S","America/Santiago","airport","OurAirports"
	3484,"Los Angeles International Airport","Los Angeles","United States","LAX","KLAX",33.94250107,-118.4079971,125,-8,"A","America/Los_Angeles","airport","OurAirports"
	3374,"Shenzhen Bao'an International Airport","Shenzhen","China","SZX","ZGSZ",22.639299392700195,113.81099700927734,13,8,"U","Asia/Shanghai","airport","OurAirports"
	2564,"Guarulhos - Governador André Franco Montoro International Airport","Sao Paulo","Brazil","GRU","SBGR",-23.435556411743164,-46.47305679321289,2459,-3,"S","America/Sao_Paulo","airport","OurAirports"


	*/
	Vertex source(3374, 22.639299392700195,113.81099700927734, "Shenzhen", "SZX");
    Vertex target(2564, -23.435556411743164,-46.47305679321289, "Sao Paulo", "GRU");
	vector<Vertex> temp = g.getExactMinorityByV(target);
	vector<int> route = g.shortestPath(source, target);
	for (size_t i = 0; i < route.size();i++) {
		std::cout << g.arrOfVertices[route[i]].city<< std::endl;
		if (i+1 < route.size()) {
			// draw shortest path
			sp.drawAirline(draw_shortest_path, g.arrOfVertices[route[i]], g.arrOfVertices[route[i+1]], 270);
		}
	}
	draw_shortest_path.writeToFile("draw_shortest_path.png");

	// for (Vertex v: vecOfV) {
	// 	// draw all airports
	// 	ap.drawAirport(draw_all_airports, g.arrOfVertices[v.id]);
	// }
	// draw_all_airports.writeToFile("output_image_test.png");

	for (Edge e: vecOfE) {
		// draw all airlines
		al.drawAirline(draw_all_airlines, g.arrOfVertices[e.source], g.arrOfVertices[e.dest], 270);
	}
	draw_all_airlines.writeToFile("draw_all_airlines.png");
}
