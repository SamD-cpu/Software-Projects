#ifndef HISTORY_H
#define HISTORY_H

#include "Transaction.h"
#include "Movie.h"
#include "Customer.h"
#include "moviefactory.h"
#include <stdio.h>
#include "bintree.h"
#include "hashtable.h"
class History : public Transaction
{
private:
	string customerName;

public:

	void process(bintree movies[], hashtable& customers);
	bool setData(ifstream& infile, char transaction);
	string getString() const;
};
#endif /* history_h */
