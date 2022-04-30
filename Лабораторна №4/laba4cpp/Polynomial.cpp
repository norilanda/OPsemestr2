#include "Polynomial.h"
#include <cmath>

double Polynomial::calculate_polynomial(double x)
{
	return c0 + c1 * x + c2 * pow(x, 2) + c3 * pow(x, 3);
}