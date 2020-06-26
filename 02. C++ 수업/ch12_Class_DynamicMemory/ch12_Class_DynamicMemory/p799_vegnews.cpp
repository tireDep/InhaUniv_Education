#include<iostream>
#include"p793_strngbad.h"

using std::cout;

void CallMe1(StringBad &);	// 참조로 전달
void CallMe2(StringBad);	// 값으로 전달

int main()
{
	using std::endl;
	{
		cout << "내부 블록을 시작한다.\n";
		StringBad headLine1("Celery Stalks at Midnight");
		StringBad headLine2("Lettuce Prey");
		StringBad sports("Spinach Leaves Bowl for Dollars");

		cout << endl;
		cout << "headLine1 : " << headLine1 << endl;
		cout << "headLine2 : " << headLine2 << endl;
		cout << "sports : " << sports << endl;
		
		CallMe1(headLine1);
		cout << "headLine1 : " << headLine1 << endl;
		
		// ---------- 문제발생 코드 ---------- 
		// CallMe2(headLine2);
		// cout << "headLine2 : " << headLine2 << endl;

		// CallMe2() 함수 실행 이후, 바로 소멸자가 실행됨
		// ----------  문제발생 코드 ---------- 
		
		// ---------- 문제발생 코드 ----------
		// cout << "하나의 객체를 다른 객체로 초기화\n";
		// StringBad sailor = sports;
		// cout << "sailor : " << sailor << endl;

		// '='에 대한 연산자 오버로딩이 없어서 어떤 작동을 할 지 모름
		// 객체 생성시 생성자가 실행되지 않아서 어떤 객체인지 모름
		// ---------- 문제발생 코드 ----------

		// ---------- 문제발생 코드 ----------
		// cout << "하나의 객체를 다른 객체에 대입\n";
		// StringBad knot;
		// knot = headLine1;
		// cout << "knot : " << knot << endl;
		// cout << "이 블록을 빠져나온다.\n";

		// knot의 처음 데이터인 "C++"이 삭제되지 x
		// knot이 사라지면서 headLine1의 내용이 삭제됨
		// ---------- 문제발생 코드 ----------

		cout << endl;
	}
	/*
	소멸자 실행됨
	- 스택으로 이루어져 있기 때문에, 맨 마지막에 선언된 객체부터 파괴된다.
	*/

	cout << "main()의 끝\n";

	return 0;
}

void CallMe1(StringBad &rsb)
{
	cout << "\n참조로 전달된 StringBad\n";
	cout << "    \"" << rsb << "\"\n";
}

void CallMe2(StringBad rsb)
{
	cout << "\n값으로 전달된 StringBad\n";
	cout << "    \"" << rsb << "\"\n";

	// 이 함수 실행 후, 소멸자가 실행됨
}
