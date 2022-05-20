#include <iostream>
#include <cmath>
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
	int number = ((double)rand() / RAND_MAX) * (rangeMax - rangeMin) + rangeMin;
	return number;
}