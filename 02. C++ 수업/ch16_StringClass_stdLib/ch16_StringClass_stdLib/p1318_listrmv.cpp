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

	cout << "오리지널 리스트의 내용\n\n";
	for_each(la.begin(), la.end(), Show);
	cout << endl;

	la.remove(4);	// 리스트에서 값 4를 모두 삭제
	cout << "remove()메서드를 사용한 후\n";
	cout << "la : ";
	for_each(la.begin(), la.end(), Show);
	cout << endl;

	list<int>::iterator last;
	last = remove(lb.begin(), lb.end(), 4);	// 실질 삭제 x, 제외 하고 사용하게 됨
	cout << "remove() 메서드를 사용한 후\n";
	cout << "lb : ";
	for_each(lb.begin(), lb.end(), Show);
	cout << endl;

	lb.erase(last, lb.end());	// 쓸모 없는 리스트 범위 삭제
	cout << "erase() 메서드를 사용한 후\n";
	cout << "lb : ";
	for_each(lb.begin(), lb.end(), Show);
	cout << endl;

	return 0;

}

void Show(int v)
{
	std::cout << v << ' ';
}