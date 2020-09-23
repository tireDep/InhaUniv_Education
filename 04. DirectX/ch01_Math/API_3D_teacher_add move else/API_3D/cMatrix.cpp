#include "stdafx.h"
#include "cMatrix.h"
#include <ctime>

#define dEpsilon 0.00001f
#define dArrSize 4

cMatrix::cMatrix()
{

}

cMatrix::cMatrix(int nDimension)
{
	ReSize(nDimension);
}

cMatrix::~cMatrix()
{

}

void cMatrix::Print()
{
	for (int i = 0; i < GetDimension(); i++)
	{
		for (int j = 0; j < GetDimension(); j++)
		{
			cout << cCol[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void cMatrix::ReSize(int nDimension)
{
	srand((unsigned)time(NULL));

	cCol.clear();

	for (int i = 0; i < nDimension; i++)
	{
		cRow addData(nDimension);
		cCol.push_back(addData);
	}
}

int cMatrix::GetDimension()
{
	return cCol.size();
}

cMatrix cMatrix::Identity(int nDimension)
{
	cMatrix result(nDimension);
	result.SetZero();

	for (int i = 0; i < nDimension; i++)
		result[i][i] = 1;

	return result;
}

cMatrix::cRow & cMatrix::operator[](int nIndex)
{
	return cCol[nIndex];
}

bool cMatrix::operator==(cMatrix & mat)
{
	if (CheckSameDimension(mat))
	{
		for (int i = 0; i < GetDimension(); i++)
		{
			for (int j = 0; j < GetDimension(); j++)
			{
				if ((*this)[i][j] - dEpsilon > mat[i][j])
					return false;
				if ((*this)[i][j] + dEpsilon < mat[i][j])
					return false;
			}
		}

		return true;
	}
	else
		return false;
}

bool cMatrix::operator!=(cMatrix & mat)
{
	return !((*this) == mat);
}

cMatrix cMatrix::operator+(cMatrix & mat)
{
	cMatrix result(GetDimension());
	result.SetZero();

	if (CheckSameDimension(mat))
	{
		for (int i = 0; i < GetDimension(); i++)
		{
			for (int j = 0; j < GetDimension(); j++)
				result[i][j] = cCol[i][j] + mat[i][j];
		}
	}
	else
	{
		for (int i = 0; i < GetDimension(); i++) 
		{
			for (int j = 0; j < GetDimension(); j++)
				result[i][j] = -9999;
		}
	}

	return result;
}

cMatrix cMatrix::operator-(cMatrix & mat)
{
	cMatrix result(GetDimension());
	result.SetZero();

	if (CheckSameDimension(mat))
	{
		for (int i = 0; i < GetDimension(); i++)
		{
			for (int j = 0; j < GetDimension(); j++)
				result[i][j] = cCol[i][j] - mat[i][j];
		}
	}
	else
	{
		for (int i = 0; i < GetDimension(); i++)
		{
			for (int j = 0; j < GetDimension(); j++)
				result[i][j] = -9999;
		}
	}

	return result;
}

cMatrix cMatrix::operator*(float num)
{
	cMatrix result(GetDimension());
	result.SetZero();

	for (int i = 0; i < GetDimension(); i++)
	{
		for (int j = 0; j < GetDimension(); j++)
		{
			result[i][j] = cCol[i][j] * num;

			// if (result[i][j] < dEpsilon)
			// 	result[i][j] = 0;	// 값 보정 필요!
		}
	}

	return result;
}

cMatrix cMatrix::operator*(cMatrix & mat)
{
	cMatrix result(GetDimension());
	result.SetZero();

	if (CheckSameDimension(mat))
	{
		// >> !!
		for (int k = 0; k < GetDimension(); k++)
		{
			for (int i = 0; i < GetDimension(); i++)
			{
				for (int j = 0; j < GetDimension(); j++)
				{
					result[k][i] += cCol[k][j] * mat[j][i];
				}

				if (abs(result[k][i]) <= dEpsilon)
					result[k][i] = 0;
				// 음수 주의!! 음수가 들어가지 않는 문제 발생할 수 있음!
			}
		}
		// << !!
	}

	return result;
}

cMatrix cMatrix::Transpose()
{
	cMatrix result(GetDimension());
	result.SetZero();
	for (int i = 0; i < GetDimension(); i++)
	{
		for (int j = GetDimension() - 1; j >= 0; j--)
			result[i][j] = cCol[j][i];
	}

	return result;
}

cMatrix cMatrix::Inverse(OUT float & fDeterminant)	// 역행렬
{
	cMatrix result(GetDimension());
	result.SetZero();

	if (-dEpsilon < fDeterminant && fDeterminant < dEpsilon)
		return result;

	return Adjoint() * (1/fDeterminant);
}

float cMatrix::Determinent()
{
	float result = 0;

	if (GetDimension() <= 0)
		return 0;
	else if (GetDimension() == 1)
		return cCol[0][0];
	else if (GetDimension() == 2)
		return cCol[0][0] * cCol[1][1] - cCol[0][1] * cCol[1][0];
	else
	{
		for (int i = 0; i < GetDimension(); i++)
			result += MinorMatrix(i, 0).Determinent() * pow(-1, 1 + (1+i)) * cCol[0][i];
	}

	return result;
}

cMatrix cMatrix::Adjoint()
{
	return Cofactor().Transpose();
}

cMatrix cMatrix::Cofactor()
{
	int dimension = GetDimension();
	cMatrix result(dimension);
	result.SetZero();

	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			result[i][j] = MinorMatrix(j, i).Determinent() * pow(-1, (1 + i) + (1 + j));
			// >> row, col
		}
	}

	return result;
}

cMatrix cMatrix::MinorMatrix(int nRow, int nCol)
{
	cMatrix calc(GetDimension() - 1);
	calc.SetZero();

	int indexX = 0, indexY = 0;
	for (int i = 0; i < GetDimension(); i++)
	{
		if (nCol == i)
			continue;

		for (int j = 0; j < GetDimension(); j++)
		{
			if (nRow == j)
				continue;

			calc[indexY][indexX++] = cCol[i][j];

			if (indexX == calc.GetDimension())
			{
				indexX = 0;
				indexY++;
				if (indexY == calc.GetDimension())
					indexY = 0;
			}
		}
	}
	return calc;
}

bool cMatrix::CheckSameDimension(cMatrix & mat)
{
	if (mat.GetDimension() != GetDimension())
		return false;
	else
		return true;
}

void cMatrix::SetZero()
{
	for (int i = 0; i < GetDimension(); i++)
	{
		for (int j = 0; j < GetDimension(); j++)
			cCol[i][j] = 0;
	}
}

void cMatrix::SetValInput()
{
	int dimension = GetDimension();
	SetZero();
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			cout << "값 입력 : ";
			cin >> cCol[i][j];
		}
	}
}

void cMatrix::SetVal(cVector3 v, cMatrix &calcMat, int col)
{
	for (int i = 0; i < dArrSize; i++)
	{
		float num = 0;

		if (i == 0)num = v.GetVectorX();
		else if (i == 1)num = v.GetVectorY();
		else if (i == 2)num = v.GetVectorZ();

		calcMat[i][col] = num;
	}
}

// >> ------------------------------------------------------------------------
cMatrix cMatrix::Translation(float x, float y, float z)
{
	// 이동행렬_점
	cMatrix resMat=cMatrix::Identity(dArrSize);

	resMat[dArrSize - 1][0] = x;
	resMat[dArrSize - 1][1] = y;
	resMat[dArrSize - 1][2] = z;

	return resMat;
}

cMatrix cMatrix::Translation(cVector3 & v)
{
	// 이동행렬_벡터
	cMatrix resMat = cMatrix::Identity(dArrSize);

	resMat[dArrSize - 1][0] = v.GetVectorX();
	resMat[dArrSize - 1][1] = v.GetVectorY();
	resMat[dArrSize - 1][2] = v.GetVectorZ();

	return resMat;
}

// >> 회전을 각 축에 대해서 실행해야 함
// 합쳐서 계산 x
cMatrix cMatrix::RotationX(float angle)
{
	cMatrix resMat = cMatrix::Identity(dArrSize);

	resMat[1][1] = cos(angle);
	resMat[1][2] = sin(angle);
	resMat[2][1] = -sin(angle);
	resMat[2][2] = cos(angle);

	return resMat;
}

cMatrix cMatrix::RotationY(float angle)
{
	cMatrix resMat = cMatrix::Identity(dArrSize);

	resMat[0][0] = cos(angle);
	resMat[0][2] = -sin(angle);
	resMat[2][0] = sin(angle);
	resMat[2][2] = cos(angle);

	return resMat;
}

cMatrix cMatrix::RotationZ(float angle)
{
	cMatrix resMat = cMatrix::Identity(dArrSize);

	resMat[0][0] = cos(angle);
	resMat[0][1] = sin(angle);
	resMat[1][0] = -sin(angle);
	resMat[1][1] = cos(angle);

	return resMat;
}

cMatrix cMatrix::View(cVector3 & vEye, cVector3 & vLookAt, cVector3 & vUp)
{
	/*
	eye, look at, up
	l = look vector
	r = right vector 
	u = up vector (0,1,0)

	up vector x look Vector = right vector
	right vector x look vector = up vector

	r.x					u.x					l.x					0
	r.y					u.y					l.y					0
	r.z					u.z					l.z					0
	-r dotPro eye		-u dotPro eye		-l dotPro eye		1 
	==> geoMatrix
	*/

	cVector3 look = (vLookAt - vEye).Normalize();
	cVector3 right =  cVector3::Cross(look, vUp).Normalize();
	cVector3 up = cVector3::Cross(look, right).Normalize();
	// >> 외적 순서 주의! 

	cMatrix resMat = cMatrix::Identity(dArrSize);

	SetVal(right, resMat, 0);
	SetVal(up, resMat, 1);
	SetVal(look, resMat, 2);

	// resMat[0][0] = right.GetVectorX(); resMat[0][1] = up.GetVectorX(); resMat[0][2] = look.GetVectorX();
	// resMat[1][0] = right.GetVectorY(); resMat[1][1] = up.GetVectorY(); resMat[1][2] = look.GetVectorY();
	// resMat[2][0] = right.GetVectorZ(); resMat[1][1] = up.GetVectorZ(); resMat[2][2] = look.GetVectorZ();

	resMat[3][0] = -cVector3::Dot(right, vEye);
	resMat[3][1] = -cVector3::Dot(up, vEye);
	resMat[3][2] = -cVector3::Dot(look, vEye);

	return resMat;
}

cMatrix cMatrix::Projection(float fFovY, float fAspect, float fNearZ, float fFalZ)
{
	/*
	sy = cot(fovy/2)  =>  1.0f / tanf(fFovY / 2.0f)
	sx = sy / aspect(비율)

	sx		0		0					0
	0		sy		0					0
	0		0		fz/(fz-nz)			1
	0		0		-fz*nz / (fz-nz)	0				
	fz : falZ
	nz : nearZ
	*/

	float sy = 1.0f / tanf(fFovY / 2.0f);
	float sx = sy / fAspect;

	cMatrix resMat(dArrSize);
	resMat.SetZero();

	resMat[0][0] = sx;
	resMat[1][1] = sy;
	resMat[2][2] = fFalZ / (fFalZ - fNearZ);
	resMat[2][3] = 1;
	resMat[3][2] = -fFalZ * fNearZ / (fFalZ - fNearZ);

	return resMat;
}

cMatrix cMatrix::ViewPort(float x, float y, float w, float h, float minZ, float maxZ)
{
	/*
	w/2.0f			0				0				0
	0				-h/2.0f			0				0
	0				0				maxZ - minZ		0
	x+(w/2.0f)		y+(h/2.0f)		minZ			1
	
	default => maxZ = 1, minZ = 0
	*/

	cMatrix resMat = cMatrix::Identity(dArrSize);
	resMat[0][0] = w/2.0f;
	resMat[1][1] = -h/2.0f;
	resMat[2][2] = maxZ - minZ;

	resMat[3][0] = x + (w / 2.0f);
	resMat[3][1] = y + (h / 2.0f);
	resMat[3][2] = minZ;

	return resMat;
}
// >> ------------------------------------------------------------------------

// -------------------------------------------------------------------

cMatrix::cRow::cRow()
{
	
}

cMatrix::cRow::cRow(int nDimension)
{
	ReSize(nDimension);
}

cMatrix::cRow::~cRow()
{

}

void cMatrix::cRow::ReSize(int nDimension)
{
	SetRanNum(nDimension);
	// 랜덤 값 생성
}

float & cMatrix::cRow::operator[](int nIndex)
{
	return vMatData[nIndex];
}

void cMatrix::cRow::SetRanNum(int nDimension)
{
	int num = 0;
	while (num < nDimension)
	{
		num++;
		vMatData.push_back(rand() % 10);
	}
}
