// Q. �Ҽ� => ����� 1�� �ڱ� �ڽŸ��� ������ ��
// ��� => � ���� �������� �� ������ �������� �ϴ� �ڿ���
// 2�� 1000 ���̿� �����ϴ� ��� �Ҽ��� ����ϴ� ���α׷� �ۼ�

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int check = 0;
	int tmp = 1;
	cout << "�Ҽ� ���" << endl;
	cout << 2 << " ";
	for (int i = 3; i <= 1000; i+=2)
	{
		check = 0;

		for (int j = 3; j <= sqrt(i); j++) // or j <= i/2
		{
			if (i % j == 0)
				check++;
		}
		if (check == 0)
		{
			tmp++;
			cout << i << " ";
		}
	}
	cout << "���� : " << tmp << endl;
}

/*
int check = 0;
cout << "�Ҽ� ���" << endl;
for (int i = 2; i <= 1000; i++)
{
	if (i % 100 == 0)
		cout << endl;
	
	for (int j = 1; j <= i; j++)
	{
		if (i % j == 0)
		check++;
	}
	if (check == 2)
		cout << i << " ";
	check = 0;
}

*/