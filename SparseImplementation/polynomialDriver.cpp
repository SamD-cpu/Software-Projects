// ------------------------------------------------ main.cpp -------------------------------------------------------

// Samuel Debesai CSS343 C

// 1/11/2020

// 1/18/2020

// --------------------------------------------------------------------------------------------------------------------
// Purpose - Driver for Testing program
// -------------------------------------------------------------------------------------------------------------------- 

// --------------------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;

#include "polynomial.h"

int main() {
	//insert test
	Polynomial p1;

	p1.changeCoefficient(1, 2);

	p1.changeCoefficient(5, 1);

	p1.changeCoefficient(9, 3);

	p1.changeCoefficient(-7.3, 7);

	cout << "p1 = " << p1 << endl;

	//remove
	p1.changeCoefficient(0, 2);
	cout << "p1 = " << p1 << endl;

	//assignment
	Polynomial p2 = p1;

	
	//degree & coefficient
	cout << "p1 = " << p1 << endl;
	cout << "p2 = " << p2 << endl;

	cout << "Degree of p1: " << p1.degree()<<endl;
	cout << "Degree of p2: " << p2.degree() << endl;
	cout << "Coefficient of p1 at 1st degree: " << p1.coefficient(1)<< endl;
	cout << "Coefficient of p2 at 7th degree: " << p2.coefficient(7)<<endl;
	p2.changeCoefficient(0, 7);

	//comparison & bang comparison
	cout << "Comparison" << endl;
	cout << "p1 = " << p1 << endl;
	cout << "p2 = " << p2 << endl;
	cout << "Comparing p1 & p2: " << (p1 == p2) << endl;
	cout << "Bang Comparison of p1 & p2: " << !(p1 == p2) << endl;

	// Arithmetic operators
	Polynomial p3;

	p3.changeCoefficient(1, 1);

	p3.changeCoefficient(4, 4);


	cout << "p3 = " << p3 << endl;

	//copy constructor
	Polynomial p4(p3);

	cout << "p4 = " << p4 << endl;
	cout << "Addition of p4 and p3: " << (p4 + p3) << endl;
	cout << "Subtraction of p4 and p3: " << (p4 - p3) << endl;
	cout << "adding p3 to p4: " << (p4 += p3) << endl;
	cout << "after addition of p3 to p4 = " << p4 << endl;
	cout << "p3 = " << p3 << endl;
	cout << "subracting p3 from p4: " << (p4 -= p3) << endl;


	cout << endl;

	return 0;
}


