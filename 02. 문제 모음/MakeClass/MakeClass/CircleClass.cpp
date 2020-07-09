#define _USE_MATH_DEFINES
#include<cmath>
#include"GemometricObject.h"

CIRCLE_C::CIRCLE_C() : radius(1) { }

CIRCLE_C::CIRCLE_C(double r) : radius(r) {}

CIRCLE_C::~CIRCLE_C() { }

double CIRCLE_C::GetRadius()
{
	return radius;
}

double CIRCLE_C::GetArea()
{
	return M_PI * pow(radius, 2);
}

double CIRCLE_C::GetPerimeter()
{
	return 2 * M_PI * radius;
}