#include<iostream>
#include"p1120_tvfm.h"

bool Tv::VolUp()
{
	if (volume < MaxVal)
	{
		volume++;
		return true;
	}
	else
		return false;
}

bool Tv::VolDown()
{
	if (volume > MinVal)
	{
		volume--;
		return true;
	}
	else
		return false;
}

void Tv::ChanUp()
{
	if (channel < maxchannel)
		channel++;
	else
		channel = 1;
}

void Tv::ChanDown()
{
	if (channel > 1)
		channel--;
	else
		channel = maxchannel;
}

void Tv::Settings() const
{
	using std::cout;
	using std::endl;
	cout << "TV = " << (state == Off ? "OFF" : "ON") << endl;

	if (state == On)
	{
		cout << "���� : " << volume << endl;
		cout << "ä�� : " << channel << endl;
		cout << "��� : " << (mode == Antenna ? "������ ���" : "���̺� ���") << endl;
		cout << "�Է� : " << (input == TV ? "TV" : "DVD") << endl;

	}
}