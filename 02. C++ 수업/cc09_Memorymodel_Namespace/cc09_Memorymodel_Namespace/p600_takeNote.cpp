#include<iostream>

namespace Jack
{
	double pail;
	void fetch() {}	// Jill���� ����(����)
	int pal;	// Jill���� ����(����)
	struct Well
	{

	};
}

namespace Jill
{
	double bucket(double n) { return 1.0; }
	double fetch;	// Jack���� ����(�Լ�)
	int pal;	// Jack���� ����(����)
	struct Hill
	{

	};
}

/*
------------------------------------------------
�̸� ���� �ȿ� using ���� ��� ���� -> ���� x
------------------------------------------------
*/

using namespace std;
using namespace Jack;
using namespace Jill;

int main()
{
	// pal = 10;	// ��� �̸������� pal���� �� �� x
	Jack::pal = 10;
	Jill::pal = 11;

	using Jack::pal;
	pal = 20;

	using Jill::fetch;	// ������ �̸��� ������ �Լ��� ������
	fetch = 50;
	cout << fetch << endl;
}