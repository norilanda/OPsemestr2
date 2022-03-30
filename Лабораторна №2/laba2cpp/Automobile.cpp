#include <iostream>
#include <vector>
#include "Automobile.h"

using namespace std;
Automobile init_automobile()
{
	Automobile automobile;
	cout << "Enter automobile's name: ";
	cin.getline(automobile.name, sizeof(automobile.name));
	cout << "Enter release date in this format dd.mm.yyyy: ";
	cin >> automobile.releaseDate.day; cin.ignore();
	cin >> automobile.releaseDate.month; cin.ignore();
	cin >> automobile.releaseDate.year; cin.ignore();
	cout << "Enter sale date in this format dd.mm.yyyy: ";
	cin >> automobile.saleDate.day; cin.ignore();
	cin >> automobile.saleDate.month; cin.ignore();
	cin >> automobile.saleDate.year; cin.ignore();
	return automobile;
}
void print_automobile(Automobile automobile)
{
	cout << "Automobile's name: " << automobile.name << endl;
	cout << "Release date: ";
	print_date(automobile.releaseDate);
	cout << endl << "Sale date: ";
	print_date(automobile.saleDate);
	cout << endl;
}
void print_date(Date date)
{
	if (date.day < 10)
		cout << "0" << date.day << ".";
	else
		cout << date.day << ".";
	if (date.month < 10)
		cout << "0" << date.month << ".";
	else
		cout << date.month << ".";
	cout << date.year;
}
std::vector <Automobile> create_automobile_list()
{
	int n;
	std::vector <Automobile> automobileList;
	cout << "Enter number of the automobiles: ";
	cin >> n; cin.ignore();
	for (int i = 0; i < n; i++)
	{
		Automobile automobile = init_automobile();
		automobileList.push_back(automobile);
		cout << endl;
	}
	return automobileList;
}
void print_automobile_list(std::vector <Automobile>automobileList)
{
	for (int i = 0; i < automobileList.size(); i++)
	{
		print_automobile(automobileList[i]);
		cout << endl;
	}
}