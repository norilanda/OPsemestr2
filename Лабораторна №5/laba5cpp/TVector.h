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
	TVector(int rangeMin = -3, int rangeMax = 3);
	//methods
	virtual void display();
	
	virtual bool is_parallel(TVector* ptr) = 0;
	virtual bool is_perpendicular(TVector* ptr) = 0;
	virtual double calc_length() = 0;
	friend class R2;
	friend class R3;
};

class R2 : public TVector
{
	double y;
public:
	R2(double x, double y);
	R2(int rangeMin = -5, int rangeMax = 5);

	void display();
	bool is_parallel(TVector* ptr);
	bool is_perpendicular(TVector* ptr);
	double calc_length();
};

class R3 : public TVector
{
	double y;
	double z;
public:
	R3(double x, double y, double z);
	R3(int rangeMin = -5, int rangeMax = 5);

	void display();
	bool is_parallel(TVector* ptr);
	bool is_perpendicular(TVector* ptr);
	double calc_length();
};