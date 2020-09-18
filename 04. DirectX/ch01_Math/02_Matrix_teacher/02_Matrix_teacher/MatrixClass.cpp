#include "MatrixClass.h"

#define dEpslion 0.0001f

cMatrix::cMatrix()
{
	
}

cMatrix::~cMatrix()
{

}

cMatrix::cMatrix(int nDimension)
{
	Resize(nDimension);
}

void cMatrix::Print()
{
	for (int i = 0; i < Dimension(); i++)
	{
		for (int j = 0; j < Dimension(); j++)
		{
			printf("%8.2f", (*this)[i][j]);
		}
		cout << endl;
	}
}

void cMatrix::Resize(int nDimension)
{
	colVec.resize(nDimension);
	for (size_t i = 0; i < nDimension; i++)
	{
		colVec[i].Resize(nDimension);
	}
}

int cMatrix::Dimension()
{
	return (int)colVec.size();
}

cMatrix cMatrix::Identity(int nDimension)
{
	cMatrix matRet(nDimension);
	for (int i = 0; i < nDimension; i++)
	{
		for (int j = 0; j < nDimension; j++)
		{
			matRet[i][j] = (i == j) ? 1 : 0;
		}
	}

	return matRet;
}

cMatrix::cRow & cMatrix::operator[](int nIndex)
{
	return colVec[nIndex];
}

bool cMatrix::operator==(cMatrix & mat)
{
	for (int i = 0; i < Dimension(); i++)
	{
		for (int j = 0; j < Dimension(); j++)
		{
			if ((*this)[i][j] - dEpslion > mat[i][j])
				return false;
			if ((*this)[i][j] + dEpslion < mat[i][j])
				return false;
		}
	}

	return true;
}

bool cMatrix::operator!=(cMatrix & mat)
{
	return !((*this) == mat);
}

cMatrix cMatrix::operator+(cMatrix & mat)
{
	cMatrix r(Dimension());

	for (int i = 0; i < Dimension(); i++)
	{
		for (int j = 0; j < Dimension(); j++)
		{
			r[i][j] = (*this)[i][j] + mat[i][j];
		}
	}

	return r;
}

cMatrix cMatrix::operator-(cMatrix & mat)
{
	cMatrix r(Dimension());

	for (int i = 0; i < Dimension(); i++)
	{
		for (int j = 0; j < Dimension(); j++)
		{
			r[i][j] = (*this)[i][j] - mat[i][j];
		}
	}

	return r;
}

cMatrix cMatrix::operator*(cMatrix & mat)
{
	cMatrix r(Dimension());
	
	for (int i = 0; i < Dimension(); i++)
	{
		for (int j = 0; j < Dimension(); j++)
		{
			r[i][j] = 0.f;
			for (int k = 0; k < Dimension(); k++)
			{
				r[i][j] = (*this)[i][k] * mat[k][j];
			}
		}
	}

	return r;
}

cMatrix cMatrix::operator*(float f)
{
	cMatrix r(Dimension());

	for (int i = 0; i < Dimension(); i++)
	{
		for (int j = 0; j < Dimension(); j++)
		{
			r[i][j] = (*this)[i][j] * f;
		}
	}

	return r;
}

cMatrix cMatrix::Inverse(OUT float & fDeterminant)
{
	cMatrix r = cMatrix::Identity(Dimension());
	fDeterminant = Determinant();
	
	if (-dEpslion < fDeterminant && fDeterminant < dEpslion)
	{
		cout << "역행렬이 존재하지 x" << endl;
		return r;
	}

	cMatrix adjoint = Adjoint();
	
	r = adjoint * (1 / fDeterminant);

	return r;
}

float cMatrix::Determinant()
{
	if (Dimension() == 1)
	{
		return  (*this)[0][0];
	}

	if (Dimension() == 2)
	{
		return (*this)[0][0] * (*this)[1][1] - (*this)[1][0] * (*this)[0][1];
	}

	float fDeterminant = 0.0f;
	for (int i = 0; i < Dimension(); i++)
	{
		fDeterminant += ((*this)[i][0] * Cofactor(i, 0));
	}

	return 0;
}

cMatrix cMatrix::Adjoint()
{
	cMatrix r(Dimension());

	for (int i = 0; i < Dimension(); i++)
	{
		for (int j = 0; j < Dimension(); j++)
		{
			r[i][j] = Cofactor(j, i);
		}
	}

	return r;
}

cMatrix cMatrix::Transpose()
{
	cMatrix r(Dimension());

	for (int i = 0; i < Dimension(); i++)
	{
		for (int j = 0; j < Dimension(); j++)
		{
			r[i][j] = (*this)[j][i];
		}
	}

	return r;
}

float cMatrix::Cofactor(int nRow, int nCol)
{
	int nConst = 0;

	if ((nRow + nCol) % 2 != 0)
		nConst = -1;
	else
		nConst = 1;
	// >> 부호 결정

	return nConst * Minor(nRow, nCol);
}

float cMatrix::Minor(int nRow, int nCol)
{
	cMatrix rMinor(Dimension() - 1);
	int nMinorRow = 0;
	int nMinorCol = 0;

	for (int i = 0; i < Dimension(); i++)
	{
		if (nRow == i)
			continue;

		nMinorCol = 0;
		for (int j = 0; j < Dimension(); j++)
		{
			if (nCol == j)
				continue;

			rMinor[nMinorRow][nMinorCol] = (*this)[i][j];
			nMinorCol++;
		}
		nMinorRow++;
	}

	return rMinor.Determinant();
}

cMatrix::cRow::cRow()
{

}

cMatrix::cRow::cRow(int nDimension)
{

}

void cMatrix::cRow::Resize(int nDimension)
{

}

float & cMatrix::cRow::operator[](int nIndex)
{
	
}
