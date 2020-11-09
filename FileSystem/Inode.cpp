#include "Inode.h"

Inode::Inode()
{
mode = "- rwxr--r--";
uid = "CSS430";
gid = "CSS430";
atime = time(0);
ctime = time(0);
mtime = time(0);
size = 0;
blockCount = 0;
singleIND = NULL;
doubleIND = NULL;
tripleIND = NULL;

for (int i = 0; i < 10; i++) {
	this->directBlocks[i] = NULL;
}
}

Inode::Inode(string mode):mode(mode)
{
	uid = "CSS430";
	gid = "CSS430";
	atime = time(0);
	ctime = time(0);
	mtime = time(0);
	size = 0;
	blockCount = 0;
	singleIND = NULL;
	doubleIND = NULL;
	tripleIND = NULL;

	for (int i = 0; i < 10; i++) {
		this->directBlocks[i] = NULL;
	}
}

Inode::~Inode()
{
	if (this->singleIND != NULL) {
		this->singleIND->unalloc();
		this->singleIND = NULL;
	}

	if (this->doubleIND != NULL) {
		this->doubleIND->unalloc();
		this->doubleIND = NULL;
	}

	if (this->tripleIND != NULL) {
		this->tripleIND->unalloc();
		this->tripleIND = NULL;
	}

	for (int i = 0; i < 10; i++) {
		if (this->directBlocks[i] != NULL) {
			this->directBlocks[i]->unalloc();
			this->directBlocks[i] = NULL;
		}
	}
}

int Inode::getBlockCount()
{
	return this->blockCount;
}

string Inode::getMode()
{
	return this->mode;
}

string Inode::getUID() {
	return this->uid;
}

string Inode::getGID() {
	return this->gid;
}

int Inode::getSize() {
	return this->size;
}

const string Inode::currentDateTime()
{
	//using date.h file OSS MIT License https://howardhinnant.github.io/date/date.html
	string s = date::format("%F %T", std::chrono::system_clock::now());
	return s;
}

bool Inode::addBlock(int numBlocks, Disk* disk)
{
	vector<Structure*> blocks;
	if (!(disk->search(numBlocks, blocks))) 
	{
		cerr << "NOT ENOUGH SPACE TO ALLOCATE" << endl;
		return false;
	}
	int count = this->blockCount + numBlocks;
	if (count <= 10) 
	{ 
		for (int i = this->blockCount; i < count; i++) 
		{
			this->directBlocks[i] = blocks[i - blockCount];
		}
	}
	else {
		cerr << "FILE SIZE EXCEEDS LIMIT" << endl;
		for (int i = 0; i < numBlocks; i++) {
			blocks[i]->unalloc();
		}
		return false;
	}

	this->blockCount += numBlocks;
	this->updateModifications();

	return true;
}

bool Inode::deleteBlock(int numBlocks, Disk* disk)
{
	if (this->blockCount < numBlocks) 
	{
		cerr << "EROR: File smaller than lower limit" << endl;
		return false;
	}

	for (int i = 0; i < numBlocks; i++) 
	{
		int cIndex = this->blockCount - 1 - i;
		this->directBlocks[cIndex]->unalloc();
		this->directBlocks[cIndex] = NULL;
	}

	this->blockCount -= numBlocks;
	this->updateModifications();
	return true;
}

void Inode::updateModifications()
{
	this->atime = time(0);
	this->mtime = time(0);
	this->size = 524288 * this->blockCount;
}

void Inode::dump()
{
	for (int i = 0; i < this->blockCount; i++)
	{
		cout << "index = " << i << ": "<< this->directBlocks[i]->isEmpty() << endl;
	}
}
