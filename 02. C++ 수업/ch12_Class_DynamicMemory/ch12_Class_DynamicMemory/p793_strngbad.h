#pragma once

#include<iostream>

class StringBad
{
private:
	char *str;	// 문자열을 지시하는 포인터
	int len;	// 문자열의 길이
	static int num_strings;	// 객체의 수

public:
	StringBad();	// 생성자
	StringBad(const char *s);	// 디폴트 생성자
	~StringBad();	// 소멸자

	friend std::ostream & operator<<(std::ostream & os, const StringBad &st);

};
