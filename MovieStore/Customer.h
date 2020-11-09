
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <fstream>
#include <stack>
#include <queue>
#include "bintree.h"

using namespace std;

class Customer {

	friend ostream& operator<<(ostream& outStream, const Customer& customer);

private:

	int customerID = 0;
	string firstName;
	string lastName;


	stack<string> userHistory;
	queue<Movie*> movieHistory;


public:

	bool setData(ifstream& infile);
	void borrowMovie(Movie*& movie);

	bool retrieveMovieHistory(Movie*& movie, Movie*& returnMovie);
	void insert(string history);

	void displayHistory();

	int getCustomerID() const;

	string getFirstName() const;
	string getLastName() const;

};

#endif