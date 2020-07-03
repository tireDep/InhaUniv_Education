#include<iostream>
#include"p1120_tvfm.h"

int main()
{
	using std::cout;
	Tv s42;
	cout << "42\" TV의 초기 설정 값\n";
	s42.Settings();
	s42.OnOff();
	s42.ChanUp();
	cout << "\n42\" TV의 변경된 설정 값\n";
	s42.Settings();

	Remote grey;

	grey.Set_Chan(s42, 10);
	grey.Volup(s42);
	grey.Volup(s42);
	cout<<"\n리모콘 사용 후 42\" TV의 설정 값\n";
	s42.Settings();

	Tv s58(Tv::On);
	s58.Set_Mode();
	grey.Set_Chan(s58, 28);
	cout << "\n58\" TV의 설정 값\n";
	s58.Settings();

	return 0;
}