#include "bintree.h"
#include "moviefactory.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"
#include "hashtable.h"
#include "Transaction.h"
#include "queue.h"
#include "queue.h"
using namespace std;
class Store
{
private:
	Queue transactions;
	hashtable customers;

	MovieFactory movieFactory;
	bintree movies[26];

public:
	void readCustomer(ifstream& infile);
	void readMovies(ifstream& infile);
	void readTransaction(ifstream& infile);
	void doTransactions();

};

