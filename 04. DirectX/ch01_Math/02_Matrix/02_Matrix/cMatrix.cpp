#include "cMatrix.h"
#include <ctime>

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
				if (mat[i][j] != cCol[i][j])
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
	if (CheckSameDimension(mat))
	{
		for (int i = 0; i < GetDimension(); i++)
		{
			for (int j = 0; j < GetDimension(); j++)
			{
				if (mat[i][j] != cCol[i][j])
					return true;
			}
		}

		return false;
	}
	else
		return false;
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
					result[k][i] += cCol[k][j] * mat[j][i];
			}
		}
		// << !!
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

cMatrix cMatrix::Inverse(OUT float & fDeterminant)	// 开青纺
{
	cMatrix result(GetDimension());
	result.SetZero();

	float _determinete = Determinent();

	return result;
}

float cMatrix::Determinent()
{
	float result = 0;

	if (GetDimension() == 2)
	{
		result = cCol[0][0] * cCol[1][1] - cCol[0][1] * cCol[1][0];
		return result;
	}
	else
	{
		cMatrix calc(GetDimension() - 1);
		calc.SetZero();

		int limitX = 0, limitY = 0;
		int indexX = 0, indexY = 0;
		int cnt = 0;

		while (cnt++ <= calc.GetDimension())
		{
			for (int i = 0; i < GetDimension(); i++)
			{
				if (limitX == i)
					continue;

				for (int j = 0; j < GetDimension(); j++)
				{
					if (limitY == j)
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
			limitY++;

			calc.Print();

			result += calc.Determinent() * pow(-1, 1 + limitY);

			cout << "limitY : " << limitY << endl;
			cout << "pow : " << pow(-1, 1 + limitY) << endl;
			cout << "result : " << result << endl;
		}
	}
}

cMatrix cMatrix::Adjoint()
{
	return cMatrix();
}

float cMatrix::Cofactor(int nRow, int nCol)
{
	return 0.0f;
}

float cMatrix::MinorMatrix(int nRow, int nCol)
{
	return 0.0f;
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
	// 罚待 蔼 积己
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
