// Q. ������ �鸸 �� ������ ���� �ùķ��̼� �ϰ�
// �ո�� �޸��� ���� ����ϴ� ���α׷��� �ۼ��϶�.
// 100 / 1,000 / 10,000 / 100,000 / 1,000,000
// ���� �� �ڰ� �� %�� �������� ����� ����϶�

// �������� : ��, ���� ���Դ� �Ȱ���

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));

	int side;
	int printVal = 100;
	double frontSide = 0;
	double backSide = 0;

	int i;
	cout << "[�ո� / �޸� Ȯ��]";
	for (i = 0; i < 1000000; i++)
	{
		side = rand() % 2;
		if (side == 0)
			backSide++;
		else
			frontSide++;

		if (i == printVal) // if (i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000)
		{
			printVal *= 10;
			cout << endl << i << "�� ������ ���\n";
			cout << "�ո� : " << frontSide / i * 100 << "%, �޸� : " << backSide / i * 100 <<"%\n";
		}
	}

	cout << endl << i << "�� ������ ���\n";
	cout << "�ո� : " << frontSide / i * 100 << "%, �޸� : " << backSide / i * 100 << "%\n";

	return 0;
}
