#include "Customer.h"
//set customer information
//precindition: infile must be valid
//postconditions: infile instream read

bool Customer::setData(ifstream& infile)
{
	infile >> customerID;
	if (customerID >= 0)
	{
		infile >> lastName;
		infile >> firstName;
		return true;
	}
	else
	{
		cout << "ERROR: " << customerID << " non-valid ID." << endl;

		return false;

	}
}

//accounts for the borrowed movie by subtracting 1 from stock
//precindition:
//postconditions:
void Customer::borrowMovie(Movie*& movie)
{
	Movie* borrowM = movie;
	borrowM->setStock(1);

	movieHistory.push(borrowM);
}

//retrieves movie history of all transaction of a customer
//precindition:
//postconditions:
bool Customer::retrieveMovieHistory(Movie*& movie, Movie*& returnM)
{
	stack<Movie*> stack;
	Movie* store;

	while (!movieHistory.empty())
	{
		store = movieHistory.front();

		if (*movie == *store)
		{
			returnM = store;
			movieHistory.pop();

			while (!stack.empty())
			{
				store = stack.top();
				movieHistory.push(store);
				stack.pop();
			}
			return true;
		}
		else
		{
			store = movieHistory.front();
			stack.push(store);
			movieHistory.pop();
		}
	}
	while (!stack.empty())
	{
		store = stack.top();
		movieHistory.push(store);
		stack.pop();
	}
	return false;
}

//displays the history of a custommer
//precindition:
//postconditions:
void Customer::displayHistory()
{
	queue<string> queue;
	string temp;

	cout << endl;
	cout << firstName << " " << lastName << "'s borrowing history:" << endl;

	if (!userHistory.empty())
	{
		while (!userHistory.empty())
		{
			temp = userHistory.top();
			userHistory.pop();
			cout << " * " << temp << endl;
			queue.push(temp);
		}
		while (!queue.empty()) {

			temp = queue.front();

			userHistory.push(temp);
			queue.pop();
		}
		cout << endl;
	}
	else
	{
		cout << " * " << firstName << " " << lastName
			<< " non-valid user." << endl << endl;
	}
}

//inserts in to the history file of a customer
//precindition:
//postconditions:
void Customer::insert(string history)
{
	userHistory.push(history);
}

//get the customer ID
//return the customer ID
int Customer::getCustomerID() const
{
	return customerID;
}

//gets the first name of a customer
//returns the name of the first name of the customer
string Customer::getFirstName() const
{
	return firstName;
}

//gets the last name of customer
//returns the last name of a customer
string Customer::getLastName() const
{
	return lastName;
}


ostream& operator<<(ostream& outStream, const Customer& customer)
{
	outStream << customer.getFirstName() << " " << customer.getLastName()
		<< " ID: " << customer.getCustomerID();

	return outStream;
}
