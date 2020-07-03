#pragma once

#include<iostream>

class Bad_Hmean
{
private:
	double v1;
	double v2;

public:
	Bad_Hmean(double a = 0, double b = 0) :v1(a), v2(b) { }
	void Mesg();
};

inline void Bad_Hmean::Mesg()
{
	std::cout << "Hmean(" << v1 << ", " << v2 << ") : �߸��� �Ű����� : a = -b\n";
}

class Bad_Gmean
{
public:
	double v1;
	double v2;
	Bad_Gmean(double a = 0, double b = 0) :v1(a), v2(b) { }
	const char *Mesg();
};

inline const char *Bad_Gmean::Mesg()
{
	return "Gmean() �Ű��������� >= 0 �̾�� �մϴ�.\n";
}