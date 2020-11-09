#include "view.h"
#include <iostream>
#include <iomanip>
void view::process(bintree movies[], hashtable& customers)
{
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << setw(40) << genre[i] << endl;
		cout << "--------------------------------------------------------------------------------" << endl << endl;
		cout << setw(20) << "Title" << setw(43) << "Stock" << endl << endl;
		cout << movies[movieType[i] - 'A'] << endl;
	}
	cout << endl;
}

bool view::setData(ifstream& infile, char transaction)
{
	setTransaction(transaction);
	return true;
}

string view::getString() const
{
	return "Inventory: ";
}
