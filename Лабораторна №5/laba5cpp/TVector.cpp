#include <iostream>
#include <cmath>
#include <stdlib.h>     /* srand, rand */
#include "TVector.h"

using namespace std;

TVector::TVector(double x)
{
	this->x = x;
}
TVector::TVector(int rangeMin, int rangeMax)
{
	x = generate_number(rangeMin, rangeMax);
}
int TVector::generate_number(int rangeMin, int rangeMax)
{
	int number = rand() % (rangeMax - rangeMin) + rangeMin;
	return number;
}
void TVector::display()
{
	cout << x << " ; ";
}