#include <iostream>
#include <vector>
#include "readFromFile.hpp"

int main(int argc, const char * argv[]) {
	std::cout << "Filename: " << "airport_sample.dat" << std::endl;
	
	// convert file to string representation
	std::cout << "String Representation:" << std::endl;
	std::cout << file_to_string("airport_sample.dat") << std::endl;
	
	// convert file to vector representation
	std::cout << "Vector Representation:" << std::endl;
	std::vector<std::string> vectorRepr = file_to_vector("airport_sample.dat");
	for (auto word : vectorRepr) {
		std::cout << word << std::endl;
	}	
}
