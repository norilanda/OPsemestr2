#pragma once

//������������, ������, ����� ���������� �������� � ��������� �����. ������������� +=, -+, ==
class Polynomial
{
	double c0;
	double c1;
	double c2;
	double c3;
public:
	//�����������u
	Polynomial(double c0, double c1, double c2, double c3);
	Polynomial(int rangeMin, int rangeMax);
	//������

	double calculate_polynomial(double x);
};
