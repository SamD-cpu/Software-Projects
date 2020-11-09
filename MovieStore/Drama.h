#ifndef Drama_h
#define Drama_h

#include "Movie.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Drama : public Movie
{
public:

	void displayType(ostream& outStream) const;

	Drama(char movieType);

	virtual void setData(ifstream&);

	bool operator==(const Movie&);
	bool operator!=(const Movie&);
	bool operator<(const Movie&);
	bool operator>(const Movie&);
private:

	char movieType;//the type of the movie

};

#endif /* Drama_h */