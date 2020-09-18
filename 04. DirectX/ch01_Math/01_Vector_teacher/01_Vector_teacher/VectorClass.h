#pragma once

class VectorClass
{
private:
	float x, y, z;

public:
	VectorClass();
	VectorClass(float set1, float set2, float set3);
	~VectorClass();

	bool operator == (VectorClass& vec);
	bool operator != (VectorClass& vec);

	VectorClass operator + (VectorClass& vec);
	VectorClass operator - (VectorClass& vec);
	VectorClass operator * (float f);
	VectorClass operator / (float f);

	static float Dot(VectorClass& v1, VectorClass& v2);
	static VectorClass Cross(VectorClass& v1, VectorClass& v2);

	float Length();

	VectorClass Normalize();

	void PrintValue();

	static float GetDegree(VectorClass& v1, VectorClass& v2);
};