#include <iostream>
#include <vector>
#include "Automobile.h"

using namespace std;
Automobile init_automobile()
{
	Automobile automobile;
	cout << "Enter automobile's name: ";
	cin.getline(automobile.name, sizeof(automobile.name));
	automobile.releaseDate = init_date("Release");
	automobile.saleDate = init_date("Sale");
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

Date init_date(string dateType)
{
	Date date;
	const int MINDATE = 1;
	const int MAXMONTH = 12;
	int MAXDAY;
	do
	{
		cout << dateType <<" date dd.mm.yyyy:  ";
		cin >> date.day; cin.ignore();
		cin >> date.month; cin.ignore();
		cin >> date.year; cin.ignore();
		if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)
			MAXDAY = 30;
		else if (date.month == 2)
			MAXDAY = (date.year % 4) == 0 ? 29 : 28;
		else
			MAXDAY = 31;
	} while (date.day < MINDATE || date.day>MAXDAY || date.month < MINDATE || date.month> MAXMONTH || date.year < MINDATE);
	return date;
}

void check_sale_date_is_not_smaller_than_release_date(Automobile& automobile)
{
	const int YFactor = 380;
	const int MFACTOR = 31;
	int release_days = automobile.releaseDate.day + automobile.releaseDate.month * MFACTOR + automobile.releaseDate.year * YFactor;
	int sale_days = automobile.saleDate.day + automobile.saleDate.month * MFACTOR + automobile.saleDate.year * YFactor;
	while (sale_days < release_days)
	{
		cout << "Sale date can't be smaller than release date. Please, enter correct dates.\n";
		automobile.releaseDate = init_date("Release");
		automobile.saleDate = init_date("Sale");
		release_days = automobile.releaseDate.day + automobile.releaseDate.month * MFACTOR + automobile.releaseDate.year * YFactor;
		sale_days = automobile.saleDate.day + automobile.saleDate.month * MFACTOR + automobile.saleDate.year * YFactor;
	}
}

void print_date(Date date)
{
	cout.fill('0');
	cout.width(2); cout << date.day << ".";
	cout.width(2); cout << date.month << ".";
	cout.width(4); cout << date.year;
	cout.fill(' ');
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