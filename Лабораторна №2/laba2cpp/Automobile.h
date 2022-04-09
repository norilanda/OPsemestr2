#pragma once
#include <vector>

struct Date
{
	int day;
	int month;
	int year;
};
struct Automobile
{
	char name[30];
	Date releaseDate;
	Date saleDate;
};
Automobile init_automobile();
void print_automobile(Automobile automobile);
Date init_date(std::string);
void check_sale_date_is_not_smaller_than_release_date(Automobile& automobile);
void print_date(Date date);
bool is_less_than_two_month_between_release_and_sale(Automobile automobile);