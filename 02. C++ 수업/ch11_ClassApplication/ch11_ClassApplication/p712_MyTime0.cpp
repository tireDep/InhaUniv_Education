#include<iostream>
#include"MyTime0.h"

Time::Time() : hours(0), minutes(0)
{

}

Time::Time(int h, int m) : hours(h), minutes(m)
{

}

void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::AddHr(int h)
{
	hours += h;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

// Time Time::Sum(const Time &t) const
// {
// 	Time sum;
// 	sum.minutes = minutes + t.minutes;
// 	sum.hours = hours + t.hours + sum.minutes / 60;
// 	sum.minutes %= 60;
// 	
// 	return sum;
// }

void Time::Show() const
{
	std::cout << hours << "�ð�, " << minutes << "��";
}

// ������ �����ε�
Time Time::operator+(const Time & t) const
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;

	return sum;
}

Time Time::operator-(const Time & t) const
{
	Time sum;
	sum.minutes = minutes - t.minutes;
	sum.hours = hours - t.hours + sum.minutes / 60;
	sum.minutes %= 60;

	return sum;
}

Time Time::operator*(const int &n) const
{
	Time sum;
	sum.minutes = minutes * n;
	sum.hours = hours * n + sum.minutes / 60;
	sum.minutes %= 60;

	return sum;
}

Time Time::operator/(const int &n) const
{
	Time sum;
	if (n != 0)
	{
		sum.minutes = minutes / n;
		sum.hours = hours / n;
		sum.minutes %= 60;
	}
	else
		std::cout << "0���� ���� �� ����\n";
	return sum;
}
