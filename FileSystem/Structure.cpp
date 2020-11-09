#include "Structure.h"

Structure::Structure()
{
	str = "";
}

Structure::~Structure()
{
}

bool Structure::isEmpty()
{
	return str == "";
}

bool Structure::write(string str)
{
	this->str = str;
	return true;
}

void Structure::unalloc()
{
	this->str = "";
}
