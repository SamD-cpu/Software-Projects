#include <sstream>
#include <iostream>
#include "moviefactory.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"

// ------------------------------------createMovie----------------------------------------------- 
// Description
// createMovie:  createMovie puts in all the new movies ins into the specific cases
//avaliable for the assiciated terms for movie.
// preconditions:valid readin, valid inputs from open instream
// postconditions: inserts new movie into proper data stream for its movieType
// -----------------------------------------------------------------------------------
bool MovieFactory::createMovie(ifstream& infile, char movieType, Movie*& movie)
{
	switch (movieType) {
	case 'F': {

		movie = new Comedy(movieType);
		movie->setData(infile);
		return true;

	}
	case 'D': {

		movie = new Drama(movieType);
		movie->setData(infile);
		return true;
	}
	case 'C': {

		movie = new Classic(movieType);
		movie->setData(infile);
		return true;
	}
	default: {

		string store;
		getline(infile, store);
		return false;
	}
	}
}

// ------------------------------------createMovieTransaction----------------------------------------------- 
// Description
// createMovie:  createMovie puts in all the read ins into the specific cases
//avaliable for the assiciated terms for movie. This accounts for the transaciton readins
//in which the objective of the transaction read ins
// preconditions:valid readin, valid inputs from open instream
// postconditions: inserts new movie into proper data stream for its movieType
// -----------------------------------------------------------------------------------
Movie* MovieFactory::createMovieTransaction(char movieType, ifstream& infile)
{
	string store;
	Movie* movie = nullptr;

	switch (movieType) {
	case 'D': {

		movie = new Drama(movieType);

		getline(infile, store, ',');
		Movie::reduce(store);
		movie->setDirector(store);

		getline(infile, store, ',');
		Movie::reduce(store);

		movie->setTitle(store);

		return movie;
	}
	case 'F': {

		movie = new Comedy(movieType);

		getline(infile, store, ',');
		Movie::reduce(store);

		movie->setTitle(store);

		infile >> store;
		movie->setYear(stoi(store));

		return movie;
	}
	case 'C': {//accounts for the differnces in param types

		movie = new Classic(movieType);

		infile >> store;
		Movie::reduce(store);

		movie->setMonth(stoi(store));

		infile >> store;
		Movie::reduce(store);

		movie->setYear(stoi(store));

		getline(infile, store);
		Movie::reduce(store);

		movie->setMajorActor(store);

		return movie;
	}
	default: {

		stringstream stream;
		stream << "ERROR: '" << movieType << "' non-valid movieType " << endl;
		cout << stream.str();
		return movie;
	}
	}
}



