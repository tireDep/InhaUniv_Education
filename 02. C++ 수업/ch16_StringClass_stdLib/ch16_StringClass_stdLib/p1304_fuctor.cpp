/*
-------------------------------------------------------------------
함수 객체
- 함수처럼 동작하는 객체
- 함수처럼 동작하려면 객체가 operator()를 정의해야 함

- 함수 객체는 함수처럼 동작하는 객체이므로 다른 멤버 변수와 멤버 함수를 가질 수 있고,
일반 함수에서 하지 못하는 지원을 받을 수 있음
- 함수 객체의 서명이 같더라도 객체 타입이 다르면 서로 전혀 다른 타입으로 인식
- 속도가 일반 함수보다 빠르다(인라인 가능, 컴파일러가 쉽게 최적화)
- 특정 상황에서 함수 객체는 함수보다 빠름
-> 임의 함수를 다른 함수에 인자로 전달한 후 사용할 때, 일반함수는 인라인화 될 수 없지만, 객체는 인라인화 될 수 있다

펑크터(Fuctor)
- 제너레이터(generator)는 매개변수 없이 호출하는 함수
- 단항 함수(unary function)는 하나의 매개변수로 호출하는 함수
- 이항 함수(binary fuction)는 두 개의 매개변수로 호출하는 함수

- bool 값을 리턴하는 단항 함수는 조건(predicate)이다
- bool 값을 리턴하는 이항 함수는 이항 조건(binary predicate)이다

- 장점
1) 함수 객체는 내부 변수를 가질 수 있음, 사용자가 함수 객체를 사용하면서 다른 상태를 가질 수 있음
2) 함수 객체는 자신만의 타입을 가질 수 있음, 이를 이용해 각각 다른 함수-객체를 갖는 컨테이너를 만들 수 있음
3) 속도가 빠름, 함수가 inline으로 사용할 수 없는 곳에 함수 객체를 inline으로 사용할 수 있음
-------------------------------------------------------------------
*/

#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>

template<class T>	// 펑크터 클래스가 operator() ()를 정의한다
class TooBig
{
private:
	T cutoff;
public:
	TooBig(const T &t) :cutoff(t) { }
	bool operator() (const T &v) { return v > cutoff; }
};

void OutInt(int n) { std::cout << n << " "; }

int main()
{
	using std::list;
	using std::cout;
	using std::endl;

	TooBig<int> f100(100);
	int vals[10] = { 50,100,90,180,60,210,415,88,188,201 };
	list<int>yadayada(vals, vals + 10);	// range 생성자
	list<int>etcetera(vals, vals + 10);

	cout << "원래의 리스트\n";
	for_each(yadayada.begin(), yadayada.end(), OutInt);
	cout << endl;
	yadayada.remove_if(f100);	// 이름이 있는 함수 객체 사용	// functor
	etcetera.remove_if(TooBig<int>(200));	// 함수 객체를 생성
	cout << "정비된 리스트\n";
	for_each(yadayada.begin(), yadayada.end(), OutInt);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), OutInt);
	cout << endl;

	return 0;

}
