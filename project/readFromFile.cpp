#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "readFromFile.h"
vector<Vertex> read_airport(const string &filename)
{
	vector<Vertex> ret;
	ifstream wordsFile(filename);
	string line;
	if (wordsFile.is_open())
	{
		/* Reads a line from `wordsFile` into `word` until the file ends. */
		while (getline(wordsFile, line))
		{
			string s = line;
			ret.push_back(split_vertex(s));
		}
	}
	return ret;
}

vector<Edge> read_route(const string &filename)
{
	vector<Edge> ret;
	ifstream wordsFile(filename);
	string line;
	if (wordsFile.is_open())
	{
		/* Reads a line from `wordsFile` into `word` until the file ends. */
		while (getline(wordsFile, line))
		{
			string s = line;
			ret.push_back(split_edge(s));
		}
	}
	return ret;
}

Vertex split_vertex(string input)
{
	int first = input.find(',');
	string id = input.substr(0, first);
	input = input.substr(first + 1);
	int d1 = input.find(',');
	input = input.substr(d1 + 2);
	int second = input.find(',');
	string city = input.substr(0, second - 1);
	input = input.substr(second + 1);
	int d2 = input.find(',');
	input = input.substr(d2 + 2);
	int third = input.find(',');
	string IATA = input.substr(0, third - 1);
	input = input.substr(third + 1);
	int d3 = input.find(',');
	input = input.substr(d3 + 1);
	int fourth = input.find(',');
	string lat = input.substr(0, fourth);
	input = input.substr(fourth + 1);
	int fifth = input.find(',');
	string longt = input.substr(0, fifth);
	int id_ = atoi(id.c_str());
	double lat_ = atof(lat.c_str());
	double longt_ = atof(longt.c_str());
	return Vertex(id_, lat_, longt_, city, IATA);
}
Edge split_edge(string input) {
	int d1 = input.find(',');
	input = input.substr(d1+1);
	int first = input.find(',');
	string id = input.substr(0, first);
	input = input.substr(first+1);
	int d2 = input.find(',');
	input = input.substr(d2+1);
	int second = input.find(',');
	string source = input.substr(0,second);
	input = input.substr(second+1);
	int d3 = input.find(',');
	input = input.substr(d3+1);
	int third = input.find(',');
	string dest = input.substr(0,third);
	int id_ = (id == "NA") ? -1 : atoi(id.c_str());
	int source_ = (source == "NA") ? -1 : atoi(source.c_str());
	int dest_= (dest == "NA") ? -1 : atoi(dest.c_str());
	return Edge(id_,source_,dest_);
}