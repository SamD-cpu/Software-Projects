#ifndef RETURN_H
#define RETURN_H
#include "Transaction.h"
#include "Movie.h"
#include "moviefactory.h"
using namespace std;

class Return : public Transaction
{
public:

	void process(bintree movies[], hashtable& customers);
	virtual bool setData(ifstream& infile, char transaction);
	string getString() const;

private:
	string movieTitle;

	MovieFactory factM;
};
#endif /* Return_h */
