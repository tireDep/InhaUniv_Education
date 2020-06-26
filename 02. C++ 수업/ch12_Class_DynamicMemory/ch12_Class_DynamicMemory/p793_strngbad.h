#pragma once

#include<iostream>

class StringBad
{
private:
	char *str;	// ���ڿ��� �����ϴ� ������
	int len;	// ���ڿ��� ����
	static int num_strings;	// ��ü�� ��

public:
	StringBad();	// ������
	StringBad(const char *s);	// ����Ʈ ������
	~StringBad();	// �Ҹ���

	friend std::ostream & operator<<(std::ostream & os, const StringBad &st);

};
