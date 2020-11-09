#include <iostream>
#include "transactionfactory.h"
#include "view.h"
#include "borrow.h"
#include "return.h"
#include "history.h"
// ------------------------------------createTransaction----------------------------------------------- 
// Description
// createMovie:  createTransaction puts in all the transactions into the specific cases
//avaliable for the assiciated terms for movie.
// preconditions:valid readin, valid inputs from open instream
// postconditions: handles call in for the type of transaction that is associated with
//transaction type read in by the files
// -----------------------------------------------------------------------------------
bool transactionfactory::createTransaction(char transactionType, Transaction*& transaction, ifstream& infile)
{
	bool check;

	switch (transactionType) {
	case 'I': {

		transaction = new view();
		check = transaction->setData(infile, transactionType);
		return check;

	}
	case 'B': {
		transaction = new Borrow();
		check = transaction->setData(infile, transactionType);
		return check;
	}
	case 'R': {
		transaction = new Return();
		check = transaction->setData(infile, transactionType);
		return check;
	}
	case 'H': {

		transaction = new History();
		check = transaction->setData(infile, transactionType);
		return check;
	}
	default: {

		stringstream stream;
		stream << "ERROR: '" << transactionType << "' is non-valid transactionType" << endl;
		cout << stream.str();

		return false;

	}
	}
}

