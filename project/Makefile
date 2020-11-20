EXENAME = main

CXX = clang++
CXXFLAGS = -std=c++0x -g -O0 -Wall -Wextra

all : $(EXENAME)

$(EXENAME): vertex.cpp edge.cpp main.cpp
	$(CXX) $(CXXFLAGS) vertex.cpp edge.cpp main.cpp -o $(EXENAME)

.PHONY: clean
clean:
	rm -f $(EXENAME)