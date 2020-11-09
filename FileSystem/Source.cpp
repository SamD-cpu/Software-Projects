#include <string> 
#include <iostream> 
#include "FileSystem.h"

using namespace std;

int main() {
	string input;
	FileSystem* fileSystem = NULL;


	while (true)
	{
		cout << ">> ";
		cin >> input;
		if (input == "exit")
		{
			fileSystem->dumpAll();
			break;
		}
		else if (input == "PR")
		{
			fileSystem->dumpAll();
		}
		else if (input == "FM")
		{
			if (fileSystem != NULL)
			{
				cerr << "FILE OPENED" << endl;
			}
			else {
				fileSystem = new FileSystem();
			}
		}
		else {
			if (fileSystem == NULL)
			{
				cerr << "FILE NOT CREATED" << endl;
			}
			else {
				string fileName;
				int num;

				if (input == "NF")
				{
					cin >> fileName >> num;
					fileSystem->Create(fileName, num);
				}
				else if (input == "MF")
				{
					cin >> fileName >> num;
					fileSystem->Add(fileName, num);

				}
				else if (input == "DF")
				{
					cin >> fileName;
					fileSystem->DeleteFile(fileName);

				}
				else if (input == "DB")
				{
					cin >> fileName >> num;
					fileSystem->DeleteBlock(fileName, num);

				}
			}
		}
	}
	return 0;
}