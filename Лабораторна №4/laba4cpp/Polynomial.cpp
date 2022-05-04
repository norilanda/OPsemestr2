#include "Polynomial.h"
#include <cmath>
#include <iostream>
#include <stdlib.h>    

using namespace std;

Polynomial::Polynomial(double c): c0(c), c1(c), c2(c), c3(c) {}
Polynomial::Polynomial(double c0, double c1, double c2, double c3)
{
	this->c0 = c0;
	this->c1 = c1;
	this->c2 = c2;
	this->c3 = c3;
}
Polynomial::Polynomial(int rangeMin, int rangeMax)
{
	c0 = generate_number(rangeMin, rangeMax);
	c1 = generate_number(rangeMin, rangeMax);
	c2 = generate_number(rangeMin, rangeMax);
	c3 = generate_number(rangeMin, rangeMax);
}
int Polynomial::generate_number(int rangeMin, int rangeMax)
{
	int number = ((double)rand() / RAND_MAX) * (rangeMax - rangeMin) + rangeMin;
	return number;
}
double Polynomial::get_c0() { return c0; }
double Polynomial::get_c1() { return c1; }
double Polynomial::get_c2() { return c2; }
double Polynomial::get_c3() { return c3; }
string Polynomial::convert_double_to_stirng(double n)
{
	string str = to_string(n);
	size_t pos = str.find_last_not_of('0') + 1;
	str = str.erase(pos);
	size_t lastPos = str.length() - 1;
	if (str[lastPos]=='.')
		str = str.erase(lastPos);
	return str;
}
string Polynomial::get_polynomial_as_string()
{
	string polynomial_string = convert_double_to_stirng(c0)+ " + " + convert_double_to_stirng(c1) + "x + " + convert_double_to_stirng(c2) + "x^2 + " + convert_double_to_stirng(c3) + "x^3" + "\n";
	return polynomial_string;
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
	return *this;
}
Polynomial Polynomial::operator-=(double number)
{
	c0 -= number;
	c1 -= number;
	c2 -= number;
	c3 -= number;
	return *this;
}
bool Polynomial::operator==(Polynomial polynomial)
{
	if (c0 == polynomial.c0 && c1 == polynomial.c1 && c2 == polynomial.c2 && c3 == polynomial.c3)
		return true;
	return false;
}

void init_coefficients(double& c0, double& c1, double& c2, double& c3)
{
	cout << "Enter 4 numbers to initiate coefficients\n";
	cout << "c0: "; cin >> c0;
	cout << "c1: "; cin >> c1;
	cout << "c2: "; cin >> c2;
	cout << "c3: "; cin >> c3;
}
void intit_range(int& rangeMin, int& rangeMax)
{
	cout << "Enter the range for generating coefficients\n";
	cout << "Minimum number of the range: "; cin >> rangeMin;
	cout << "Maximum number of the range: "; cin >> rangeMax;
}