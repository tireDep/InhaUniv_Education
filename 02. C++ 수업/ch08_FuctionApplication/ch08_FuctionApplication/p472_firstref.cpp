// ��������
// 472p

#include<iostream>

using namespace std;

int main()
{
	int rats = 101;
	int & rodents = rats;	

	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;
	rodents++;
	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;

	cout << "rats�� �ּ� = " << &rats;
	cout << ", rodents�� �ּ� = " << &rodents << endl;

	return 0;
}

/*
-----------------------------------------------------
int & rodents = rats �� 
���������� int * const pr = &rats �� ���� ����
-----------------------------------------------------
*/