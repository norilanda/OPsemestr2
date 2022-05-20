#pragma once

class R2;
class R3;

class TVector
{
protected:
	double x;
	static int generate_number(int rangeMin, int rangeMax);
public:
	//constructors
	TVector(double x);
	TVector(int rangeMin = -5, int rangeMax = 5);
	//methods
	virtual void display();
	
	virtual bool is_parallel(R2& v) = 0;
	virtual bool is_perpendicular(TVector& v) = 0;
	virtual double calc_length() = 0;
};

class R2 : public TVector
{
	double y;
public:
	R2(double x, double y);
	R2(int rangeMin = -5, int rangeMax = 5);

	void display();
	bool is_parallel(R2& v);
	bool is_perpendicular(TVector& v);
	double calc_length();
};

class R3 : public TVector
{
	double y;
	double z;
public:
	R3(double x, double y, double z);
	R3(int rangeMin = -5, int rangeMax = 5);

};