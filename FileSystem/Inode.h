#ifndef INODE_H
#define INODE_H 

#include <time.h> 
#include <vector> 
#include <iostream> 
#include <string>
#include <ctime>
#include "date.h"
#include "Disk.h"  
#include <stdio.h>
#include <time.h>

using namespace std;

class Inode {
public:
	Inode();
	Inode(string mode);
	~Inode();

	int getBlockCount();
	string getMode();
	string getUID();
	string getGID();
	int getSize();
	const string currentDateTime();

	bool addBlock(int numBlocks, Disk* disk);
	bool deleteBlock(int numBlocks, Disk* disk);

private:
	//update the file modificaitons
	void updateModifications();
	void dump();

	string mode; // file or directory 
	string uid; // User id
	string gid; // global user

	time_t atime; // Access time 
	time_t ctime; // Create time 
	time_t mtime; // Modify time 
	int size;     // Integer size in bytes 
	int blockCount; // Number of blocks allocated
	Structure* directBlocks[10]; // 10 disk block numbers
	Structure* singleIND; //Block number
	Structure* doubleIND;//Block number
	Structure* tripleIND;//Block number

};
#endif 