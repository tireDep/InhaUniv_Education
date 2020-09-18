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

	float Determinent();
	cMatrix Adjoint();
	cMatrix Cofactor();
	cMatrix MinorMatrix(int nRow, int nCol);	// �ش� ����� ��Ľ� ���ϴ� ����

	bool CheckSameDimension(cMatrix &mat);
	void SetZero();

	void SetValInput();

	static void SetVal(cVector3 v, cMatrix &calcMat, int col);

	// >> ----------------------------------------------------------------

	static cMatrix Translation(float x, float y, float z);
	static cMatrix Translation(cVector3& v);
	// >> �̵�
	
	static cMatrix RotationX(cVector3& v);
	static cMatrix RotationY(cVector3& v);
	static cMatrix RotationZ(cVector3& v);
	// >> ȸ��

	static cMatrix View(cVector3& vEye, cVector3& vLookAt, cVector3& vUp);
	// >> ���� ��ġ, ��� �ٶ󺸰� �ִ���(�� ��ġ - �ٶ󺸴� ��(?)), �ϴ� �ٶ󺸴� ����
	// >> vUp���� rightVector ���� => lookAt, right ���� => ��Ȯ�� vUp ����

	static cMatrix Projection(float fFovY, float fAspect, float fNearZ, float fFalZ);
	// >> ���� �Լ�(���ٰ�)
	// >> �þ߰�(����), ��Ⱦ�� = �ʺ� / ����, ����� ������ �Ÿ�, �� �������� �Ÿ�

	static cMatrix ViewPort(float x, float y, float w, float h, float minZ, float maxZ);
	// >> ȭ�� �׸��� �Լ�

	// << ----------------------------------------------------------------
};