#ifndef DISK_H
#define DISK_H

#include "Structure.h" 
#include <iostream>

using namespace std;

const int MAX_BLOCKS = 1000;//amount of blocks

class Disk {
public:
	Disk();
	~Disk();

	//searches for allocated disk location within blocks of mem
	bool search(int num, vector<Structure*>& blocks);  
	//snapshot of the memory witholding the data within the mem
	void dump();


private:
	Structure* disk[MAX_BLOCKS];
	//unallocated locations
	int unalloc;
};

#endif