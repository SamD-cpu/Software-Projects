#include "Comedy.h"

// ------------------------------------DisplayType----------------------------------------------- 
// Description
// DisplayType: displays the correct output for the constraints of type of movieType 
// preconditions: must be of valid types
// postconditions: returns ostream value of movie type
// --------------------------------------------------------------------------------------------
void Comedy::displayType(ostream& outStream) const
{
	outStream << getTitle() << " " << getYear();
}
// ------------------------------------char constructor----------------------------------------------- 
// Description
// set MovieType
// preconditions: value typeof value  
// postconditions: sets new setMovieType value
// -------------------------------------------------------------------------------------------- 
Comedy::Comedy(char movieType)
{
	setMovieType(movieType);
}
// ------------------------------------setData----------------------------------------------- 
// Description
// sets the data that are assicoated with the pass in
// preconditions: must be of acessible & valid input of file read in
// postconditions: reads in the data from the readMovies call line
// -------------------------------------------------------------------------------------------- 
void Comedy::setData(ifstream& infile)
{
	Movie::setData(infile);

	string year;

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
bool Comedy::operator==(const Movie& rhs)
{
	return (getTitle() == rhs.getTitle() &&
		getYear() == rhs.getYear());

}
// ------------------------------------Bang Comparison----------------------------------------------- 
// Description
// Bang Comparison: bang comparison of the two movie objs 
// preconditions: no invalid objects for compaison
// postconditions: value return to determine if all nodes of the movie type
// do not match each other
// -------------------------------------------------------------------------------------------- 
bool Comedy::operator!=(const Movie& rhs)
{
	return!(this == &rhs);
}
// ------------------------------------operator<---------------------------------------------- -
// Description
// Comparison: compares the two movie objs and check to see if one is less 
// preconditions: no invalid objects for compaison
// postconditions: makes sure that the values that are comparted match the movies type of
// comparison that is suppose to match the operations comparisons
// -------------------------------------------------------------------------------------------- 
bool Comedy::operator<(const Movie& rhs)
{
	if (getTitle() != rhs.getTitle())
	{
		return getTitle() < rhs.getTitle();
	}
	else
	{
		return getYear() < rhs.getYear();
	}
}
// ------------------------------------operator>---------------------------------------------- -
// Description
// Comparison: compares the two movie objs and check to see if one is greater 
// preconditions: no invalid objects for compaison
// postconditions: makes sure that the values that are comparted match the movies type of
// comparison that is suppose to match the operations comparisons
// -------------------------------------------------------------------------------------------- 
bool Comedy::operator>(const Movie& rhs)
{
	if (getTitle() != rhs.getTitle())
	{
		return getTitle() > rhs.getTitle();
	}
	else
	{
		return getYear() > rhs.getYear();
	}
}
