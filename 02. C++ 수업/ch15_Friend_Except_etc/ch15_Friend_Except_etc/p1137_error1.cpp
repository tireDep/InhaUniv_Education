#include<iostream>
#include<cstdlib>

double Hmean(double a, double b);

int main()
{
	double x, y, z;

	std::cout << "�� ���� �Է��Ͻʽÿ�.\n";
	while (std::cin >> x >> y)
	{
		z = Hmean(x, y);
		std::cout << x << ", " << y << "�� ��ȭ�����" << z << "�Դϴ�.\n";
		std::cout << "�ٸ� �� ���� �Է��Ͻʽÿ�.(�������� q) : ";
	}
	std::cout << "���α׷��� �����մϴ�.\n";

	return 0;
}

double Hmean(double a, double b)
{
	if (a == -b)
	{
		std::cout << "�Ű��������� Hmean()�� ������ �� �����ϴ�.\n";
		std::abort();	// ���â �߻�
	}

	return 2.0 * a *b / (a + b);
}
