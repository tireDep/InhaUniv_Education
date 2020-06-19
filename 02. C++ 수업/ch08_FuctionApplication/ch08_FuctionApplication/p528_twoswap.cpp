// 528p
// ����� Ư��ȭ

#include<iostream>

struct JOB_S
{
	char name[40];
	double salary;
	int floor;
};

template<typename T>
void Swap(T &a, T &b);

template<>	// ����� Ư��ȭ
void Swap<JOB_S>(JOB_S &j1, JOB_S &j2);

void Show(JOB_S &j);

using namespace std;

int main()
{
	int i = 10, j = 20;
	cout << "i, j = " << i << ", " << j << endl;
	cout << "�����Ϸ��� ������ int�� ��ȯ�⸦ ����ϸ�\n";
	Swap(i, j);
	cout << "���� i, j = " << i << ", " << j << endl;

	JOB_S sue = { "Susan Yaffee",73000.60,7 };
	JOB_S sidney = { "Sidney Tffee",78060.72,9 };

	cout << "\njob ��ȯ ��\n";
	Show(sue);
	Show(sidney);
	Swap(sue, sidney);
	cout << "\njob ��ȯ ��\n";
	Show(sue);
	Show(sidney);

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

template<>	// ����� Ư��ȭ
void Swap<JOB_S>(JOB_S &j1, JOB_S &j2)
{
	double t1;
	int t2;

	t1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t1;

	t2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t2;
}

void Show(JOB_S &j)
{
	cout << j.name << " : (" << j.floor << "���� ����) $" << j.salary << endl;
}