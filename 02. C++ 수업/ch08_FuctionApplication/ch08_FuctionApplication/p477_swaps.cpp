// ��������
// 477p

#include<iostream>

void SwapR(int &a, int &b);	// ������ ����
void SwapP(int *a, int *b);	// ������ �ּҸ� ����
void SwapV(int a, int b);	// ������ ���� ����

/*
-------------------------------------------------------------
void SwapR(int &a, int &b) ������ ���� ��ü�� ������ ��,
���� ����Ǵ� ���� ������ �ʴ´ٸ� �Ű������� const �ٿ��� ��
-------------------------------------------------------------
*/

using namespace std;

int main()
{
	int wallet1 = 3000;
	int wallet2 = 3500;

	cout << "���� 1 = " << wallet1 << "��";
	cout << ", ���� 2 = " << wallet2 << "��\n";

	cout << "\n������ �̿��Ͽ� ������� ��ȯ\n";
	SwapR(wallet1, wallet2);
	cout << "���� 1 = " << wallet1 << "��";
	cout << ", ���� 2 = " << wallet2 << "��\n";

	cout << "\n�����͸� �̿��Ͽ� ������� ��ȯ\n";
	SwapP(&wallet1, &wallet2);
	cout << "���� 1 = " << wallet1 << "��";
	cout << ", ���� 2 = " << wallet2 << "��\n";

	cout << "\n������ �����Ͽ� ���뱳ȯ �õ�\n";
	SwapV(wallet1, wallet2);
	cout << "���� 1 = " << wallet1 << "��";
	cout << ", ���� 2 = " << wallet2 << "��\n";
}

void SwapR(int &a, int &b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}

void SwapP(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void SwapV(int a, int b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}
