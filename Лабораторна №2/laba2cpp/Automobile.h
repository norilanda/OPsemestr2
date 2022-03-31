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
void print_date(Date date);
std::vector <Automobile> create_automobile_list();
void print_automobile_list(std::vector <Automobile> automobileList);
bool is_less_than_two_month_between_release_and_sale(Automobile automobile);
std::vector <Automobile> create_list_of_two_month_automobile(std::vector <Automobile> oldList);