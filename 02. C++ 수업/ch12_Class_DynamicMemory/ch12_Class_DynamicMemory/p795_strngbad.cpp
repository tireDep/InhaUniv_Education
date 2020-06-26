#define _CRT_SECURE_NO_WARNINGS

// #include<iostream>
#include<cstring>
#include"p793_strngbad.h"

using std::cout;

int StringBad::num_strings = 0;	// 클래스 멤버를 초기화

StringBad::StringBad()
{
	// num_strings++;
	// std::cout << num_strings <<" ";
	len = 4;
	str = new char[4];
	std::strcpy(str, "C++");	// 디폴트 문자열
	num_strings++;
	cout << num_strings << " : \"" << str << "\" 디폴트 객체 생성\n";	// 추적용 Msg
}

StringBad::StringBad(const char *s)
{
	len = std::strlen(s);	// 문자열의 크기 설정
	str = new char[len + 1];	// 기억 공간 대입
	std::strcpy(str, s);	// 포인터 초기화
	num_strings++;	// 생성된 객체 수 카운트
	cout << num_strings << " : \"" << str << "\" 객체 생성\n";	// 추적용 Msg
}

StringBad::~StringBad()	// 꼭 필요한 소멸자
{
	// num_strings--;
	// std::cout << num_strings << " ";

	cout << "\"" << str << "\" 객체 파괴, ";	// 추적용 Msg
	--num_strings;
	cout << "남은 객체 수 : " << num_strings << "\n";	// 추적용 Msg
	delete[] str;
}

std::ostream & operator<<(std::ostream&os, const StringBad &st)
{
	os << st.str;
	return os;
}