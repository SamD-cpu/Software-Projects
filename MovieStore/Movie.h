// ------------------------------------------------ Movie.h -------------------------------------------------------

// Samuel Debesai

// --------------------------------------------------------------------------------------------------------------------
// Purpose - create class to handle the manipulation of class objects
// -------------------------------------------------------------------------------------------------------------------- 

// --------------------------------------------------------------------------------------------------------------------
#include <sstream>
#include <ostream>
#ifndef Movie_H
#define Movie_H

using namespace std;

class Movie
{

public:
	static void reduce(string& inStream);

	friend ostream& operator<<(ostream& outStream, const Movie& rhs);

// ------------------------------------DisplayType----------------------------------------------- 
// Description
// DisplayType: displays the correct output for the constraints of type of movieType 
// preconditions: must be of valid types
// postconditions: returns ostream value of movie type
// -------------------------------------------------------------------------------------------- 
	virtual void displayType(ostream& stream) const = 0;


	virtual void setData(ifstream& infile);


	int getStock() const;
	void setStock(int);

	string getTitle()const;//returns the title of the movie
	void setTitle(string); //sets the Title

	string getDirector()const;//the director gets returned
	void setDirector(string);//sets the name of the director

	int getYear()const;//get the year when the movie was made
	void setYear(int);//sets the year when the movie was made

	char getMovieType()const;//get the type of the movie
	void setMovieType(char);//set the type of the movie

	string getMajorActor() const;
	void setMajorActor(string);

	int getMonth() const;//get the month
	void setMonth(int);//set the month

	virtual Movie& operator=(Movie&);//copy constructor


	virtual bool operator==(const Movie& rhs) = 0;//checks the equality of two movies
	virtual bool operator!=(const Movie& rhs) = 0;
	virtual bool operator<(const Movie& rhs) = 0;
	virtual bool operator>(const Movie& rhs) = 0;

private:
	int stock; //number of items of a given title
	string title; //title of the move
	string director;//name of the director
	int year;//the year the movie was made
	char movieType;//the type of the movie
	string majorActor;//the name of major actors
	int month;//month of release

};

#endif /* Movie_h */
