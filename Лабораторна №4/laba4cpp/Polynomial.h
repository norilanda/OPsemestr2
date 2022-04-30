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
	double get_c0();
	double get_c1();
	double get_c2();
	double get_c3();
	double calculate_polynomial(double x);
};
