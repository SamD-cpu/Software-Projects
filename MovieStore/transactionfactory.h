#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H
#include <fstream>
#include "Transaction.h"
using namespace std;

class transactionfactory
{
public:
	bool createTransaction(char transactionType, Transaction*& transaction, ifstream& infile);
};
#endif