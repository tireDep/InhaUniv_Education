#pragma once

#include<string>
#include<iostream>
using std::string;

class GEMOEMTRICOBJECT_S
{
protected:
	double area;
	double length;

public:
	GEMOEMTRICOBJECT_S();
	virtual ~GEMOEMTRICOBJECT_S();

	virtual double GetArea() = 0;
	virtual double GetPerimeter() = 0;
};

class TRIANGLE_S : public GEMOEMTRICOBJECT_S
{
private:
	double side1;
	double side2;
	double side3;
	bool isFilled;
	string color;

public:
	TRIANGLE_S();
	TRIANGLE_S(double s1, double s2, double s3);
	~TRIANGLE_S();

	double GetSide1() const;
	double GetSide2() const;
	double GetSide3() const; 
	double GetArea();
	double GetPerimeter();
	void SetColor();
	string GetColor();
	bool CheckFilled();
};

class RECTANGLE_C : public GEMOEMTRICOBJECT_S
{
private:
	double width;
	double height;

public:
	RECTANGLE_C();
	RECTANGLE_C(double w, double h);
	~RECTANGLE_C();

	void SetWidth();
	void SetHeight();
	double GetWidth();
	double GetHeight();
	double GetArea();
	double GetPerimeter();
};

class CIRCLE_C : public GEMOEMTRICOBJECT_S
{
private:
	double radius;	// ¹ÝÁö¸§

public:
	CIRCLE_C();
	CIRCLE_C(double r);
	~CIRCLE_C();

	double GetRadius();
	double GetArea();
	double GetPerimeter();
};
