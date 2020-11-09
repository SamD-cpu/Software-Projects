#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Customer.h"

using namespace std;

class hashtable {


	struct Node {

		Customer* data;
		Node* next;

		Node(Customer* data, Node* next) :
			data(data), next(next) {};
	};

private:
	Node* container[102];//prime hashing numbers

public:
	hashtable();
	~hashtable();
	bool retrieve(int id, Customer*& customer);
	void insert(Customer* customer);
	void build(ifstream& infile);

private:
	int hash(int id);
};
#endif