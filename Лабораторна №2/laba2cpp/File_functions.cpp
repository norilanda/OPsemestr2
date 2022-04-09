#include <iostream>
#include <string>
#include <fstream>
#include "Automobile.h"

using namespace std;

char choose_file_mode()
{
	cout << "Do you want to create a new file or just to add new information?\nTo create a new file enter 'n', to add information enter 'a': ";
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
		int n;
		vector <Automobile> automobileList;
		cout << "Enter number of the automobiles: ";
		cin >> n; cin.ignore(); cout << endl;
		for (int i = 0; i < n; i++)
		{
			Automobile automobile = init_automobile();
			automobileList.push_back(automobile);
			cout << endl;
		}
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
	for (int i = 0; i < automobileList.size(); i++)
	{
		print_automobile(automobileList[i]);
		cout << endl;
	}
}

void write_new_file_of_automobile(string pathOld, string pathNew)
{
	vector <Automobile> newtList;
	ifstream inFile(pathOld, ios::binary);
	if (!inFile.is_open())
		cout << "Cannot open the file!\n";
	else
	{
		Automobile automobile;
		while (inFile.read((char*)&automobile, sizeof(Automobile)))
			if (is_less_than_two_month_between_release_and_sale(automobile))
				newtList.push_back(automobile);
	}
	inFile.close();
	ofstream outFile(pathNew, ios::binary);
	if (!outFile.is_open())
		cout << "Cannot open the file!\n";
	else
	{
		for (int i = 0; i < newtList.size(); i++)
			outFile.write((char*)&newtList[i], sizeof(Automobile));
	}
	outFile.close();
}

void display_automobiles_released_not_earlier_than_year(string path)
{
	int year;
	cout << "Enter the year to see automobiles which have not been released before this year: ";
	cin >> year; cin.ignore();
	vector <Automobile> automobileList = read_file_into_list(path);
	for (int i = 0; i < automobileList.size(); i++)
	{
		if (automobileList[i].releaseDate.year >= year)
		{
			print_automobile(automobileList[i]);
			cout << endl;
		}
	}
}