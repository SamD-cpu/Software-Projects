#include "borrow.h"

// ------------------------------------process-----------------------------------------------
// Description
// process: handes the process fo manipulation of the stock values of borrowing 
// preconditions: The valid entry for the precondition and the postcondition of the process 
// postconditions: process should define the resonsibilities of the borrowing 
// -------------------------------------------------------------------------------------------- 
void Borrow::process(bintree movies[], hashtable& customers)
{
	Movie* stockedMovie;
	Customer* customer;
	Movie* movie = getMovie();
	char genre = movie->getMovieType();

	if (customers.retrieve(getID(), customer)) {

		if (movies[genre - 'A'].retrieve(movie, stockedMovie)) {

			if (stockedMovie->getStock() > 0) {

				customer->borrowMovie(movie);
				stockedMovie->setStock(stockedMovie->getStock() - 1);//decrements the stock count

				movieTitle = stockedMovie->getTitle();

				customer->insert(getString());//customer history
			}
			else {

				cout << "ERROR: " << "no copies " << stockedMovie->getTitle() << endl;
			}
		}
		else {

			cout << "ERROR: " << *movie << " out of stock" << endl;
		}
	}
	else {

		cout << "ERROR: " << getID() << " is non-valid" << endl;
	}
}
// ------------------------------------setData----------------------------------------------- 
// Description
// sets the data that are assicoated with the pass in
// preconditions: must be of acessible & valid input of file read in
// postconditions: reads in the data from the ReadTransaction call line
// -------------------------------------------------------------------------------------------- 
bool Borrow::setData(ifstream& infile, char transaction)
{
	int id;
	infile >> id;
	setID(id);

	char item;
	infile >> item;
	setItem(item);

	if (item != 'D')
	{
		cout << "ERROR: '" << item << "' is not a distro type " << endl;
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
string Borrow::getString() const
{
	return "borrowed: " + movieTitle + ".";
}
