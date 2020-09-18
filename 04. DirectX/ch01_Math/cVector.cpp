#include "cVector.h"
#include <iostream>
#include <cmath>

using namespace std;

cVector3::cVector3()
{
	x = 0;
	y = 0;
	z = 0;
}

cVector3::cVector3(float set1, float set2, float set3)
{
	x = set1;
	y = set2;
	z = set3;
}

cVector3::~cVector3()
{

}

bool cVector3::operator==(cVector3 & vec)
{
	if (vec.x == x && vec.y == y && vec.z == z)
		return true;
	else
		return false;
}

bool cVector3::operator!=(cVector3 & vec)
{
	if (vec.x != x || vec.y != y || vec.z != z)
		return true;
	else
		return false;
}

cVector3 cVector3::operator+(cVector3 & vec)
{
	cVector3 result;
	result.x = vec.x + x;
	result.y = vec.y + y;
	result.z = vec.z + z;

	return result;
}

cVector3 cVector3::operator-(cVector3 & vec)
{
	cVector3 result;
	result.x = vec.x - x;
	result.y = vec.y - y;
	result.z = vec.z - z;

	return result;
}

cVector3 cVector3::operator*(float f)
{
	cVector3 result;
	result.x = f * x;
	result.y = f * y;
	result.z = f * z;

	return result;
}

cVector3 cVector3::operator/(float f)
{
	cVector3 result;
	result.x = x;
	result.y = y;
	result.z = z;

	if (f == 0)
		return result;

	result.x /= f;
	result.y /= f;
	result.z /= f;

	return result;
}

float cVector3::Dot(cVector3 & v1, cVector3 & v2)
{
	// 1 >> 각 성분끼리 곱한 후 더함
	// cVector3 result;
	// result.x = v1.x*v2.x;
	// result.y = v1.y*v2.y;
	// result.z = v1.z*v2.z;
	// return result.x + result.y + result.z;

	// 2 >> 각 벡터의 크기를 구하고 cos(θ) * 벡터 크기1 * 벡터 크기2
	cVector3 result;

	result.x = v1.x*v2.x;
	result.y = v1.y*v2.y;
	result.z = v1.z*v2.z;

	float v1Lenght = v1.Length();
	float v2Lenght = v2.Length();

	float cosTheta = (result.x + result.y + result.z) / (v1Lenght * v2Lenght);
	// >> cos(θ) 구하는 법
	// 벡터 내적 / (벡터 크기1 * 벡터 크기2)

	return cosTheta * v1Lenght * v2Lenght;
}

cVector3 cVector3::Cross(cVector3 & v1, cVector3 & v2)
{
	cVector3 result;

	result.x = v1.y*v2.z - v1.z*v2.y;
	result.y = v1.z*v2.x - v1.x*v2.z;
	result.z = v1.x*v2.y - v1.y*v2.x;

	return result;
}

float cVector3::Length()
{
	float result;
	result = pow(pow(x, 2) + pow(y, 2) + pow(z, 2), 0.5);

	return result;
}

cVector3 cVector3::Normalize()
{
	cVector3 result;
	float length = Length();

	result.x = x / length;
	result.y = y / length;
	result.z = z / length;

	return result;
}

void cVector3::PrintValue()
{
	cout << x << ", " << y << ", " << z << endl;
}

float cVector3::GetDegree(cVector3 & v1, cVector3 & v2)
{
	cVector3 result;

	result.x = v1.x*v2.x;
	result.y = v1.y*v2.y;
	result.z = v1.z*v2.z;

	float v1Lenght = v1.Length();
	float v2Lenght = v2.Length();

	float cosTheta = (result.x + result.y + result.z) / (v1Lenght * v2Lenght);
	// >> cos(θ) 구하는 법
	// 벡터 내적 / (벡터 크기1 * 벡터 크기2)

	float degree = acos(cosTheta) * (180 / 3.14);	// 라디안 -> 각도

	return degree;
}
