#include <iostream>
#include <fstream>
#include "Store.h"

using namespace std;

int main() {


	Store store;

	ifstream customersFile("data4customers.txt");
	ifstream moviesFile("data4movies.txt");
	ifstream transactionsFile("data4commands.txt");

	store.readCustomer(customersFile);
	store.readMovies(moviesFile);
	store.readTransaction(transactionsFile);

	store.doTransactions();

	return 0;

};