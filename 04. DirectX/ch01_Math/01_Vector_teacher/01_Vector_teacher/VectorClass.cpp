#include "VectorClass.h"
#include <cmath>

#define dEpsilon 0.0001f

VectorClass::VectorClass() : x(0.0f), y(0.0f), z(0.0f)
{

}

VectorClass::VectorClass(float set1, float set2, float set3) : x(set1), y(set2), z(set3)
{
	// x = set1;
	// y = set2;
	// z = set3;
}

VectorClass::~VectorClass()
{

}

bool VectorClass::operator==(VectorClass & vec)
{
	if (x - dEpsilon <= vec.x && x <= vec.x + dEpsilon
		&& y - dEpsilon <= vec.y && y <= vec.y + dEpsilon
		&& z - dEpsilon <= vec.z && z <= vec.z + dEpsilon)
		return true;
	else
		return false; 
}

bool VectorClass::operator!=(VectorClass & vec)
{
	return !(*this == vec);
}

VectorClass VectorClass::operator+(VectorClass & vec)
{
	VectorClass r;
	
	r.x = x + vec.x;
	r.y = y + vec.y;
	r.z = z + vec.z;
	
	return r;
}

VectorClass VectorClass::operator-(VectorClass & vec)
{
	VectorClass r;

	r.x = x - vec.x;
	r.y = y - vec.y;
	r.z = z - vec.z;

	return r;
}

VectorClass VectorClass::operator*(float f)
{
	VectorClass r;

	r.x = x * f;
	r.y = y * f;
	r.z = z * f;

	return r;
}

VectorClass VectorClass::operator/(float f)
{
	VectorClass r;

	r.x = x / f;
	r.y = y / f;
	r.z = z / f;

	return r;
}

float VectorClass::Dot(VectorClass & v1, VectorClass & v2)
{
	return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

VectorClass VectorClass::Cross(VectorClass & v1, VectorClass & v2)
{
	VectorClass r;
	r.x = v1.y*v2.z - v1.z*v2.y;
	r.y = v1.z*v2.x - v1.x*v2.z;
	r.z = v1.x*v2.y - v1.y*v2.x;

	return r;
}

float VectorClass::Length()
{
	return (float)sqrt(x*x + y*y + z*z);
}

VectorClass VectorClass::Normalize()
{
	VectorClass r;
	float len = Length();

	r.x = x / len;
	r.y = y / len;
	r.z = z / len;

	return r;
}

void VectorClass::PrintValue()
{

}

float VectorClass::GetDegree(VectorClass & v1, VectorClass & v2)
{
	return 0.0f;
}
