
#ifndef BORROW_H
#define BORROW_H
using namespace std;
#include "Transaction.h"
#include "Movie.h"
#include "moviefactory.h"
class Borrow : public Transaction
{
public:

	void process(bintree movies[], hashtable& customers);
	bool setData(ifstream& infile, char transaction);
	string getString() const;

private:
	string movieTitle;

	MovieFactory factM;

};

#endif /* borrow_h */
