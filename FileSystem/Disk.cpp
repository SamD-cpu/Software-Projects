#include "Disk.h"

Disk::Disk()
{
	unalloc = MAX_BLOCKS;
	for (int i = 0; i < MAX_BLOCKS; i++)
	{
		this->disk[i] = new Structure();
	}
}

Disk::~Disk()
{
	for (int i = 0; i < MAX_BLOCKS; i++) 
	{
		delete this->disk[i];
		this->disk[i] = NULL;
	}
}

bool Disk::search(int num, vector<Structure*>& blocks)
{
	if (this->unalloc < num) {
		cerr << "FULL DISK " << endl;
		return false;
	}

	for (int i = 0; i < MAX_BLOCKS; i++) {
		if (blocks.size() == num) {
			return true;
		}
		Structure* current = this->disk[i];
		if (current->isEmpty()) {
			current->write("ALLOCATED");
			blocks.push_back(current);//visitied list
		}
	}
	if (blocks.size() == num) {
		return true;
	}
	return false;
}

void Disk::dump()
{
	Structure* block = this->disk[0];
	cout << "{";
	if (block->isEmpty()) 
		cout << "O";
	else 
		cout << "X";
	

	for (int i = 1; i < MAX_BLOCKS; i++) {
		block = this->disk[i];
		if (block->isEmpty())
			cout << ", O";
		else 
			cout << ", X";
	}
	cout << "}" << endl;
}
