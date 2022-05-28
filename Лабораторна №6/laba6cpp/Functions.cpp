#include <iostream>
#include <stdlib.h>
#include <string>
#include "Functions.h"

using namespace std;

vector <char> enter_char_arr(int n)
{
	vector <char> arr;
	cout << "generate - enter 'g', manually - enter 'm': ";
	char mode;
	cin >> mode; cin.ignore();
	while (mode != 'g' && mode != 'm')
	{
		cout << "Try again! ";
		cin >> mode; cin.ignore();
	}
	if (mode == 'm')
		arr = init_chars(n);
	else
	{
		arr = generate_chars(n);
		cout << "Created array:\n";
		print_arr(arr);
	}
	return arr;
}

void init_arr_size(int& n)
{
	cout << "Enter number of chars: ";
	cin >> n; cin.ignore();
	while (n<1)
	{
		cout << "Try again: ";
		cin >> n; cin.ignore();
	}
}
vector <char> generate_chars(int n)
{
	int rangeMin = 32;
	int rangeMax = 126;
	vector <char> arr(n);
	for (int i=0;i<n;i++)
		arr[i] = rand() % (rangeMax - rangeMin + 1) + rangeMin;
	return arr;
}

void print_arr(vector <char> arr)
{
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i];
	cout << "\n";
}

vector <char> init_chars(int n)
{
	vector <char> arr(n);
	cout << "Enter chars without space: ";
	string str;
	getline(cin, str);
	for (int i = 0; i <n; i++)
		arr[i] = str[i];
	return arr;
}


