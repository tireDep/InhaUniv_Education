#define _CRT_SECURE_NO_WARNINGS

// #include<iostream>
#include<cstring>
#include"p793_strngbad.h"

using std::cout;

int StringBad::num_strings = 0;	// Ŭ���� ����� �ʱ�ȭ

StringBad::StringBad()
{
	// num_strings++;
	// std::cout << num_strings <<" ";
	len = 4;
	str = new char[4];
	std::strcpy(str, "C++");	// ����Ʈ ���ڿ�
	num_strings++;
	cout << num_strings << " : \"" << str << "\" ����Ʈ ��ü ����\n";	// ������ Msg
}

StringBad::StringBad(const char *s)
{
	len = std::strlen(s);	// ���ڿ��� ũ�� ����
	str = new char[len + 1];	// ��� ���� ����
	std::strcpy(str, s);	// ������ �ʱ�ȭ
	num_strings++;	// ������ ��ü �� ī��Ʈ
	cout << num_strings << " : \"" << str << "\" ��ü ����\n";	// ������ Msg
}

StringBad::~StringBad()	// �� �ʿ��� �Ҹ���
{
	// num_strings--;
	// std::cout << num_strings << " ";

	cout << "\"" << str << "\" ��ü �ı�, ";	// ������ Msg
	--num_strings;
	cout << "���� ��ü �� : " << num_strings << "\n";	// ������ Msg
	delete[] str;
}

std::ostream & operator<<(std::ostream&os, const StringBad &st)
{
	os << st.str;
	return os;
}