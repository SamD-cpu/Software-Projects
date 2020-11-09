#include "return.h"
// ------------------------------------process-----------------------------------------------
// Description
// process: handes the process fo manipulation of the stock values of return 
// preconditions: The valid entry for the precondition and the postcondition of the process 
// postconditions: process should define the resonsibilities of the borrowing 
// -------------------------------------------------------------------------------------------- 
void Return::process(bintree movies[], hashtable& customers)
{
	Movie* stock;
	Customer* customer;
	Movie* movie = getMovie();
	char genre = movie->getMovieType();

	if (customers.retrieve(getID(), customer))
	{
		if (customer->retrieveMovieHistory(movie, stock))
		{
			Movie* retrieval;
			if (movies[genre - 'A'].retrieve(stock, retrieval))
			{
				movies[genre - 'A'].insert(stock);
				movieTitle = retrieval->getTitle();

				customer->insert(getString());
			}
			else
			{
				cout << "ERROR:  " << *movie << "  doesn't exist" << endl;
			}
		}
		else
		{

			cout << "ERROR: " << *customer << " not checked out " << *movie << endl;
		}
	}
	else
	{
		cout << "ERROR: " << getID() << " non-valid user";
	}
}

// ------------------------------------setData----------------------------------------------- 
// Description
// sets the data that are assicoated with the pass in
// preconditions: must be of acessible & valid input of file read in
// postconditions: reads in the data from the ReadTransaction call line
// -------------------------------------------------------------------------------------------- 
bool Return::setData(ifstream& infile, char transaction)
{
	setTransaction(transaction);

	int id;
	infile >> id;
	setID(id);

	char item;
	infile >> item;
	setItem(item);

	if (item != 'D') {
		cout << "ERROR: '" << item << "' is not a currently allowed movie "
			"item" << endl;

		return false;
	}
	char movieType;
	infile >> movieType;

	Movie* movie = factM.createMovieTransaction(movieType, infile);
	setMovie(movie);
	return (movie != nullptr);
}

// ------------------------------------getString----------------------------------------------- 
// Description
// get the data that should be passed in for the borrowing behaviors of the customer
// preconditions: 
// postconditions: collects the customers movie
// -------------------------------------------------------------------------------------------- 
string Return::getString() const
{
	return "returned: " + movieTitle + ".";
}
