#define _CRT_SECURE_NO_WARNINGS

#include<cstring>
#include"p824_string1.h"

using std::cin;
using std::cout;

int String::num_string = 0;	// static Ŭ���� ��� �ʱ�ȭ

String::String(const char *s)	// c ��Ÿ���� ���ڿ����� String ����
{
	len = std::strlen(s);	// ���ڿ��� ũ�⸦ ����
	str = new char[len + 1];	// ��� ���� ����
	std::strcpy(str, s);	// �����͸� �ʱ�ȭ
	num_string++;	// ��ü ī��Ʈ ����
}

String::String()	// ����Ʈ ������
{
	len = 4;
	str = new char[1];
	str[0] = '\0';	// ����Ʈ ���ڿ�
	num_string++;
}

String::~String()
{
	--num_string;
	delete[] str;
}

String::String(const String &st)
{
	num_string++;	// static ��� ���� ó��
	len = st.len;	// ���� ũ��� ����
	str = new char[len + 1];	// ��� ���� ����
	std:strcpy(str, st.str); // ���ڿ��� �� ��ġ�� ����
}

String & String::operator=(const String &st)	// String�� String�� ����
{
	if (this == &st)
		return *this;

	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

String & String::operator=(const char * s)	// c ��Ÿ���� ���ڿ��� String�� ����
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

char & String::operator[](int i)	// const�� �ƴ� String�� �б� - ���� ���� ���� ����
{
	return str[i];
}

const char & String::operator[](int i) const	// const String�� �б� ���� ���� ���� ����
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

ostream & operator<<(ostream & os, const String & st)	// ������ ���ڿ� �Է�
{
	os << st.str;
	return os;
}

istream & operator >> (istream & is, String & st)	// ������ �������� ���ڿ� �Է�
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);

	if (is)
		st = temp;

	while (is&&is.get() != '\n')
		return is;
}

int String::HowMany()	// static �޼���
{
	return num_string;
}