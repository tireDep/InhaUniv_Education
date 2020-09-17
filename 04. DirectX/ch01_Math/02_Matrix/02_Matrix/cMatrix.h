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
	cMatrix(int nDimension);	// ���� ����
	~cMatrix();

	void Print();
	void ReSize(int nDimension);
	int GetDimension();

	static cMatrix Identity(int nDimension);	// �ش� ������ ���� ���
	cRow& operator[](int nIndex);

	// ==============================================================================

	bool operator ==(cMatrix &mat);
	bool operator !=(cMatrix &mat);

	cMatrix operator +(cMatrix &mat);
	cMatrix operator -(cMatrix &mat);
	cMatrix operator *(float num);
	cMatrix operator *(cMatrix &mat);
	
	cMatrix Transpose();	// ��ġ ���
	cMatrix Inverse(OUT float& fDeterminant);	// �����

	float Determinent(float detNum);
	cMatrix Adjoint();
	float Cofactor(int nRow, int nCol);
	float MinorMatrix(int nRow, int nCol);	// �ش� ����� ��Ľ� ���ϴ� ����

	bool CheckSameDimension(cMatrix &mat);
	void SetZero();
};