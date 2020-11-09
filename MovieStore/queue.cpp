#include <sstream>
#include <iostream>
#include "queue.h"

// ------------------------------------Deconstructor---------------------------------------------- -
// Description
// Deconstructor: De-allocates the queue stored
// are associated within the data set of transaction readins
// preconditions:  not point to Null value 
// postconditions: deallocation of memory
// -------------------------------------------------------------------------------------------- 
Queue::~Queue() {

	Node* store;

	while (head != nullptr)
	{
		store = head;
		head = head->next;
		delete store->data;
		store->data = nullptr;
		delete store;
	}
	head = nullptr;
}


// ------------------------------------push---------------------------------------------- -
// Description
// First In First Out implemtation of enqueue, eter queue
// preconditions:  not point to Null value 
// postconditions: Item is added to the rear of the queue
// -------------------------------------------------------------------------------------------- 
void Queue::push(Transaction* transaction)
{
	if (head == nullptr)
	{
		head = new Node(transaction, nullptr);
	}
	else
	{
		Node* cNode = head;

		while (cNode->next != nullptr)
		{
			cNode = cNode->next;
		}
		cNode->next = new Node(transaction, nullptr);
	}
}
// ------------------------------------pop---------------------------------------------- -
// Description
// First In First Out implemtation of enqueue, exit queue
// preconditions:  not point to Null value 
// postconditions: Front item is removed from the queue
// -------------------------------------------------------------------------------------------- 
Transaction* Queue::pop()
{
	Node* store = head;
	Transaction* transaction = nullptr;

	if (head != nullptr)
	{
		transaction = head->data;
		head = head->next;
		delete store;

	}

	return transaction;
}
// ------------------------------------isEmpty---------------------------------------------- -
// Description
// checks to see if the queue is empty or not
// preconditions:  not point to Null value 
// postconditions: returns the bool value of if the value fo the head is there or not
// indicates emptiness
// -------------------------------------------------------------------------------------------- 
bool Queue::isEmpty()
{
	return (head == nullptr);
}


// ------------------------------------build----------------------------------------------- 
// Description
// build:  build Transaction info into the store data through the provided list.  
// assiciated with its term.
// preconditions:valid transation, valid inputs from open instream
// postconditions: inserts transactiontype into the factorymethods with proper data
// -----------------------------------------------------------------------------------
void Queue::build(ifstream& infile)
{

	char transactionType;
	infile >> transactionType;

	while (!infile.eof())
	{
		Transaction* temp = nullptr;

		if (transactionFactory.createTransaction(transactionType, temp, infile))
		{
			push(temp);
		}
		else {
			string store;
			getline(infile, store);

			if (temp != nullptr) delete temp;
		}
		infile >> transactionType;

		if (infile.eof()) 
			break;
	}
}