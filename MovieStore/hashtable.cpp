#include "hashtable.h"
// ------------------------------------hashtable---------------------------------------------- -
// Description
// sets the array to null values, assumption of unique customers
// preconditions: no invalid objects for hashing
// postconditions: sets all elements for the table
// -------------------------------------------------------------------------------------------- 
hashtable::hashtable()
{
	for (int i = 0; i < 102; i++) {
		container[i] = nullptr;
	}

}
// ------------------------------------deconstructor---------------------------------------------- -
// Description
// deletes the allocation of the array at the specific index
// preconditions: non-dangling pointers
// postconditions: deletes the nodes of the elements
// -------------------------------------------------------------------------------------------- 
hashtable::~hashtable()
{
	Node* cNode;

	for (int i = 0; i < 102; i++) {
		while (container[i] != nullptr) {
			cNode = container[i];
			container[i] = container[i]->next;
			delete cNode;
		}
	}
}
// ------------------------------------retrieve----------------------------------------------- 
// Description
// retrieve:  rtrieval of the customer data based off the id and hashing.  
// assiciated with its term.
// preconditions:must be of certain customer and id
// postconditions: retrieves customer data based on its findings
// -----------------------------------------------------------------------------------
bool hashtable::retrieve(int id, Customer*& customer)
{
	int hashID = hash(id);
	Node* cNode = container[hashID];

	while (cNode != nullptr)
	{
		if (cNode->data->getCustomerID() == id)
		{
			customer = cNode->data;
			return true;
		}
		else
		{
			cNode = cNode->next;
		}
	}
	return false;
}
// ------------------------------------insert----------------------------------------------- 
// Description
// insert:  Insert customer into the store data through hashing.  
// assiciated with its term.
// preconditions:valid customer
// postconditions: inserts new customer into proper data
// -----------------------------------------------------------------------------------
void hashtable::insert(Customer* customer)
{
	int id = hash(customer->getCustomerID());
	Node* store = container[id];

	container[id] = new Node(customer, store);

}
// ------------------------------------build----------------------------------------------- 
// Description
// build:  build customer into the store data through the provided list.  
// assiciated with its term.
// preconditions:valid customer, valid inputs from open instream
// postconditions: inserts new customer into proper data
// -----------------------------------------------------------------------------------
void hashtable::build(ifstream& infile)
{
	while (!infile.eof())
	{
		Customer* temp = new Customer;
		if (temp->setData(infile))
		{
			if (!infile.eof())
			{
				insert(temp);//insertions
			}
			else
			{
				delete temp;
			}
		}
		else
		{
			delete temp;
		}
	}
}

int hashtable::hash(int id)
{
	return id % 102;//hashing for a prime indexing of numbers
}
