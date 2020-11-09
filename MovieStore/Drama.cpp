#include "Drama.h"
#include <iostream>


void Drama::displayType(ostream& outStream) const
{
	outStream << getDirector() << " " << getTitle();
}

Drama::Drama(char movieType)
{
	setMovieType(movieType);
}

void Drama::setData(ifstream& infile)
{
	Movie::setData(infile);

	string year;

	getline(infile, year);
	Movie::reduce(year);
	setYear(stoi(year));
}

bool Drama::operator==(const Movie& rhs)
{
	return (getDirector() == rhs.getDirector() && getTitle() == rhs.getTitle());
}

bool Drama::operator!=(const Movie& rhs)
{
	return !(this == &rhs);
}

bool Drama::operator<(const Movie& rhs)
{
	if (getDirector() != rhs.getDirector())
	{
		return getDirector() < rhs.getDirector();
	}
	else
	{
		return getTitle() < rhs.getTitle();
	}
}

bool Drama::operator>(const Movie& rhs)
{
	if (getDirector() > rhs.getDirector())
	{
		return true;
	}
	else
	{
		if (getTitle() > rhs.getTitle())
		{
			return true;
		}
	}
	return false;
}
