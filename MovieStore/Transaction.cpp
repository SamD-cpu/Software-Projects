#include "Transaction.h"

//destructor
// cl
Transaction::~Transaction()
{
	if (movie != nullptr)
		delete movie;

}

//get the id of customer
int Transaction::getID() const
{
	return id;
}

//set id for customer
void Transaction::setID(int userID)
{
	this->id = userID;
}

//get the transaction by specific customer
char Transaction::getTransaction() const
{
	return transaction;
}

//sets the transaction type
void Transaction::setTransaction(char transactionType)
{
	this->transaction = transactionType;
}


char Transaction::getItem() const
{
	return item;

}

void Transaction::setItem(char item)
{
	this->item = item;
}

Movie* Transaction::getMovie() const
{
	return movie;
}

//
void Transaction::setMovie(Movie* movie)
{
	this->movie = movie;
}

