// ------------------------------------------------ BinTree.cpp -------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This program is to create a binary search tree class called BinTree along with some additional functions 

// -------------------------------------------------------------------------------------------------------------------- 

// --------------------------------------------------------------------------------------------------------------------
#include "bintree.h"
#include <algorithm>    
#include <iomanip>
using namespace std;

// ------------------------------------allStock----------------------------------------------- 
// Description
// Gets the stock of all the movies of a certain type in parameters
// preconditions: stock is expression in valid options
// postconditions: able to obtain the proper contained stock for each movie type
// in respect to all properties
// -------------------------------------------------------------------------------------------- 
int bintree::allStock(Node* currPtr, Movie*& movie) const
{
	if (currPtr == nullptr)
	{
		return 0;
	}
	else if ((currPtr->data->getTitle() == movie->getTitle()) && !currPtr->visited)
	{
		currPtr->visited = true;

		return currPtr->data->getStock() + (allStock(currPtr->left, movie) + allStock(currPtr->right, movie));

	}
	else
	{
		return (allStock(currPtr->left, movie) + allStock(currPtr->right, movie));

	}
}
// ------------------------------------reset---------------------------------------------- -
// Description
// Resets all the nodes that are account for being visited on the fringe 
// preconditions: nodes are not to be set to true for search
// postconditions: all visited bools of the given node are reset to false a null val
// in respect to all properties
// -------------------------------------------------------------------------------------------- 
void bintree::reset(Node* currNode) const
{
	if (currNode != nullptr)
	{
		currNode->visited = false;
		reset(currNode->right);
		reset(currNode->left);
	}
}
// ------------------------------------insert----------------------------------------------- 
// Description
// insert: insertion of values, which will  be used the overloaded operators to insert a new type of movie.
// preconditions:The next passed in value, is the lowest degree from the previous power 
// postconditions: insertion into the polynomial in respect to order 
// grows in size
// -------------------------------------------------------------------------------------------- 
bintree::Node* bintree::insertHelper(Node*& currNode, Movie*& data)
{
	if (currNode == nullptr)
	{
		currNode = new Node(data, nullptr, nullptr);
	}
	else if (*data < *currNode->data)
	{
		currNode->left = insertHelper(currNode->left, data);
	}
	else if (*data > * currNode->data)
	{
		currNode->right = insertHelper(currNode->right, data);
	}
	else if (*data == *currNode->data)
	{
		currNode->data->setStock(currNode->data->getStock() + data->getStock());
	}
	else
	{
		cout << "LOGICAL ERROR: could not insert " << data->getTitle() << endl;
	}
	return currNode;
}
// ------------------------------------retrieveH----------------------------------------------- 
// Description
// retrieveH: retrieval of the corerct target value that is associated with the proper data 
// assiciated with its term.
// preconditions:must be of certain movietpye
// postconditions: retrieves movie and returns based on its findings
// -------------------------------------------------------------------------------------------- 
bool bintree::retrieveH(bintree::Node* currNode, Movie* target, Movie*& data) const
{
	if (currNode == nullptr) {

		return false;
	}
	if (*currNode->data == *target) {

		data = currNode->data;
		return true;
	}
	else if (*target > * currNode->data) {

		return retrieveH(currNode->right, target, data);
	}
	else
	{
		return retrieveH(currNode->left, target, data);
	}
}
// ------------------------------------makeEmptyHelper----------------------------------------------- 
// Description
// makeEmptyHelper: deletes the existing Term node pointed by the pos pointer 
// preconditions: head is not equal to null and size is not 0
// postconditions: values are all deleted in the source node down to the leaves
// -------------------------------------------------------------------------------------------- 
void bintree::makeEmptyHelper(Node* sNode)
{
	if (!sNode)
		return;
	makeEmptyHelper(sNode->left);
	makeEmptyHelper(sNode->right);
	delete sNode;
}

string bintree::inorderWalk() const
{
	string str = inorderHelper(root);
	reset(root);

	return str;
}

// ------------------------------------Deconstructor-----------------------------------------------
// Description
// Deconstructor: De-allocates the nodes
// are associated within the data set
// preconditions:  not point to Null value 
// postconditions: deallocation of memory
// -------------------------------------------------------------------------------------------- 
bintree::~bintree()
{
	makeEmptyHelper(root);
	root = nullptr;
}

// ------------------------------------insert----------------------------------------------- 
// Description
// insert: insertion of values, which will  be used the overloaded operators to insert a new type of movie.
// preconditions:The next passed in value, is the lowest degree from the previous power 
// postconditions: insertion into the polynomial in respect to order 
// grows in size
// -------------------------------------------------------------------------------------------- 
void bintree::insert(Movie* data)
{
	root = insertHelper(root, data);
}

// ------------------------------------retrieveH----------------------------------------------- 
// Description
// retrieveH: retrieval of the corerct target value that is associated with the proper data 
// assiciated with its term.
// preconditions:must be of certain movietpye
// postconditions: retrieves movie and returns based on its findings
// -------------------------------------------------------------------------------------------- 
bool bintree::retrieve(Movie* target, Movie*& data)
{
	return retrieveH(root, target, data);
}

// ------------------------------------inorderHelper----------------------------------------------- 
// Description
// inorderHelper:builds the bst to show the titile and its stock values
// preconditions:must be valid movietype
// postconditions: displays all movies inorder fashion of their sorting mechanisims
// -------------------------------------------------------------------------------------------- 
string bintree::inorderHelper(bintree::Node* currNode) const
{
	stringstream stream;
	if (currNode != nullptr) {

		stream << inorderHelper(currNode->left);

		if (!currNode->visited) {

			stream.setf(ios::left);

			stream << setw(10) << " ";

			stream << setw(50) << currNode->data->getTitle();

			stream << allStock(root, currNode->data);

			stream << endl;
		}
		stream << inorderHelper(currNode->right);
	}
	return stream.str();
}
// ------------------------------------isEmpty----------------------------------------------- 
// Description
// isEmpty:checks to see if the bst is empty
// preconditions:
// postconditions: returns if the bst has is allocated or not and returns off disposition
// -------------------------------------------------------------------------------------------- 
bool bintree::isEmpty()
{
	return (root == nullptr) ? true : false;
}
// ------------------------------------makeEmpty----------------------------------------------- 
// Description
// makeEmptyHelper: deletes the existing Term node pointed by the pos pointer 
// preconditions: head is not equal to null and size is not 0
// postconditions: values are all deleted in the source node down to the leaves
// -------------------------------------------------------------------------------------------- 
void bintree::makeEmpty()
{
	return makeEmptyHelper(root);
}
// ------------------------------------OutStream Overload----------------------------------------------- 
// Description
// OutStream Overload: display the values in repect the properties of movies 
// preconditions: object for the output and movie
// postconditions: overloaded ouput in respect to the process and 
// outputs stores stock inorder
// -------------------------------------------------------------------------------------------- 
std::ostream& operator<<(std::ostream& outStream, const bintree& tree)
{
	outStream << tree.inorderWalk();
	return outStream;
}
