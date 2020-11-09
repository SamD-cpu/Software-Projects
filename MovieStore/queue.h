#ifndef QUEUE_H
#define QUEUE_H

#include "Transaction.h"
#include "transactionfactory.h"
#include <fstream>

using namespace std;

class Queue {

	struct Node {
		Transaction* data;
		Node* next;

		Node(Transaction* data, Node* next) : data(data), next(next) {}

		Node() {
			next = nullptr;
		}
	};

private:
	transactionfactory transactionFactory;

	Node* head = nullptr;

public:

	~Queue();

	void push(Transaction* transaction);
	Transaction* pop();
	bool isEmpty();
	void build(ifstream& infile);
};

#endif