#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>     /* srand, rand */
#include "TVector.h"

using namespace std;
//vectors
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
	cout << setw(4) << x << " ; ";
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
	cout << setw(4) << y << "; ";
}
bool R2::is_parallel(TVector* ptrTVector)
{
	if ((x / ptrTVector->x) == (y / ((R2*)ptrTVector)->y))
		return true;
	return false;
}
bool R2::is_perpendicular(TVector* ptrTVector)
{
	double dotProduct = x * ptrTVector->x + y * ((R2*)ptrTVector)->y;
	return !dotProduct;
}
double R2::calc_length()
{
	return sqrt(pow(x, 2) + pow(y, 2));
}


R3::R3(double x, double y, double z) : TVector(x)
{
	this->y = y;
	this->z = z;
}
R3::R3(int rangeMin, int rangeMax) : TVector(rangeMin, rangeMax)
{
	y = generate_number(rangeMin, rangeMax);
	z = generate_number(rangeMin, rangeMax);
}

void R3::display()
{
	TVector::display();
	cout << setw(4) << y << "; " << setw(4) << z << "; ";
}
bool R3::is_parallel(TVector* ptrTVector)
{
	double k = (x / ptrTVector->x);
	if (k == (y / ((R3*)ptrTVector)->y) && k == (z / ((R3*)ptrTVector)->z))
		return true;
	return false;
}
bool R3::is_perpendicular(TVector* ptrTVector)
{
	double dotProduct = x * ptrTVector->x + y * ((R3*)ptrTVector)->y + z * ((R3*)ptrTVector)->z;
	return !dotProduct;
}
double R3::calc_length()
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}