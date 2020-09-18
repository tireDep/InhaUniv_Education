#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

class cMatrix
{
public:
	cMatrix();
	~cMatrix();

	// >> : 
private:
	class cRow
	{
	private:
		std::vector<float> rowVec;

	public:
		cRow();
		cRow(int nDimension);
		~cRow() {}
		void Resize(int nDimension);
		float& operator[](int nIndex);
	};

	std::vector<cRow> colVec;
	// << : 
public:

	// >> : 
	cMatrix(int nDimension);

	void	Print();
	void	Resize(int nDimension);
	int		Dimension();

	static	cMatrix Identity(int nDimension);

	cRow&	operator[](int nIndex);
	bool	operator==(cMatrix& mat);
	bool	operator!=(cMatrix& mat);
	cMatrix operator+(cMatrix& mat);
	cMatrix operator-(cMatrix& mat);
	cMatrix operator*(cMatrix& mat);
	cMatrix operator*(float f);

	cMatrix Inverse(OUT float& fDeterminant);
	float	Determinant();
	cMatrix Adjoint();
	cMatrix Transpose();
	float	Cofactor(int nRow, int nCol);
	float	Minor(int nRow, int nCol);

};

