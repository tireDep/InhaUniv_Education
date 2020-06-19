// 520p
// �Լ� ���ø� ����ϱ�

#include<iostream>

template <typename T>
void Swap(T &a, T &b);	
// �Լ� ���ø� ����
// T�� Any ���� ����

using namespace std;

int main()
{
	int i = 10, j = 20;

	cout << "i, j = " << i << ", " << j << endl;
	cout << "�����Ϸ��� ������ int�� ��ȯ�⸦ ����ϸ�\n";
	Swap(i, j);
	cout<<"���� i, j = " << i << ", " << j << endl;

	double x = 24.5, y = 81.7;
	cout << "\nx, y = " << x << ", " << y << endl;
	cout << "�����Ϸ��� ������ double�� ��ȯ�⸦ ����ϸ�\n";
	Swap(x, y);
	cout << "���� x, y = " << x << ", " << y << endl;

	return 0;

}

template <typename T>
void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}