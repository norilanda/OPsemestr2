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
	int number = rand() % (rangeMax - rangeMin + 1) + rangeMin;
	return number;
}
void TVector::display()
{
	cout << x << " ; ";
}


R2::R2(double x, double y) : TVector(x)
{
	this->y = y;
}
R2::R2(int rangeMin, int rangeMax) : TVector(rangeMin, rangeMax)
{
	y = generate_number(rangeMin, rangeMax);
}
void R2::display()
{
	TVector::display();
	cout << y << "; ";
}
bool R2::is_parallel(TVector& v)
{
	return true;
}
bool R2::is_perpendicular(TVector& v)
{
	return true;
}
double R2::calc_length()
{
	return 0;
}