#ifndef BINTREE_h
#define BINTREE_h

#include <fstream>
#include <sstream>
#include <iostream>
#include "Movie.h"
using namespace std;

class bintree
{
	//display operator overload
	friend ostream& operator<<(std::ostream& outStream, const bintree& tree);

	struct Node
	{
		Movie* data;
		Node* left = nullptr;
		Node* right = nullptr;
		bool visited = false;

		Node(Movie* data, Node* left, Node* right) :
			data(data), left(left), right(right) {};

	};

private:

	Node* root = nullptr;
	//gets all the stock avaliable per movie
	int allStock(Node*, Movie*&) const;
	//resets the fringe of the visited
	void reset(Node*) const;


public:

	//destructor
	~bintree();

	//insertion
	void insert(Movie* data);

	//retrieval
	bool retrieve(Movie*, Movie*&);

	//checks if empty
	bool isEmpty();

	//makes empty
	void makeEmpty();

	//inorder traversal display
	string inorderWalk() const;

	//helper methods
	Node* insertHelper(Node*& currNode, Movie*& data);

	bool retrieveH(Node* subtree, Movie* target, Movie*& out) const;

	string inorderHelper(Node* currNode) const;

	void makeEmptyHelper(Node* sNode);


};

#endif