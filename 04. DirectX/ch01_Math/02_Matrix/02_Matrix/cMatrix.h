#pragma once

#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

class cMatrix
{
private:
	class cRow
	{
	private:
		vector<float> vMatData;
	
	public:
		cRow();
		cRow(int nDimension);
		~cRow();
	
		void ReSize(int nDimension);
		float& operator[](int nIndex);

		void SetRanNum(int nDimension);
	};

	vector<cRow> cCol;

public:
	cMatrix();
	cMatrix(int nDimension);	// 랜덤 생성
	~cMatrix();

	void Print();
	void ReSize(int nDimension);
	int GetDimension();

	static cMatrix Identity(int nDimension);	// 해당 차수의 단위 행렬
	cRow& operator[](int nIndex);

	// ==============================================================================

	bool operator ==(cMatrix &mat);
	bool operator !=(cMatrix &mat);

	cMatrix operator +(cMatrix &mat);
	cMatrix operator -(cMatrix &mat);
	cMatrix operator *(float num);
	cMatrix operator *(cMatrix &mat);
	
	cMatrix Transpose();	// 전치 행렬
	cMatrix Inverse(OUT float& fDeterminant);	// 역행렬

	float Determinent(float detNum);
	cMatrix Adjoint();
	float Cofactor(int nRow, int nCol);
	float MinorMatrix(int nRow, int nCol);	// 해당 행렬의 행렬식 구하는 목적

	bool CheckSameDimension(cMatrix &mat);
	void SetZero();
};