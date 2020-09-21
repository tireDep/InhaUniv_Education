#include "stdafx.h"
#include "cVector.h"
#include <iostream>
#include <cmath>

#define dEpsilon 0.0001f
#define dArrSize 4

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
	if (x - dEpsilon <= vec.x && x <= vec.x + dEpsilon
		&& y - dEpsilon <= vec.y && y <= vec.y + dEpsilon
		&& z - dEpsilon <= vec.z && z <= vec.z + dEpsilon)
		return true;
	else
		return false;
}

bool cVector3::operator!=(cVector3 & vec)
{
	return !(*this == vec);
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

float cVector3::GetVectorX()
{
	return x;
}

float cVector3::GetVectorY()
{
	return y;
}

float cVector3::GetVectorZ()
{
	return z;
}

void cVector3::SetValue(float setX, float setY, float setZ)
{
	x = setX;
	y = setY;
	z = setZ;
}

cVector3 cVector3::GetcVector()
{
	return cVector3();
}

cVector3 cVector3::TransformCoord(cVector3 & v, cMatrix & mat)
{
	float a = mat[0][0] * v.GetVectorX() + mat[1][0] * v.GetVectorY() + mat[2][0] * v.GetVectorZ() + mat[3][0] * 1;
	float b = mat[0][1] * v.GetVectorX() + mat[1][1] * v.GetVectorY() + mat[2][1] * v.GetVectorZ() + mat[3][1] * 1;
	float c = mat[0][2] * v.GetVectorX() + mat[1][2] * v.GetVectorY() + mat[2][2] * v.GetVectorZ() + mat[3][2] * 1;
	float d = mat[0][3] * v.GetVectorX() + mat[1][3] * v.GetVectorY() + mat[2][3] * v.GetVectorZ() + mat[3][3] * 1;

	cVector3 retVec(a / d, b / d, c / d);

	return retVec;
}

cVector3 cVector3::TransformNormal(cVector3 & v, cMatrix & mat)
{
	float a = mat[0][0] * v.GetVectorX() + mat[1][0] * v.GetVectorY() + mat[2][0] * v.GetVectorZ();
	float b = mat[0][1] * v.GetVectorX() + mat[1][1] * v.GetVectorY() + mat[2][1] * v.GetVectorZ();
	float c = mat[0][2] * v.GetVectorX() + mat[1][2] * v.GetVectorY() + mat[2][2] * v.GetVectorZ();

	cVector3 retVec(a, b, c);

	return retVec;
}
