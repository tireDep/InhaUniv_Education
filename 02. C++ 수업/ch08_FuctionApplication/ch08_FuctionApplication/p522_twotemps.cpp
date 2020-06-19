// 522p
// ���ø��� �����ε�

#include<iostream>

template<typename T>
void Swap(T &a, T &b);	// ���� ���ø�

template<typename T>
void Swap(T *a, T *b, int n);	// �߰� ���ø�

void Show(int a[]);

const int arrSize = 8;

using namespace std;

int main()
{
	int i = 10, j = 20;
	cout << "i, j = " << i << ", " << j << endl;
	cout << "�����Ϸ��� ������ int�� ��ȯ�⸦ ����ϸ�\n";
	Swap(i, j);
	cout << "���� i, j = " << i << ", " << j << endl;

	int d1[arrSize] = { 0,7,0,4,1,7,7,6 };
	int d2[arrSize] = { 0,6,2,0,1,9,6,9 };

	cout << "\n���� �迭\n";
	Show(d1);
	Show(d2);
	Swap(d1, d2, arrSize);
	cout << "\n��ȯ�� �迭\n";
	Show(d1);
	Show(d2);

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

template<typename T>
void Swap(T *a, T *b, int n)
{
	T temp;
	for (int i = 0; i < n; i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

void Show(int a[])
{
	cout << a[0] << a[1] << "/";
	cout << a[2] << a[3] << "/";

	for (int i = 4; i < arrSize; i++)
		cout << a[i];

	cout << endl;
}