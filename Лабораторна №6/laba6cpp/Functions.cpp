#include <iostream>
#include <stdlib.h>
#include "Functions.h"

using namespace std;

vector <char> generate_chars(int n)
{
	int rangeMin = 32;
	int rangeMax = 256;
	vector <char> arr(n);
	for (int i=0;i<n;i++)
		arr[i] = rand() % (rangeMax - rangeMin + 1) + rangeMin;
	return arr;
}

