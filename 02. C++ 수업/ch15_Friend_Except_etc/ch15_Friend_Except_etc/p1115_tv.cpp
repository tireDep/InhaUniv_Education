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
		cout << "볼륨 : " << volume << endl;
		cout << "채널 : " << channel << endl;
		cout << "모드 : " << (mode == Antenna ? "지상파 방송" : "케이블 방송") << endl;
		cout << "입력 : " << (input == TV ? "TV" : "DVD") << endl;

	}
}