#pragma once

//������������, ������, ����� ���������� �������� � ��������� �����. ������������� +=, -+, ==
class Polynomial
{
	double c0;
	double c1;
	double c2;
	double c3;
	double generate_number(double rangeMin, double rangeMax, int decimalPlaces);
public:
	//�����������u
	Polynomial();
	Polynomial(double c0, double c1, double c2, double c3);
	Polynomial(double rangeMin, double rangeMax, int decimalPlaces = 0);
	//������
	double get_c0();
	double get_c1();
	double get_c2();
	double get_c3();
	void display();
	double calculate_polynomial(double x);
	//operators
	Polynomial operator+=(double number);
	Polynomial operator-=(double number);
	bool operator==(Polynomial polynomial);
};
