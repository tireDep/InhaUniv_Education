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

	float Determinent();
	cMatrix Adjoint();
	cMatrix Cofactor();
	cMatrix MinorMatrix(int nRow, int nCol);	// 해당 행렬의 행렬식 구하는 목적

	bool CheckSameDimension(cMatrix &mat);
	void SetZero();

	void SetValInput();

	static void SetVal(cVector3 v, cMatrix &calcMat, int col);

	// >> ----------------------------------------------------------------

	static cMatrix Translation(float x, float y, float z);
	static cMatrix Translation(cVector3& v);
	// >> 이동
	
	static cMatrix RotationX(cVector3& v);
	static cMatrix RotationY(cVector3& v);
	static cMatrix RotationZ(cVector3& v);
	// >> 회전

	static cMatrix View(cVector3& vEye, cVector3& vLookAt, cVector3& vUp);
	// >> 눈의 위치, 어디를 바라보고 있는지(눈 위치 - 바라보는 것(?)), 하늘 바라보는 상태
	// >> vUp으로 rightVector 구함 => lookAt, right 직교 => 정확한 vUp 설정

	static cMatrix Projection(float fFovY, float fAspect, float fNearZ, float fFalZ);
	// >> 투사 함수(원근감)
	// >> 시야각(라디안), 종횡비 = 너비 / 높이, 가까운 평면까지 거리, 먼 평면까지의 거리

	static cMatrix ViewPort(float x, float y, float w, float h, float minZ, float maxZ);
	// >> 화면 그리는 함수

	// << ----------------------------------------------------------------
};