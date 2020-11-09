#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <string> 
#include <vector>
using namespace std;

const int SIZE = 524288;

class Structure {

public:

	 Structure();
	~Structure();

	bool isEmpty();

	bool write(string str);
	void unalloc();

private:
	vector<int> indirect;
	string str;
};

#endif
