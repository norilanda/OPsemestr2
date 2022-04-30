#pragma once

//конструктори, гетери, метод обчислення значення в конкретній точці. Перевантажити +=, -+, ==
class Polynomial
{
	double c0;
	double c1;
	double c2;
	double c3;
public:
	//конструкторu
	Polynomial(double c0, double c1, double c2, double c3);
	Polynomial(int rangeMin, int rangeMax);
	//гетери

	double calculate_polynomial(double x);
};
