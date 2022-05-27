#include <iostream>
#include <stdlib.h>
#include "Functions.h"

using namespace std;

void init_arr_size(int& n)
{
	cout << "Enter number of chars: ";
	cin >> n;
	while (n<1)
	{
		cout << "Try again: ";
		cin >> n;
	}
}
vector <char> generate_chars(int n)
{
	int rangeMin = 32;
	int rangeMax = 256;
	vector <char> arr(n);
	for (int i=0;i<n;i++)
		arr[i] = rand() % (rangeMax - rangeMin + 1) + rangeMin;
	return arr;
}

