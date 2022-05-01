#include "Polynomial.h"
#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

Polynomial::Polynomial(): c0(1), c1(1), c2(1), c3(1) {}
Polynomial::Polynomial(double c0, double c1, double c2, double c3)
{
	this->c0 = c0;
	this->c1 = c1;
	this->c2 = c2;
	this->c3 = c3;
}
Polynomial::Polynomial(double rangeMin, double rangeMax, int decimalPlaces = 0)
{
	//FINISH !!!
	c0 = generate_number(rangeMin, rangeMax, decimalPlaces);
	c1 = generate_number(rangeMin, rangeMax, decimalPlaces);
	c2 = generate_number(rangeMin, rangeMax, decimalPlaces);
	c3 = generate_number(rangeMin, rangeMax, decimalPlaces);
}
double Polynomial::generate_number(double rangeMin, double rangeMax, int decimalPlaces)
{
	double number = ((double)rand() / RAND_MAX) * (rangeMax - rangeMin) + rangeMin;
	int coefficient = pow(10, decimalPlaces);
	return round(number * coefficient) / coefficient;
}
double Polynomial::get_c0(){ return c0; }
double Polynomial::get_c1() { return c1; }
double Polynomial::get_c2() { return c2; }
double Polynomial::get_c3() { return c3; }
void Polynomial::display()
{
	cout << c0 << " + " << c1 << "x + " << c2 << "x^2 + " << c3 << "x^3" << "\n";
}
double Polynomial::calculate_polynomial(double x)
{
	return c0 + c1 * x + c2 * pow(x, 2) + c3 * pow(x, 3);
}
Polynomial Polynomial::operator+=(double number)
{
	c0 += number;
	c1 += number;
	c2 += number;
	c3 += number;
}
Polynomial Polynomial::operator-=(double number)
{
	c0 -= number;
	c1 -= number;
	c2 -= number;
	c3 -= number;
}
bool Polynomial::operator==(Polynomial polynomial)
{
	if (c0 == polynomial.c0 && c1 == polynomial.c1 && c2 == polynomial.c2 && c3 == polynomial.c3)
		return true;
	return false;
}