#include "Store.h"

void Store::readMovies(ifstream& infile)
{
	if (!infile) {
		cout << "ERROR: File Not Found" << endl;
		exit(-1);
	}
	char movieType;
	string inMovieType;

	getline(infile, inMovieType, ',');
	movieType = inMovieType[0];

	while (!infile.eof())
	{
		Movie* temp = nullptr;
		if (movieFactory.createMovie(infile, movieType, temp))
		{
			movies[movieType - 'A'].insert(temp);
		}
		else
		{
			stringstream stream;
			stream << "ERROR: '" << movieType << "' non-valid movieType" << endl;
			cout << stream.str();
		}
		getline(infile, inMovieType, ',');
		movieType = inMovieType[0];

		if (infile.eof()) break;
	}
	infile.close();

}

void Store::readTransaction(ifstream& infile)
{
	if (!infile) {
		cout << "ERROR: File Not Found." << endl;
		exit(-1);
	}

	transactions.build(infile);
	infile.close();
}

void Store::readCustomer(ifstream& infile)
{
	if (!infile) {
		cout << "ERROR: File Not Found" << endl;
		exit(-1);
	}

	customers.build(infile);
	infile.close();
}

void Store::doTransactions()
{
	while (!transactions.isEmpty())
	{
		Transaction* transaction;
		transaction = transactions.pop();
		transaction->process(movies, customers);
	}
}



