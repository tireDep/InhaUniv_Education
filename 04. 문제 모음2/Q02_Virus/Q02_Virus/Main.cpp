// Q. ���� ���� ���漾�Ϳ� �ٹ����� ����� �� ������ ���̷��� ������ ���� �����̴�.
// 
// ���̷����� �ʱ� ������ : A
// ���̷����� �ð��� ���� ��� : B
// ���̷����� �������� �ð� : T
// 
// ���� ���� �����Ͱ� �־����� �� T�ð��� ������ ���� ���� ������ ���� �����ؾ� �Ѵ�
// 
// ���� �� �ʱ� ������(A)�� 2��, ���� ���(B)�� 4, �ð�(T)�� ���
// ���� �������� ���� 2*4*4*4 = 128������ ������ �� �ִ�.
// 
// �Է� ���� >
// �Է� �����ʹ� �� �� ���� �־����� A B T ���� �������� �и��Ǿ� ������� �����ȴ�
//
// ���� ���� >
// 1 <= A <= 100
// 1 <= B <= 100
// 1 <= T <= 10^13
//
// ��� ���� >
// T �ð��� ���� �� ���� �������� ���� 10^9+7(1000000007) ������ ���� ��
// �� ������ ���� ����Ѵ�
// ���� �Է� >
// 2 3 20
// 
// ���� ��� >
// 973568760

#include <iostream>

using namespace std;

int main()
{
	long int iPeople = 0;
	long long int fMulNum = 0;
	long long int fTime = 0;

	cin >> iPeople >> fMulNum >> fTime;

	// long long int fResult = iPeople * pow(fMulNum, fTime);
	// long long int fDivide = pow(10, 9) + 7;
	
	long long int fResult = iPeople;
	long long int fDivide = pow(10, 9) + 7;
	for (int i = 0; i < fTime; i++)
	{
		if (fResult * fMulNum <= 0)
		{
			fResult /= fDivide;
			cout << "testtesttestttest" << endl;
			cout << i << endl;
		}
		fResult *= fMulNum;
	}

	cout << fResult << endl;
	// cout << "result : " << fResult % fDivide << endl;

	return 0;
}