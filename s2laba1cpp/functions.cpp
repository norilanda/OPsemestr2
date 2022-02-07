#include "functions.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void print_file(string path)
{
	ifstream inFile;
	inFile.open(path);
	if (!inFile.is_open())
	{
		cout << "Cannot open the file!";
	}
	else
	{
		while (!inFile.eof())
		{
			string stringOfText;
			getline(inFile, stringOfText);
			cout << stringOfText << '\n';
		}		
	}
	inFile.close();
}
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
		string stringOfText;
		cout << "Enter your strings. To finish press 'Enter' twice\n";
		getline(cin, stringOfText);
		while (!stringOfText.empty())
		{
			outFile << stringOfText << '\n';
			getline(cin, stringOfText);
		}
	}
	outFile.close();
}