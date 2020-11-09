#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include "Inode.h"

#include <map> 
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std;

class FileSystem {

private:
	//directory for inode array
	struct Directory {
		int inodeID = -1;
		int size;
	};
	//map data structure for the inode
	//directory for system
	map<int, Inode*> inodes;
	map<string, Directory*> directory;
	Disk* disk;
	int id;


public: 
	FileSystem();
	~FileSystem();
	//create 
	bool Create(string fileName, int blockNum);
	bool Add(string fileName, int blockNum);
	//delete 
	bool DeleteFile(string fileName);
	bool DeleteBlock(string fileName, int blockNum);
	
	//snapshot
	void dumpAll();
	void dump();

};
#endif