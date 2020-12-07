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
TEST_CASE("test build") {
    g.build(vecOfE, vecOfV);
    REQUIRE("Goroka" == g.arrOfVertices[1].city);
}
TEST_CASE("test BFS") {

}
TEST_CASE("test getAllMinorityGroups") {

}
TEST_CASE("test getExactMinorityByNum") {

}
TEST_CASE("test getExactMinorityByV") {

}


// TEST_CASE("Verify that file_to_vector works on a small example") {
// 	std::vector<std::string> res = file_to_vector("tests/smallSample.txt");
// 	std::string expected[] = {"hello", "students", "of", "cs", "225", "!!!"};
	
// 	REQUIRE(6 == res.size());

// 	for (int i = 0; i < res.size(); i++) {
// 		REQUIRE(expected[i] == res[i]);
// 	}
// }		
