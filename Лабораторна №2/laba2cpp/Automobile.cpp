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

vector <Automobile> create_automobile_list()
{
	int n;
	std::vector <Automobile> automobileList;
	cout << "Enter number of the automobiles: ";
	cin >> n; cin.ignore();
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		Automobile automobile = init_automobile();
		automobileList.push_back(automobile);
		cout << endl;
	}
	cout << "--------------------------------------------------\n";
	return automobileList;
}

void print_automobile_list(vector <Automobile>automobileList)
{
	for (int i = 0; i < automobileList.size(); i++)
	{
		print_automobile(automobileList[i]); 
		cout << endl;
	}
}

bool is_less_than_two_month_between_release_and_sale(Automobile automobile)
{
	bool is_less = false;
	int year_difference = automobile.saleDate.year - automobile.releaseDate.year;
	if (year_difference < 2)
	{
		int month_difference;
		if (year_difference == 1)
			month_difference = 12 - automobile.releaseDate.month + automobile.saleDate.month;
		else if (year_difference == 0)
			month_difference = automobile.saleDate.month - automobile.releaseDate.month;
		if (month_difference == 2)
		{ 
			if (automobile.saleDate.day <= automobile.releaseDate.day)
				is_less = true;
		}
		else if(month_difference<2)
			is_less = true;
	}
	return is_less;
}

vector <Automobile> create_list_of_two_month_automobile(vector <Automobile> oldList)
{
	vector <Automobile> newList;
	for (int i = 0; i < oldList.size(); i++)
	{
		if(is_less_than_two_month_between_release_and_sale(oldList[i]))
			newList.push_back(oldList[i]);
	}
	return newList;
}