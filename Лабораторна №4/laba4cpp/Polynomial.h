#pragma once
#include <string>

using std::string;

class Polynomial
{
	double c0;
	double c1;
	double c2;
	double c3;
	static int generate_number(int rangeMin, int rangeMax);
	static string convert_double_to_stirng(double n);
public:
	Polynomial(double c = 1);
	Polynomial(double c0, double c1, double c2, double c3);
	Polynomial(int rangeMin, int rangeMax);
	
	double get_c0();
	double get_c1();
	double get_c2();
	double get_c3();
	string get_polynomial_as_string();
	double calculate_polynomial(double x);
	
	Polynomial operator+=(double number);
	Polynomial operator-=(double number);
	bool operator==(Polynomial polynomial);
};

void init_coefficients(double& c0, double& c1, double& c2, double& c3);
void intit_range(int& rangeMin, int& rangeMax);
