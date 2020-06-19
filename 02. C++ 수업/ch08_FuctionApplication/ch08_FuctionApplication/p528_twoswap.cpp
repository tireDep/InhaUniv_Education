// 528p
// 명시적 특수화

#include<iostream>

struct JOB_S
{
	char name[40];
	double salary;
	int floor;
};

template<typename T>
void Swap(T &a, T &b);

template<>	// 명시적 특수화
void Swap<JOB_S>(JOB_S &j1, JOB_S &j2);

void Show(JOB_S &j);

using namespace std;

int main()
{
	int i = 10, j = 20;
	cout << "i, j = " << i << ", " << j << endl;
	cout << "컴파일러가 생성한 int형 교환기를 사용하면\n";
	Swap(i, j);
	cout << "이제 i, j = " << i << ", " << j << endl;

	JOB_S sue = { "Susan Yaffee",73000.60,7 };
	JOB_S sidney = { "Sidney Tffee",78060.72,9 };

	cout << "\njob 교환 전\n";
	Show(sue);
	Show(sidney);
	Swap(sue, sidney);
	cout << "\njob 교환 후\n";
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

template<>	// 명시적 특수화
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
	cout << j.name << " : (" << j.floor << "층에 거주) $" << j.salary << endl;
}