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

	cout << "�� ���� �Է��Ͻʽÿ�.\n";
	while (cin >> x >> y)
	{
		try
		{
			z = Hmean(x, y);
			cout << x << ", " << y << "�� ��ȭ ����� " << z << "�Դϴ�.\n";
			cout << x << ", " << y << "�� ���� ����� " << Gmean(x, y) << "�Դϴ�.\n";
			cout << "�ٸ� �� ���� �Է��Ͻʽÿ�. (�������� q) : ";
		}
		catch(Bad_Hmean & bg)
		{
			bg.Mesg();
			cout << "�ٽ� �Ͻʽÿ�.\n";
			continue;
		}
		catch (Bad_Gmean &hg)
		{
			cout << hg.Mesg();
			cout << "Values used : " << hg.v1 << ", " << hg.v2 << endl;
			cout << "�˼��մϴ�. �� �̻� ������ �� �����ϴ�.\n";
			break;
		}
	}
	cout << "���α׷��� �����մϴ�.\n";

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