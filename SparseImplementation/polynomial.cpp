// ------------------------------------------------ ploynomial.cpp -------------------------------------------------------

// Samuel Debesai CSS343 C

// 1/11/2020

// 1/18/2020

// --------------------------------------------------------------------------------------------------------------------
// Purpose - This programming assignment exercises dynamic memory allocation, pointer operations, 
// and copy constructor design through designing a doubly-linked circular list with a dummy 
// header. Using such a list, you will implement an ADT polynomial. 

// -------------------------------------------------------------------------------------------------------------------- 

// --------------------------------------------------------------------------------------------------------------------
#include "polynomial.h"
#include <cmath>
// ------------------------------------Default Constructor----------------------------------------------- 
// Description
// Default Constructor: variables of the Terms properties are initialized in
// and pointers instantiated to point in respect to a doubly circular 
//linked list
// preconditions: Default to default values or inital expressions
// postconditions: The first instance of a polynomial is created in
// respect to all properties
// -------------------------------------------------------------------------------------------- 
Polynomial::Polynomial()
{
	head = new Term();
	head->next = head;
	head->prev = head;

	head->coeff = 0.0;
	head->power = 0;
	size = 0;
}
//end of Default Constructor

// ------------------------------------Copy Constructor----------------------------------------------- 
// Description
// Copy Constructor: The copy constructor initializes an object 
// within the same constraints of the class. Take care of deep copy 
// preconditions: Must not point towards a null value
// postconditions: A deep copy of all values in respect to the
// Terms properties
// -------------------------------------------------------------------------------------------- 
Polynomial::Polynomial(const Polynomial& p)
{
	head = new Term();
	head->next = head;
	head->prev = head;

	head->coeff = 0.0;
	head->power = 0;
	size = 0;
	*this = p;
}
//end of Copy Constructor
// ------------------------------------Deconstructor----------------------------------------------- 
// Description
// Deconstructor: De-allocates the linked nodes that 
// are associated within the data set
// preconditions: size must be greater than 1 and not point to Null value 
// postconditions: deallocation of memory
// -------------------------------------------------------------------------------------------- 
Polynomial::~Polynomial()
{
	if (head == nullptr || size == 0) // does nothing in cases of empty
	{
		return;
	}

	if (size == 1) //only holds one term
	{
		remove(head->next);//deletes circular
		delete head;
		head = nullptr;
		return;
	}
	//removes all the other nodes
	Term* pNode = head->next->next;
	while (pNode != head)
	{
		remove(pNode->prev);
		pNode = pNode->next;
	}
	//last node
	remove(pNode->next);
	delete head;
	head = nullptr;
}
//end of Deconstructor

// ------------------------------------Degree----------------------------------------------- 
// Description
// Degree: Returns the degree of the max polynomial 
// preconditions: the head must not point to null and size greater than 0 
// postconditions: @returns the maximum degree post traversal
// -------------------------------------------------------------------------------------------- 
int Polynomial::degree() const
{
	if (head == nullptr || size == 0)
	{
		return 0;
	}

	int max = 0;
	Term* pNode = head->next;
	while (pNode != head)
	{
		if (pNode->power > max)
		{
			max = pNode->power;//comaprison swap
		}
		pNode = pNode->next;
	}

	return max;
}
//end of Degree

// ------------------------------------Coefficient----------------------------------------------- 
// Description
// coefficient: returns the coefficient of the x^power term. 
// preconditions: the head must not point to null and size greater than 0 
// postconditions: @returns coefficient of power
// -------------------------------------------------------------------------------------------- 
double Polynomial::coefficient(const int power) const
{
	if (head == nullptr || size == 0)
	{
		return 0;
	}

	Term* pNode = head->next;
	while (pNode != head)
	{
		if (pNode->power == power)
		{
			return pNode->coeff;//returns when found
		}
		pNode = pNode->next;
	}

	return -1; //if value isn't found
}
//end of Coefficient

// ------------------------------------changeCoefficient----------------------------------------------- 
// Description
// changeCoefficient: replaces the coefficient of the x^power term and inserts
// value into linked list, as well as remove value.
// preconditions: newCoefficient is suppose to update lhs coeff, power updates
// for lhs power.
// postconditions: The updated changes are able to be able to change the value,
// delete value, and insert a value.
// -------------------------------------------------------------------------------------------- 
bool Polynomial::changeCoefficient(const double newCoefficient, const int power)
{
	//handles deletion
	if (newCoefficient == 0.0 && power == 0)
	{
		Term* tempPoly = new Term;
		tempPoly->coeff = 0.0;
		tempPoly->power = 0;

		bool tempPolyRemove = remove(tempPoly);//removal of temp
		delete tempPoly;
		tempPoly = nullptr;
		return tempPolyRemove;
	}

	Term* pNode = head->next;
	while (pNode != head)//checks power existences
	{
		if (pNode->power == power)
		{
			pNode->coeff = newCoefficient;
			pNode = nullptr;
			delete pNode;
			return true;
		}
		pNode = pNode->next;
	}
	pNode = nullptr;
	delete pNode;


	//handles empty linked list
	if (size == 0)
	{
		head->next = new Term;
		head->next->coeff = newCoefficient;
		head->next->power = power;

		head->prev = head->next;

		head->next->prev = head;
		head->next->next = head;

		size++;
		return true;

	}
	else if (size == 1)//one term
	{
		if (head->next->power > power)
		{
			Term* temp = new Term;
			temp->coeff = newCoefficient;
			temp->power = power;
			temp->next = head;
			temp->prev = head->next;
			temp->next->prev = temp;
			temp->prev->next = temp;

			size++;

			temp = nullptr;
			delete temp;
			return true;
		}
		else {//when the lhs has become less than the rhs params
			Term* temp = new Term;
			temp->coeff = newCoefficient;
			temp->power = power;
			temp->next = head->next;
			temp->prev = head;
			temp->next->prev = temp;
			temp->prev->next = temp;

			size++;

			temp = nullptr;
			delete temp;
			return true;
		}
	}
	//last cases of insert if no changes engaged for value or removal
	return insert(head->next, newCoefficient, power);

}
//end of changeCoefficient

// ------------------------------------Addition-----------------------------------------------
// Description
// Addition: adds like terms 
// preconditions: head is not equal to null and rhs to added to lhs
// postconditions: changes to the lhs appropriate to values
// -------------------------------------------------------------------------------------------- 
Polynomial Polynomial::operator+(const Polynomial& p) const
{
	Polynomial lhs(*this);
	Polynomial rhs(p);

	Term* left;
	Term* right = rhs.head->next;

	bool check = false;

	while (right != rhs.head)//traversal
	{
		left = lhs.head->next;
		check = false;

		while (left != lhs.head)
		{
			if (right->power == left->power)//checks is summation is possible
			{
				//adds coefficient
				lhs.changeCoefficient(left->coeff + right->coeff, left->power);
				check = true;

			}
			left = left->next;
		}
		if (!check)
		{

			//adds values
			lhs.changeCoefficient(right->coeff, right->power);
		}
		right = right->next;
	}
	return lhs;
}
//end of Addition

// ------------------------------------Subtraction----------------------------------------------- 
// Description
// Subtraction: sub like terms 
// preconditions: head is not equal to null and rhs to added to lhs
// postconditions: the differneces of the lhs and the rhs is equated
// -------------------------------------------------------------------------------------------- 
Polynomial Polynomial::operator-(const Polynomial& p) const
{
	Polynomial rhs(p);
	Term* right = rhs.head->next;

	while (right != rhs.head)//creates a negative copy
	{
		rhs.changeCoefficient(right->coeff * (-1), right->power);
		right = right->next;
	}
	//negative arithmetics
	return (*this + rhs);
}
//end of Subtraction

// ------------------------------------Comparison----------------------------------------------- 
// Description
// Comparison: compares the polynomials 
// preconditions: head is not equal to null and rhs to added to lhs
// postconditions: value return to determine if all points of the poly
// matches each other
// -------------------------------------------------------------------------------------------- 
bool Polynomial::operator==(const Polynomial& p) const
{
	Term* left = head->next;
	Term* right = p.head->next;

	while (left != head && right != head)
	{
		if (left->coeff != right->coeff || left->power != right->power)
		{
			return false;
		}
		left = left->next;
		right = right->next;
	}

	if (left == head && right != head || left != head && right == head)
	{
		return false;
	}
	else
	{
		return true;
	}
}
//end of Comparison

// ------------------------------------Bang Comparison----------------------------------------------- 
// Description
// Comparison: compares the polynomials and replies if not equals 
// preconditions: head is not equal to null and rhs to added to lhs
// postconditions: value of the NOT comparison check
// -------------------------------------------------------------------------------------------- 
bool Polynomial::operator!=(const Polynomial& p) const
{
	return !(*this == p);
}
//end of Bang Comparison

// ------------------------------------Deep Copy----------------------------------------------- 
// Description
// Deep Copy: deep copy of rhs object 
// preconditions: parameter is instantiated
// postconditions: returns the deep copy or all respected values to lhs
// matches each other
// -------------------------------------------------------------------------------------------- 
Polynomial& Polynomial::operator=(const Polynomial& p)
{
	if (p.size == 0)
	{
		return *this;
	}
	Term* pNode = p.head->next;
	while (pNode != p.head)
	{
		changeCoefficient(pNode->coeff, pNode->power);
		pNode = pNode->next;
	}

	pNode = nullptr;
	delete pNode;
	return *this;
}
//end of Deep Copy

// ------------------------------------Summation----------------------------------------------- 
// Description
// Summation: addition of rhs to lhs 
// preconditions: head is not equal to null and rhs to added to lhs
// postconditions: returns the deep copy or all respected values to 
// add the rhs and lhs
// -------------------------------------------------------------------------------------------- 
Polynomial& Polynomial::operator+=(const Polynomial& p)
{
	return (*this = (*this + p));

}
//end of Summation

// ------------------------------------Subtraction from LHS----------------------------------------------- 
// Description
// Summation: subtraction of rhs to lhs 
// preconditions: head is not equal to null and rhs to added to lhs
// postconditions: returns the deep copy or all respected values to 
// subtract the rhs and lhs
// -------------------------------------------------------------------------------------------- 
Polynomial& Polynomial::operator-=(const Polynomial& p)
{
	return (*this = (*this - p));
}
//end of Subtraction from LHS

// ------------------------------------insert----------------------------------------------- 
// Description
// insert: insertion of values, which will  be used bychangeCoefficient to insert a new term.
// preconditions:The next passed in value, is the lowest degree from the previous power 
// postconditions: insertion into the polynomial in respect to order 
// grows in size
// -------------------------------------------------------------------------------------------- 
bool Polynomial::insert(Term* prev, const double newCoefficient, const int power)
{
	Term* temp = new Term;
	temp->power = power;
	temp->coeff = newCoefficient;
	temp->next = prev;
	if (prev->next == nullptr)
	{
		temp->prev = prev;
		prev->next = temp;
	}
	else
	{
		temp->prev = prev->prev;
		prev->prev->next = temp;
	}
	prev->prev = temp;
	size++;
	return true;
}
//end of insert

// ------------------------------------Remove----------------------------------------------- 
// Description
// Remove: deletes the existing Term node pointed by the pos pointer 
// preconditions: head is not equal to null and size is not 0
// postconditions: returns true if the operation of removal of 
// a value from the doubly linked list is sucessful
// -------------------------------------------------------------------------------------------- 
bool Polynomial::remove(Term* pos)
{
	Term* pNode = head->next;
	if (head == nullptr || size == 0)//no value to delete, handles case
	{
		pNode = nullptr;
		return false;
	}

	else if (size == 1)//single term
	{
		if (pos->power == pNode->power)
		{

			head->next = head;
			head->prev = head;
			//circular behavior
			head->next->prev = head;
			head->prev->next = head;

			size--;
			pNode = nullptr;
			return true;
		}
	}
	//removal of nodes through the linked list
	while (pNode->power != pos->power)
	{
		if (pNode == head)
		{
			pNode = nullptr;
			return false;
		}
		pNode = pNode->next;
	}
	pNode->prev->next = pNode->next;
	pNode->next->prev = pNode->prev;

	delete pNode;
	pNode = nullptr;
	size--;
	return true;
}
//end of remove


// ------------------------------------OutStream Overload----------------------------------------------- 
// Description
// OutStream Overload: display the values in repect the properties of  
// preconditions: object for the output and the polynomial
// postconditions: overloaded ouput in respect to the process and 
// make of a ploynomial in order
// -------------------------------------------------------------------------------------------- 

ostream& operator<<(ostream& outStream, const Polynomial& p)
{
	if (p.head->next == nullptr || p.head->next->next == p.head)
	{
		outStream << "0.0";
		return outStream;
	}

	Polynomial::Term* pNode = p.head->next;
	outStream << pNode->coeff << "x^" << pNode->power;
	pNode = pNode->next;
	while (pNode != p.head)
	{
		if (pNode->power == 0)
		{
			if (pNode->coeff > 0)
			{
				outStream << " + " << pNode->coeff;
			}
			else
			{
				outStream << " - " << pNode->coeff;
			}
		}//structure for positve or negative numbers
		else if (pNode->coeff > 0)//handles unary operator of coefficient
			outStream << " + " << abs(pNode->coeff) << "x^" << pNode->power;
		else if (pNode->coeff < 0)
			outStream << " - " << abs(pNode->coeff) << "x^" << pNode->power;
		pNode = pNode->next;
	}

	return outStream;
}
//end of OutStream Overload

//end of polynomial.cpp