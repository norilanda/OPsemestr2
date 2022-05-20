#include <iostream>
#include <vector>
#include "TVector.h"
#include "Work_with_vectors.h"

using namespace std;

void create_arr_of_vectors(vector <TVector*>& arr, int n, int m)
{
	cout << "Random or manually? Random - enter 'r', manually - enter 'm'\n";
	char mode;
	cin >> mode;
	while (mode != 'r' && mode != 'm')
	{
		cout << "Try again! ";
		cin >> mode;
	}
	if (mode == 'r')
	{
		int rangeMin, rangeMax;
		cout << "Enter range (first min than max value): ";
		cin >> rangeMin;
		cin >> rangeMax;
		for (int i = 0; i < n; i++)
			arr.push_back(new R2(rangeMin, rangeMax));
		for (int i = 0; i < m; i++)
			arr.push_back(new R3(rangeMin, rangeMax));
	}
	else
	{
		double x, y, z;
		cout << "R2:\n";
		for (int i = 0; i < n; i++)
		{
			cout << "x, y: ";
			cin >> x; 
			cin >> y;
			arr.push_back(new R2(x, y));
		}
		cout << "R3:\n";
		for (int i = 0; i < m; i++)
		{
			cout << "x, y, z: ";
			cin >> x;
			cin >> y;
			cin >> z;
			arr.push_back(new R3(x, y, z));
		}
	}
}
void display_arr_of_vectors(vector <TVector*> arr, int n, int m)
{
	cout << "R2 vectors: \n";
	for (int i = 0; i < n; i++)
	{
		arr[i]->display();
		cout << "| length = " << arr[i]->calc_length() << "\n";		
	}
	cout << "R3 vectors: \n";
	for (int i = n; i < n + m; i++)
	{
		arr[i]->display();
		cout << "| length = " << arr[i]->calc_length() << "\n";
	}
}
void display_vector(vector <TVector*> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i]->display();
		cout << "| length = " << arr[i]->calc_length() << "\n";
	}
}

double calc_sum_of_parallels(vector <TVector*> arr, int n, int m, vector <TVector*>& arrPar)
{
	double sum = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[0]->is_parallel(arr[i]))
		{
			sum += arr[i]->calc_length();
			arrPar.push_back(arr[i]);
		}			
	}
	return sum;
}
double calc_sum_of_perpendicular(vector <TVector*> arr, int n, int m, vector <TVector*>& arrPerp)
{
	double sum = 0;
	for (int i = n + 1; i < n + m; i++)
	{
		if (arr[n]->is_perpendicular(arr[i]))
		{
			sum += arr[i]->calc_length();
			arrPerp.push_back(arr[i]);
		}
	}
	return sum;
}