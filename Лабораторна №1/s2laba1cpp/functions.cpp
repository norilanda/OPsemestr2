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
		string stringOfText;
		char keyToFinishTypingText = 24;
		cout << "Enter your strings. To finish entering a string press 'Enter'.\n"<<
			"To finish typing text press combination 'Ctrl + x' (hold 'Ctrl' and press 'x')\n";
		getline(cin, stringOfText);
		while (stringOfText[0]!= keyToFinishTypingText)
		{
			outFile << stringOfText << '\n';
			getline(cin, stringOfText);
		}
	}
	outFile.close();
}
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
		cout << '\n';
	}
	inFile.close();
}
string check_last_char(string str)
{
	if (!str.empty())
	{
		string charsToCheck = " .,";
		size_t len = str.length();
		char lastChar = str[len - 1];
		size_t pos = charsToCheck.find(lastChar);
		if (pos == string::npos)
		{
			str = "-";
		}
	}
	return str;
}
void rewrite_text_into_new_file(std::string path, std::string newPath)
{
	ifstream inFile;
	ofstream newFile;
	inFile.open(path);
	newFile.open(newPath);
	if (!inFile.is_open() || !newFile.is_open())
	{
		cout << "Cannot open the file!";
	}
	else
	{
		while (!inFile.eof())
		{
			string tempString;
			getline(inFile, tempString);
			tempString = check_last_char(tempString);
			newFile << tempString << '\n';
		}
	}
	inFile.close();
	newFile.close();
}