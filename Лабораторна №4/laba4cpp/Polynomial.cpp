#include "Polynomial.h"
#include <cmath>
#include <cstdlib>

using namespace std;

Polynomial::Polynomial(double c0, double c1, double c2, double c3)
{
	this->c0 = c0;
	this->c1 = c1;
	this->c2 = c2;
	this->c3 = c3;
}
Polynomial::Polynomial(int rangeMin, int rangeMax)
{
	//FINISH !!!
	c0 = rand() % rangeMax - rangeMin + 1;
	/*c1 = 
	c2 = 
	c3 =*/
}
double Polynomial::calculate_polynomial(double x)
{
	return c0 + c1 * x + c2 * pow(x, 2) + c3 * pow(x, 3);
}