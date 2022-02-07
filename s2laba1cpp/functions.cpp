#include "functions.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void create_file(string path)
{
	ofstream outFile;
	outFile.open(path);
	if (!outFile.is_open())
	{
		cout << "Cannot open the file!";
	}
	else
	{

	}
}