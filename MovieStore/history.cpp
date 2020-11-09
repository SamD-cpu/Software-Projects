#include "history.h"

// ------------------------------------process-----------------------------------------------
// Description
// process: handes the process fo manipulation of the stock values of borrowing 
// preconditions: The valid entry for the precondition and the postcondition of the process 
// postconditions: process should define the resonsibilities of the borrowing 
// -------------------------------------------------------------------------------------------- 
void History::process(bintree movies[], hashtable& customers)
{
	Customer* customer;

	if (customers.retrieve(getID(), customer))
	{
		customerName = customer->getFirstName() + " " + customer->getLastName();

		customer->displayHistory();

	}
	else
	{
		cout << "ERROR: " << *customer << " account not found ";
	}
}

bool History::setData(ifstream& infile, char transaction)
{
	setTransaction(transaction);

	int id;
	infile >> id;
	setID(id);

	return true;
}

string History::getString() const
{
	stringstream stream;
	stream << customerName;
	stream << " transaction history.";

	return stream.str();
}
