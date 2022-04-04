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
	automobile.releaseDate = init_date();
	cout << "Enter sale date in this format dd.mm.yyyy: ";
	automobile.saleDate = init_date();
	check_sale_date_is_not_smaller_than_release_date(automobile);
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

Date init_date()
{
	Date date;
	cin >> date.day; cin.ignore();
	cin >> date.month; cin.ignore();
	cin >> date.year; cin.ignore();
	while (date.day < 1 || date.day>31 || date.month < 1 || date.month>12 || date.year < 0)
	{
		cout << "Your date is incorrect! Try again! Enter date in format dd.mm.yyyy: ";
		cin >> date.day; cin.ignore();
		cin >> date.month; cin.ignore();
		cin >> date.year; cin.ignore();
	}
	return date;
}

void check_sale_date_is_not_smaller_than_release_date(Automobile& automobile)
{
	int year_factor = 365;
	int month_factor = 31;
	int release_days = automobile.releaseDate.day + automobile.releaseDate.month * month_factor + automobile.releaseDate.year * year_factor;
	int sale_days = automobile.saleDate.day + automobile.saleDate.month * month_factor + automobile.saleDate.year * year_factor;
	while (sale_days < release_days)
	{
		cout << "Sale date can't be smaller than release date. Please, enter correct dates.\n";
		cout << "Release date dd.mm.yyyy: ";
		automobile.releaseDate = init_date();
		cout << "Sale date dd.mm.yyyy: ";
		automobile.saleDate = init_date();
		release_days = automobile.releaseDate.day + automobile.releaseDate.month * month_factor + automobile.releaseDate.year * year_factor;
		sale_days = automobile.saleDate.day + automobile.saleDate.month * month_factor + automobile.saleDate.year * year_factor;
	}
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
	while (n < 0)
	{
		cout << "Number of the automobiles can't be negative. Try again! ";
		cin >> n; cin.ignore();
	}
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
	bool isLess = false;
	int yearDifference = automobile.saleDate.year - automobile.releaseDate.year;
	int monthDifference = 3;
	if (yearDifference == 1)
		monthDifference = 12 - automobile.releaseDate.month + automobile.saleDate.month;
	else if (yearDifference == 0)
		monthDifference = automobile.saleDate.month - automobile.releaseDate.month;
	if (monthDifference == 2)
	{ 
		if (automobile.saleDate.day <= automobile.releaseDate.day)
			isLess = true;
	}
	else if(monthDifference < 2)
		isLess = true;
	return isLess;
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