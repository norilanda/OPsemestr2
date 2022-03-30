#include <iostream>
#include <string>
#include <fstream>
#include "Automobile.h"

using namespace std;

char choose_file_mode()
{
	cout << "Do you want to create a new file or just to add new information?\n"
		<<" To create a new file enter 'n', to add information enter 'a': ";
	char answer; cin >> answer;
	while (answer != 'a' && answer != 'n')
	{
		cout << "Wrong letter! Try again! ";
		cin >> answer;
	}
	return answer;
}

void write_automobiles_into_file(string path)
{
	char answer = choose_file_mode();
	ofstream outFile;
	if (answer == 'n')
		outFile.open(path, ios::binary);
	else
		outFile.open(path, ios::binary|ios::app);
	if (!outFile.is_open())
		cout << "Cannot open the file!\n";
	else
	{
		vector <Automobile> automobileList = create_automobile_list();
		for (int i = 0; i < automobileList.size(); i++)
			outFile.write((char*)&automobileList[i], sizeof(Automobile));
	}
	outFile.close();	
}

vector <Automobile> read_file_into_list(string path)
{
	vector <Automobile> automobileList;
	ifstream inFile(path, ios::binary);
	if (!inFile.is_open())
		cout << "Cannot open the file!\n";
	else
	{
		Automobile automobile;
		while (inFile.read((char*)&automobile, sizeof(Automobile)))
			automobileList.push_back(automobile);
	}
	inFile.close();
	return automobileList;
}

void display_file_information(string path)
{
	vector <Automobile> automobileList = read_file_into_list(path);
	print_automobile_list(automobileList);
}

void write_new_file_of_automobile(string pathOld, string pathNew)
{

}