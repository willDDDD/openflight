#include <string>
#include <vector>
#include "../catch/catch.hpp"
#include "../readFromFile.cpp"
#include "../graph.h"
#include "../graphDrawing.h"
#include "../vertex.h"
#include "../edge.h"
#include "../priorityQueue.h"



TEST_CASE("readFromFile: test read_airport on the sample") {
	vector<Vertex> res = read_airport("airport_sample.dat");
	// always check "expected" == "actual" --> be consistent
	REQUIRE(1 == res[0].id);
}
TEST_CASE("readFromFile: test read_airline on the sample") {
	vector<Edge> res = read_route("route_sample.dat");
	// always check "expected" == "actual" --> be consistent
	REQUIRE(16624 == res[0].id);
}
TEST_CASE("readFromFile: test split_vertex") {
	ifstream wordsFile("airport_sample.dat");
    string line;
    getline(wordsFile, line);
    string s = line;
    REQUIRE(1 == split_vertex(s).id);
}
TEST_CASE("readFromFile: test split_route") {
    ifstream wordsFile("route_sample.dat");
    string line;
    getline(wordsFile, line);
    string s = line;
    REQUIRE(16624 == split_edge(s).id);
}


vector<Vertex> vecOfV = read_airport("airport.dat");
vector<Edge> vecOfE = read_route("route.dat");
Graph g;
TEST_CASE("Graph: test build") {
    g.build(vecOfE, vecOfV);
    REQUIRE("Goroka" == g.arrOfVertices[1].city);
}
TEST_CASE("Graph: test BFS by counting component") {
    g.BFS();
    REQUIRE(4567 == g.component);
}
TEST_CASE("Graph: test getAllMinorityGroups") {
    g.BFS();
    REQUIRE(9132 == g.getAllMinorityGroups().size());
}
TEST_CASE("Graph: test getExactMinorityByNum") {
    g.BFS();
    REQUIRE(6 == g.getExactMinorityByNum(2).size());
}
TEST_CASE("Graph: test getExactMinorityByV") {
    g.BFS();
    REQUIRE(1 == g.getExactMinorityByV(vecOfV[0]).size());
}
/*
TEST_CASE("Graph drawing: test findAirportCoor") {
    PNG png;
    png.readFromFile("world_map.png");
    Graph_coloring image = Graph_coloring(png);//args


    Vertex  v1 =  Vertex(111, 50, 100, "city 1", "abc"); //id, lat, long, city, ITAT code 10S, 10E             
    Vertex  v2 =  Vertex(112, -50, -100,"city 2", "xyz"); // id, lat, long, city, ITAT code

    pair<int, int> p1 = image.findAirportCoor(v1);
    REQUIRE(100 == p1.first);
    REQUIRE(100 == p1.second);

    pair<int, int> p2 = image.findAirportCoor(v2);
    REQUIRE(100 == p2.first);
    REQUIRE(100 == p2.second);

    image.drawAirport(png,v1,0.5);
    REQUIRE(0.5 == png.getPixel(100,200).l);

    image.drawAirport(png,v2,0.5);
    REQUIRE(0.5 == png.getPixel(100,200).l);
    image.drawAirline(png, v1, v2, 270); //hue 270 is purple
    REQUIRE(0.5 == png.getPixel(100,200).l);
}
*/

TEST_CASE("test Shortest Path") {
	
    Vertex source1(3797, 31.780000686645508,117.2979965209961, "Shanghai", "HQ");
	Vertex target1(3484, 33.94250107, -118.4079971, "Los Angeles", "LAX");
	vector<int> FromJFKToLAX = g.shortestPath(source1, target1);
	REQUIRE(1 == FromJFKToLAX.size());
}


// TEST_CASE("Verify that file_to_vector works on a small example") {
// 	std::vector<std::string> res = file_to_vector("tests/smallSample.txt");
// 	std::string expected[] = {"hello", "students", "of", "cs", "225", "!!!"};
	
// 	REQUIRE(6 == res.size());

// 	for (int i = 0; i < res.size(); i++) {
// 		REQUIRE(expected[i] == res[i]);
// 	}
// }		
