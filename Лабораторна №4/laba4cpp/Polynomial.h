#pragma once
#include <string>

using std::string;

//конструктори, гетери, метод обчислення значення в конкретній точці. Перевантажити +=, -+, ==
class Polynomial
{
	double c0;
	double c1;
	double c2;
	double c3;
	int generate_number(double rangeMin, double rangeMax);
	static string convert_double_to_stirng(double n);
public:
	//конструкторu
	Polynomial();
	Polynomial(double c0, double c1, double c2, double c3);
	Polynomial(int rangeMin, int rangeMax);
	//гетери
	double get_c0();
	double get_c1();
	double get_c2();
	double get_c3();
	string get_polynomial_as_string();
	double calculate_polynomial(double x);
	//operators
	Polynomial operator+=(double number);
	Polynomial operator-=(double number);
	bool operator==(Polynomial polynomial);
};

void init_coefficients(double& c0, double& c1, double& c2, double& c3);
void intit_range(double& rangeMin, double& rangeMax);
