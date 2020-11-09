#include "FileSystem.h"

FileSystem::FileSystem()
{
	disk = new Disk();
	id = 0;
}

FileSystem::~FileSystem()
{
	delete this->disk;
}

bool FileSystem::Create(string fileName, int blockNum)
{
	map<string, Directory*>::iterator itr = this->directory.find(fileName);
	if (itr != this->directory.end()) {//iterate to find file
		cerr << "FILE EXISTS" << endl;
		this->dump();
		return false;
	}

	Inode* node = new Inode();
	if (!node->addBlock(blockNum, this->disk)) {//adds new block
		delete node;
		return false;
	}

	Directory* diskDirectory = new Directory{ this->id, blockNum};
	this->inodes[this->id] = node;
	this->directory[fileName] = diskDirectory;//creates directory
	this->id++;
	return true;
}

bool FileSystem::Add(string fileName, int blockNum)
{
	map<string, Directory*>::iterator itr = this->directory.find(fileName);
	if (itr == this->directory.end()) {
		cerr << "NO FILE FOUND" << endl;
		return false;
	}

	int id = this->directory[fileName]->inodeID;
	if (!(this->inodes[id]->addBlock(blockNum, this->disk))) {//add file in mem
		cerr << "COULD NOT ADD" << endl;
		return false;
	}
	return true;
}

bool FileSystem::DeleteFile(string fileName)
{
	map<string, Directory*>::iterator itr = this->directory.find(fileName);
	if (itr == this->directory.end()) {
		cerr << "NO FILE FOUND" << endl;
		return false;
	}

	int id = this->directory[fileName]->inodeID;
	delete this->inodes[id];
	this->inodes.erase(id);

	delete this->directory[fileName];
	this->directory.erase(fileName);
	return true;
}

bool FileSystem::DeleteBlock(string fileName, int blockNum)
{
	map<string, Directory*>::iterator itr = this->directory.find(fileName);
	if (itr == this->directory.end()) {
		cerr << "NO FILE FOUND" << endl;
		return false;
	}

	int id = this->directory[fileName]->inodeID;
	this->inodes[id]->deleteBlock(blockNum, this->disk);
	this->directory[fileName]->size = this->inodes[id]->getSize();
	return true;
}

void FileSystem::dumpAll()
{
	cout << endl;
	cout << "File in Storage" << endl;
	this->dump();
	cout << endl;
	cout << "Disk Space :: (X = Allocated, O = Free space)" << endl;
	this->disk->dump();
}


void FileSystem::dump()
{
	for (map<string, Directory*>::
		iterator itr = this->directory.begin();
		itr != this->directory.end(); ++itr)
	{
		int id = itr->second->inodeID;
		Inode* inode = this->inodes[id];
		cout << id << " "
			<< inode->getMode() << " "
			<< inode->getUID() << " "
			<< inode->getGID() << " "
			<< inode->getSize() << " "
			<< inode->getBlockCount() << " "
			<< inode->currentDateTime() << " "
			<< itr->first << endl;
	}
}
