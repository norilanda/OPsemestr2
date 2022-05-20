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
	//methods
	virtual void display();
	
	virtual bool is_parallel(TVector& v) = 0;
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
	bool is_parallel(TVector& v);
	bool is_perpendicular(TVector& v);
	double calc_length();
};