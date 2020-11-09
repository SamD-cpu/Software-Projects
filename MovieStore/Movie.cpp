#include "Movie.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>


// ------------------------------------reduce----------------------------------------------- 
// Description
// eliminates the trailing spaces that are with unicode 
// preconditions: must be of valid input
// postconditions: gives the value of char into a string format without trailing lines
// in respect to all properties
// -------------------------------------------------------------------------------------------- 
void Movie::reduce(string& inStream)
{
	stringstream stream;
	stream << inStream;

	string str;
	string outStream;

	while (stream >> str) {

		outStream += (str + ' ');
	}
	if (outStream[outStream.length() - 1] == '\n') {
		outStream = outStream.substr(0, outStream.length() - 2);
	}

	inStream = outStream.substr(0, outStream.length() - 1);
}
// ------------------------------------setData----------------------------------------------- 
// Description
// sets the data that are assicoated with the pass in
// preconditions: must be of acessible & valid input of file read in
// postconditions: reads in the data from the readMovies call line
// -------------------------------------------------------------------------------------------- 
void Movie::setData(ifstream& infile)
{

	string store;
	getline(infile, store, ',');

	while (store == "")
		getline(infile, store, ',');
	Movie::reduce(store);
	setStock(stoi(store));

	getline(infile, store, ',');
	Movie::reduce(store);
	setDirector(store);

	getline(infile, store, ',');
	Movie::reduce(store);
	setTitle(store);

}
// ------------------------------------getStock----------------------------------------------- 
// Description
// gets stock number
// preconditions: immutable object 
// postconditions: the return of stock value
// -------------------------------------------------------------------------------------------- 
int Movie::getStock()const
{
	return stock;
}
// ------------------------------------setStock----------------------------------------------- 
// Description
// sets stock number
// preconditions: value typeof value 
// postconditions: sets the new stock value
// -------------------------------------------------------------------------------------------- 
void Movie::setStock(int stock)
{
	this->stock = stock;
}
// ------------------------------------getTitle----------------------------------------------- 
// Description
// get Title string
// preconditions: immutable object 
// postconditions: the return of string value
// -------------------------------------------------------------------------------------------- 
string Movie::getTitle()const
{
	return title;
}
// ------------------------------------setTitle----------------------------------------------- 
// Description
// set Title string
// preconditions: value typeof value  
// postconditions: sets new string value
// -------------------------------------------------------------------------------------------- 
void Movie::setTitle(string title)
{
	this->title = title;
}
// ------------------------------------getTitle----------------------------------------------- 
// Description
// get Title string
// preconditions: immutable object 
// postconditions: the return of string value
// -------------------------------------------------------------------------------------------- 
string Movie::getDirector()const
{
	return director;
}
// ------------------------------------setDirector----------------------------------------------- 
// Description
// set Director string
// preconditions: value typeof value  
// postconditions: sets new string value
// -------------------------------------------------------------------------------------------- 
void Movie::setDirector(string director)
{
	this->director = director;
}
// ------------------------------------getYear----------------------------------------------- 
// Description
// get Year number
// preconditions: immutable object 
// postconditions: the return of year value
// -------------------------------------------------------------------------------------------- 
int Movie::getYear() const
{
	return year;
}
// ------------------------------------setYear----------------------------------------------- 
// Description
// set Year number
// preconditions: value typeof value 
// postconditions: sets the new year value
// -------------------------------------------------------------------------------------------- 
void Movie::setYear(int year)
{
	this->year = year;
}
// ------------------------------------getMovieType----------------------------------------------- 
// Description
// get MovieType character
// preconditions: immutable object 
// postconditions: the return of getMovieType value
// -------------------------------------------------------------------------------------------- 
char Movie::getMovieType() const
{
	return movieType;
}
// ------------------------------------setMovieType----------------------------------------------- 
// Description
// set MovieType
// preconditions: value typeof value  
// postconditions: sets new setMovieType value
// -------------------------------------------------------------------------------------------- 
void Movie::setMovieType(char movieType)
{
	this->movieType = movieType;
}
// ------------------------------------getMajorActor----------------------------------------------- 
// Description
// get MajorActor name
// preconditions: immutable object 
// postconditions: the return of getMajorActor value
// -------------------------------------------------------------------------------------------- 
string Movie::getMajorActor() const
{
	return majorActor;
}
// ------------------------------------setMajorActor----------------------------------------------- 
// Description
// set MajorActor name
// preconditions: immutable object 
// postconditions: sets new setMajorActor value
// -------------------------------------------------------------------------------------------- 
void Movie::setMajorActor(string majorActor)
{
	this->majorActor = majorActor;
}
// ------------------------------------getMonth----------------------------------------------- 
// Description
// get Month number
// preconditions: value typeof value 
// postconditions: returns the getMonth value
// -------------------------------------------------------------------------------------------- 
int Movie::getMonth() const
{
	return month;
}
// ------------------------------------setMonth----------------------------------------------- 
// Description
// se tMonth number
// preconditions: value typeof value 
// postconditions: returns the setMonth value
// -------------------------------------------------------------------------------------------- 
void Movie::setMonth(int month)
{
	this->month = month;
}
// ------------------------------------Assignment Operator----------------------------------------------- 
// Description
// Assignment Operator: sets all movies types for type of movie 
// preconditions: object for the output and the movies
// postconditions: overloaded object in respect to the process and 
// outputs stores movie properties
// -------------------------------------------------------------------------------------------- 
Movie& Movie::operator=(Movie& obj)
{
	obj.setTitle(title);
	obj.setYear(year);
	obj.setDirector(director);
	obj.setMovieType(movieType);

	return obj;
}
// ------------------------------------OutStream Overload----------------------------------------------- 
// Description
// OutStream Overload: display the values in repect the properties of movies 
// preconditions: object for the output and the movies
// postconditions: overloaded ouput in respect to the process and 
// outputs stores movie properties
// -------------------------------------------------------------------------------------------- 
ostream& operator<<(ostream& outStream, const Movie& rhs)
{
	rhs.displayType(outStream);
	return outStream;
}
