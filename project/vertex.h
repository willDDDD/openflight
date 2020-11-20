#pragma once
#include <string>
using namespace std;

class vertex {
    public:
     vertex(int a, double b, double c, string d, string e);     
     int id; //Unique OpenFlights identifier for this airport.
     double lat;//	Decimal degrees, usually to six significant digits. Negative is South, positive is North.
     double longt;//Decimal degrees, usually to six significant digits. Negative is West, positive is East.
     string city;//Main city served by airport. May be spelled differently from Name.
     string IATA;//3-letter IATA code. Null if not assigned/unknown.
};