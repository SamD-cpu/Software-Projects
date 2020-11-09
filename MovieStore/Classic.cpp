#include "Classic.h"

// ------------------------------------DisplayType----------------------------------------------- 
// Description
// DisplayType: displays the correct output for the constraints of type of movieType 
// preconditions: must be of valid types
// postconditions: returns ostream value of movie type
// -------------------------------------------------------------------------------------------- 
void Classic::displayType(ostream& outStream) const
{
	outStream << getMonth() << " " << getYear() << " " << getMajorActor();

}
// ------------------------------------char constructor----------------------------------------------- 
// Description
// set MovieType
// preconditions: value typeof value  
// postconditions: sets new setMovieType value
// -------------------------------------------------------------------------------------------- 
Classic::Classic(char movieType)
{
	setMovieType(movieType);
}
// ------------------------------------setData----------------------------------------------- 
// Description
// sets the data that are assicoated with the pass in
// preconditions: must be of acessible & valid input of file read in
// postconditions: reads in the data from the readMovies call line
// -------------------------------------------------------------------------------------------- 
void Classic::setData(ifstream& infile)
{
	Movie::setData(infile);

	string firstName;
	string lastName;
	int month;
	string year;

	infile >> firstName;
	infile >> lastName;
	setMajorActor(firstName + " " + lastName);

	infile >> month;
	setMonth(month);

	getline(infile, year);
	Movie::reduce(year);
	setYear(stoi(year));
}
// ------------------------------------Comparison---------------------------------------------- -
// Description
// Comparison: compares the two movie objs 
// preconditions: no invalid objects for compaison
// postconditions: value return to determine if all nodes of the movies
// matches each other based off of params
// -------------------------------------------------------------------------------------------- 
bool Classic::operator==(const Movie& rhs)
{
	return (getMajorActor() == rhs.getMajorActor() &&
		getYear() == rhs.getYear() &&
		getMonth() == rhs.getMonth());
}
// ------------------------------------Bang Comparison----------------------------------------------- 
// Description
// Bang Comparison: bang comparison of the two movie objs 
// preconditions: no invalid objects for compaison
// postconditions: value return to determine if all nodes of the movie type
// do not match each other
// -------------------------------------------------------------------------------------------- 
bool Classic::operator!=(const Movie& rhs)
{
	return !(this == &rhs);
}
// ------------------------------------operator>---------------------------------------------- -
// Description
// Comparison: compares the two movie objs and check to see if one is greater 
// preconditions: no invalid objects for compaison
// postconditions: makes sure that the values that are comparted match the movies type of
// comparison that is suppose to match the operations comparisons
// -------------------------------------------------------------------------------------------- 
bool Classic::operator>(const Movie& rhs)
{

	if (getYear() != rhs.getYear())
	{
		return getYear() > rhs.getYear();
	}
	else
	{
		return getMajorActor() > rhs.getMajorActor();
	}
}
// ------------------------------------operator<---------------------------------------------- -
// Description
// Comparison: compares the two movie objs and check to see if one is less 
// preconditions: no invalid objects for compaison
// postconditions: makes sure that the values that are comparted match the movies type of
// comparison that is suppose to match the operations comparisons
// -------------------------------------------------------------------------------------------- 
bool Classic::operator<(const Movie& rhs)
{
	if (getYear() != rhs.getYear())
	{
		return getYear() < rhs.getYear();
	}
	else
	{
		return getMajorActor() < rhs.getMajorActor();
	}
}
// ------------------------------------Comparison---------------------------------------------- -
// Description
// Comparison: sets the objects to the super class and the assumed class porpeties
// preconditions: no invalid objects for compaison
// postconditions: values will be set to the type of method for values
// -----------------------------------------------------------------------------------
Movie& Classic::operator=(Movie& rhs)
{
	Movie::operator=(rhs);

	rhs.setMonth(getMonth());
	rhs.setMajorActor(getMajorActor());

	return rhs;
}
