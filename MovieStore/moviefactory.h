#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include "Movie.h"
using namespace std;

class MovieFactory {

public:
	//factory method for Movie
	bool createMovie(ifstream& infile, char movieType, Movie*& movie);
	//factory method for shorthand Movie
	Movie* createMovieTransaction(char movieType, ifstream& infile);

};


#endif