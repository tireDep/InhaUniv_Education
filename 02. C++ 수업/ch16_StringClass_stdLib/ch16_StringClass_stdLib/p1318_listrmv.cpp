#include<iostream>
#include<list>
#include<algorithm>

void Show(int);
const int LIM = 10;

int main()
{
	using namespace std;

	int ar[LIM] = { 4,5,4,2,2,3,4,8,1,4 };
	list<int> la(ar, ar + LIM);
	list<int>lb(la);

	cout << "�������� ����Ʈ�� ����\n\n";
	for_each(la.begin(), la.end(), Show);
	cout << endl;

	la.remove(4);	// ����Ʈ���� �� 4�� ��� ����
	cout << "remove()�޼��带 ����� ��\n";
	cout << "la : ";
	for_each(la.begin(), la.end(), Show);
	cout << endl;

	list<int>::iterator last;
	last = remove(lb.begin(), lb.end(), 4);	// ���� ���� x, ���� �ϰ� ����ϰ� ��
	cout << "remove() �޼��带 ����� ��\n";
	cout << "lb : ";
	for_each(lb.begin(), lb.end(), Show);
	cout << endl;

	lb.erase(last, lb.end());	// ���� ���� ����Ʈ ���� ����
	cout << "erase() �޼��带 ����� ��\n";
	cout << "lb : ";
	for_each(lb.begin(), lb.end(), Show);
	cout << endl;

	return 0;

}

void Show(int v)
{
	std::cout << v << ' ';
}