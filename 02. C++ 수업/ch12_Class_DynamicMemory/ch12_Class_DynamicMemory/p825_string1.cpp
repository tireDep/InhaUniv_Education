#define _CRT_SECURE_NO_WARNINGS

#include<cstring>
#include"p824_string1.h"

using std::cin;
using std::cout;

int String::num_string = 0;	// static 클래스 멤버 초기화

String::String(const char *s)	// c 스타일의 문자열부터 String 생성
{
	len = std::strlen(s);	// 문자열의 크기를 설정
	str = new char[len + 1];	// 기억 공간 대입
	std::strcpy(str, s);	// 포인터를 초기화
	num_string++;	// 객체 카운트 설정
}

String::String()	// 디폴트 생성자
{
	len = 4;
	str = new char[1];
	str[0] = '\0';	// 디폴트 문자열
	num_string++;
}

String::~String()
{
	--num_string;
	delete[] str;
}

String::String(const String &st)
{
	num_string++;	// static 멤버 갱신 처리
	len = st.len;	// 같은 크기로 설정
	str = new char[len + 1];	// 기억 공간 대입
	std:strcpy(str, st.str); // 문자열을 새 위치에 복사
}

String & String::operator=(const String &st)	// String을 String에 대입
{
	if (this == &st)
		return *this;

	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

String & String::operator=(const char * s)	// c 스타일의 문자열을 String에 대입
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

char & String::operator[](int i)	// const가 아닌 String에 읽기 - 쓰기 개별 문자 접근
{
	return str[i];
}

const char & String::operator[](int i) const	// const String에 읽기 전용 개별 문자 접근
{
	return str[i];
}

bool operator<(const String & st1, const String & st2)
{
	return (std::strcmp(st1.str, st2.str));
}

bool operator>(const String & st1, const String & st2)
{
	return st2 < st1;
}

bool operator==(const String & st1, const String & st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

ostream & operator<<(ostream & os, const String & st)	// 간단한 문자열 입력
{
	os << st.str;
	return os;
}

istream & operator >> (istream & is, String & st)	// 빠르고 지저분한 문자열 입력
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);

	if (is)
		st = temp;

	while (is&&is.get() != '\n')
		return is;
}

int String::HowMany()	// static 메서드
{
	return num_string;
}