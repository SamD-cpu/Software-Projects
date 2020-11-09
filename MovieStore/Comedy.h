#ifndef COMEDY_H
#define COMEDY_H

#include "Movie.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Comedy : public Movie {

public:

	void displayType(ostream& outStream) const;

	Comedy(char movieType);

	void setData(ifstream& infile);

	bool operator==(const Movie&);
	bool operator!=(const Movie&);
	bool operator<(const Movie&);
	bool operator>(const Movie&);
};

#endif