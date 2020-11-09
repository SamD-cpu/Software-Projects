#ifndef VIEW_H
#define VIEW_H
#include "Transaction.h"
#include "bintree.h"
class view : public Transaction
{
	const string genre[3]
	{
		"Comedy",
		"Drama",
		"Classic"
	};
	const char movieType[3]
	{
		'F',
		'D',
		'C'
	};
public:


	void process(bintree movies[], hashtable& customers);
	bool setData(ifstream& infile, char transaction);

	string getString() const;

};

#endif