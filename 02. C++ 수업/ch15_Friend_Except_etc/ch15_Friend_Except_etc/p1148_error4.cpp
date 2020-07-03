#include<iostream>
#include<cmath>
#include"p1147_exc_mean.h"

double Hmean(double a, double b) throw(Bad_Hmean);
double Gmean(double a, double b) throw(Bad_Gmean);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;

	cout << "두 수를 입력하십시오.\n";
	while (cin >> x >> y)
	{
		try
		{
			z = Hmean(x, y);
			cout << x << ", " << y << "의 조화 평균은 " << z << "입니다.\n";
			cout << x << ", " << y << "의 기하 평균은 " << Gmean(x, y) << "입니다.\n";
			cout << "다른 두 수를 입력하십시오. (끝내려면 q) : ";
		}
		catch(Bad_Hmean & bg)
		{
			bg.Mesg();
			cout << "다시 하십시오.\n";
			continue;
		}
		catch (Bad_Gmean &hg)
		{
			cout << hg.Mesg();
			cout << "Values used : " << hg.v1 << ", " << hg.v2 << endl;
			cout << "죄송합니다. 더 이상 진행할 수 없습니다.\n";
			break;
		}
	}
	cout << "프로그램을 종료합니다.\n";

	return 0;
}

double Hmean(double a, double b) throw(Bad_Hmean)
{
	if (a == -b)
		throw Bad_Hmean(a, b);
	return 2.0*a*b / (a + b);
}

double Gmean(double a, double b) throw(Bad_Gmean)
{
	if (a < 0 || b < 0)
		throw Bad_Gmean(a, b);
	return std::sqrt(a*b);
}