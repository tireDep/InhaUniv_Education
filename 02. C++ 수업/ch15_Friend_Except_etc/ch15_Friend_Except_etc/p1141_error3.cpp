#include<iostream>
#include<cstdlib>

double Hmean(double a, double b);

int �ˤ�()
{
	double x, y, z;

	std::cout << "�� ���� �Է��Ͻʽÿ�.\n";
	while (std::cin >> x >> y)
	{
		try
		{
			z = Hmean(x, y);
		}
		catch (const char *s)	// ���� �ڵ鷯�� ����
		{
			std::cout << s << std::endl;
			std::cout << "�� ���� ���� �Է��Ͻʽÿ�. : ";
			continue;
		}	// ���� �ڵ鷯�� ��
		std::cout << x << ", " << y << "�� ��ȭ�����" << z << "�Դϴ�.\n";
		std::cout << "�ٸ� �� ���� �Է��Ͻʽÿ�.(�������� q) : ";
	}
	std::cout << "���α׷��� �����մϴ�.\n";

	return 0;
}

double Hmean(double a, double b)
{
	if (a == -b)
		throw "�߸��� Hmean() �Ű� ���� : a = -b�� ������ �ʽ��ϴ�.\n";
	return 2.0 * a *b / (a + b);
}
