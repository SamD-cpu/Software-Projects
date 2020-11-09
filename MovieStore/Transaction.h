#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "bintree.h"
#include "hashtable.h"


using namespace std;

class Transaction {

private:

	int id;

	char transaction;
	char item;
	char movieType;

	Movie* movie;

public:

	~Transaction();

	virtual void process(bintree movies[], hashtable& customers) = 0;
	virtual bool setData(ifstream& infile, char transactionType) = 0;
	virtual string getString() const = 0;

	int getID() const;
	void setID(int userID);

	char getTransaction() const;
	void setTransaction(char transactionType);

	char getItem() const;
	void setItem(char item);

	Movie* getMovie() const;
	void setMovie(Movie* movie);
};

#endif