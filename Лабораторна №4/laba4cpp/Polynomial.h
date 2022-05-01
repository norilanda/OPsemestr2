#pragma once

//������������, ������, ����� ���������� �������� � ��������� �����. ������������� +=, -+, ==
class Polynomial
{
	double c0;
	double c1;
	double c2;
	double c3;
	int generate_number(double rangeMin, double rangeMax);
public:
	//�����������u
	Polynomial();
	Polynomial(double c0, double c1, double c2, double c3);
	Polynomial(int rangeMin, int rangeMax);
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

void init_coefficients(double& c0, double& c1, double& c2, double& c3);
void intit_range(double& rangeMin, double& rangeMax);
