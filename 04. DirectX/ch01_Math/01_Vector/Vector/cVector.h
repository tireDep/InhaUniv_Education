#pragma once

class cVector3
{
private:
	float x, y, z;

public:
	cVector3();
	cVector3(float set1, float set2, float set3);
	~cVector3();

	bool operator == (cVector3& vec);
	bool operator != (cVector3& vec);

	cVector3 operator + (cVector3& vec);
	cVector3 operator - (cVector3& vec);
	cVector3 operator * (float f);
	cVector3 operator / (float f);

	static float Dot(cVector3& v1, cVector3& v2);
	static cVector3 Cross(cVector3& v1, cVector3& v2);

	float Length();

	cVector3 Normalize();

	void PrintValue();

	static float GetDegree(cVector3& v1, cVector3& v2);
};
