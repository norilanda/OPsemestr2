#pragma once

class TVector
{
protected:
	double x;
	static int generate_number(int rangeMin, int rangeMax);
public:
	//constructors
	TVector(double x);
	TVector(int rangeMin = -5, int rangeMax = 5);
	// паралельн≥сть
	// перпендикул€рн≥сть
	// метод визначенн€ довжини
};
