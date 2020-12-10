#include <string>
#include <vector>
#include "../HSLA/HSLAPixel.h"
#include "../HSLA/PNG.h"
#include "../HSLA/lodepng/lodepng.h"
#include "../catch/catch.hpp"
#include "../readFromFile.cpp"
#include "../graph.h"
#include "../graphDrawing.h"
#include "../vertex.h"
#include "../edge.h"
#include "../priorityQueue.h"

using namespace cs225;
using namespace std;

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
// g.BFS();
// g.build(vecOfE, vecOfV);
TEST_CASE("Graph: test build") {
    g.build(vecOfE, vecOfV);
    REQUIRE("Goroka" == g.arrOfVertices[1].city);
}
TEST_CASE("Graph: test BFS by counting component") {
    //g.build(vecOfE, vecOfV);
    g.BFS();
    REQUIRE(4567 == g.component);
}
TEST_CASE("Graph: test getAllMinorityGroups") {
    //g.build(vecOfE, vecOfV);
    g.BFS();
    REQUIRE(9132 == g.getAllMinorityGroups().size());
}
TEST_CASE("Graph: test getExactMinorityByNum") {
    //g.build(vecOfE, vecOfV);
    g.BFS();
    REQUIRE(6 == g.getExactMinorityByNum(2).size());
}
TEST_CASE("Graph: test getExactMinorityByV") {
    //g.build(vecOfE, vecOfV);
    g.BFS();
    REQUIRE(0 == g.getExactMinorityByV(g.arrOfVertices[1]).size());
}
TEST_CASE("Graph: test Shortest Path 1") {
    //6341,"Beijing Nanyuan Airport","Beijing","China","NAY","ZBNY",39.782798767089844,116.38800048828125,0,8,"U","Asia/Shanghai","airport","OurAirports"
    //3830,"Chicago O'Hare International Airport","Chicago","United States","ORD","KORD",41.9786,-87.9048,672,-6,"A","America/Chicago","airport","OurAirports"
    //g.build(vecOfE, vecOfV);
    Vertex source(6341, 39.782798767089844,116.38800048828125, "Beijing", "NAY");
    Vertex target(3830, 41.9786,-87.9048, "Chicago", "ORD");
    vector<int> path = g.shortestPath(source, target);
    REQUIRE("Beijing" == g.arrOfVertices[path[0]].city);
    REQUIRE("Datong" == g.arrOfVertices[path[1]].city);
    REQUIRE("Beijing" == g.arrOfVertices[path[2]].city);
    REQUIRE("Chicago" == g.arrOfVertices[path[3]].city);
}
TEST_CASE("Graph: test Shortest Path 2") {
	// There exist a direct airline between JFK and LAX, so the size of the vector equals 2 (source airport and destination airport)
    Vertex source1(3797, 40.63980103, -73.77890015, "New York", "JFK");
	Vertex target1(3484, 33.94250107, -118.4079971, "Los Angeles", "LAX");
    g.build(vecOfE, vecOfV);
	vector<int> FromJFKToLAX = g.shortestPath(source1, target1);
    REQUIRE("New York" == g.arrOfVertices[FromJFKToLAX[0]].city);
    REQUIRE("Los Angeles" == g.arrOfVertices[FromJFKToLAX[1]].city);
	REQUIRE(2 == FromJFKToLAX.size());
}
