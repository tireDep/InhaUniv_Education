#include "cMatrix.h"
#include <ctime>

#define dEpsilon 0.00001f

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
			result[i][j] = cCol[i][j] * num;
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
				if (abs(result[k][i]) < dEpsilon)
					result[k][i] = 0;	// 음수값 주의!
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

void cMatrix::SetVal()
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
