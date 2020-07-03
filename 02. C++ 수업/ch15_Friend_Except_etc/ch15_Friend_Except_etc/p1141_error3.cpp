#include<iostream>
#include<cstdlib>

double Hmean(double a, double b);

int ㅛㄷ()
{
	double x, y, z;

	std::cout << "두 수를 입력하십시오.\n";
	while (std::cin >> x >> y)
	{
		try
		{
			z = Hmean(x, y);
		}
		catch (const char *s)	// 예외 핸들러의 시작
		{
			std::cout << s << std::endl;
			std::cout << "두 수를 새로 입력하십시오. : ";
			continue;
		}	// 예외 핸들러의 끝
		std::cout << x << ", " << y << "의 조화평균은" << z << "입니다.\n";
		std::cout << "다른 두 수를 입력하십시오.(끝내려면 q) : ";
	}
	std::cout << "프로그램을 종료합니다.\n";

	return 0;
}

double Hmean(double a, double b)
{
	if (a == -b)
		throw "잘못된 Hmean() 매개 변수 : a = -b는 허용되지 않습니다.\n";
	return 2.0 * a *b / (a + b);
}
