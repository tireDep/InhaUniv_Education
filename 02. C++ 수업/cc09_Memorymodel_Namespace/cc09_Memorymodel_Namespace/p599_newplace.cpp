#include<iostream>
#include<new>	// ��ġ���� new

const int BUF = 512;
const int N = 5;
char buffer[BUF];

using namespace std;

int main()
{
	double *pd1, *pd2;

	cout << "new�� ��ġ ���� new�� ù ��° ȣ��\n";
	pd1 = new double[N];	// �� ���
	pd2 = new (buffer)double[N];	// buffer �迭 ���
	for (int i = 0; i < N; i++)
		pd2[i] = pd1[i] = 1000 + 20.0 + i;
	cout << "�޸� �ּ�\n" << pd1 << " : ��; ";
	cout << (void *)buffer << " : ����" << endl;
	cout << "\n�޸� ����\n";
	for (int i = 0; i < N; i++)
	{
		cout << &pd1[i] << "�� " << pd1[i] << "; ";
		cout << &pd2[i] << "�� " << pd2[i] << "\n";
	}

	cout << "\nnew�� ��ġ ���� new�� �� ��° ȣ��\n";
	double *pd3, *pd4;
	pd3 = new double[N];	// ���ο� �ּҸ� ã�Ƽ�
	pd4 = new (buffer)double[N];	// ���� �����͸� �� ���� ��
	for (int i = 0; i < N; i++)
		pd4[i] = pd3[i] = 1000 + 40.0 + i;
	cout << "\n�޸� ����\n";
	for (int i = 0; i < N; i++)
	{
		cout << &pd3[i] << "�� " << pd3[i] << "; ";
		cout << &pd4[i] << "�� " << pd4[i] << "\n";
	}

	cout << "\nnew�� ��ġ ���� new�� �� ��° ȣ��\n";
	delete[] pd1;
	pd1 = new double[N];
	pd2 = new (buffer + N * sizeof(double)) double[N];
 	for (int i = 0; i < N; i++)
		pd2[i] = pd1[i] = 1000 + 60.0 + i;
	cout << "\n�޸� ����\n";
	for (int i = 0; i < N; i++)
	{
		cout << &pd1[i] << "�� " << pd1[i] << "; ";
		cout << &pd2[i] << "�� " << pd2[i] << "\n";
	}

	delete[] pd1;
	delete[] pd3;

	return 0;
}