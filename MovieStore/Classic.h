
#include "Movie.h"
#include <fstream>
#include <iostream>
#include <string>
#ifndef CLASSIC_H
#define CLASSIC_H

using namespace std;

class Classic : public Movie {

public:

	void displayType(ostream&) const;

	Classic(char);

	void setData(ifstream&);

	bool operator==(const Movie&);
	bool operator!=(const Movie&);
	bool operator<(const Movie&);
	bool operator>(const Movie&);

	Movie& operator=(Movie&);
};

#endif