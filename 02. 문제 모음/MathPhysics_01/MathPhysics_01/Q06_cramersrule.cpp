// Q. ���� 2x2 1�� �������� ũ������ ������ ����� Ǯ���ϴ� ���α׷��� �ۼ��϶�
// ax + by = e
// cx + dy = f
// x = (ed - bf) / (ad - bc)
// y = (af - ec) / (ad - bc)
// a,b,c,d,e,f ���� �Է¹޾� ����� ����϶�
// ad-bc = 0�̸� "�ذ� ����" ���

#include<iostream>

using namespace std;

int main()
{
	int a, b, c, d, e, f;
	int x, y;

	cout << "ax + by = e" << endl << "cx + dy = f " << endl;
	cout << "�����Է�(a, b, c, d, e, f) : ";
	cin >> a >> b >> c >> d >> e >> f;

	if (a*d - b*c == 0)
		cout << "�����\n�ذ� �������� ����" << endl;
	else
	{
		x = (e * d - b * f) / (a * d - b * c);
		y = (a * f - e * c) / (a * d - b * c);

		cout << "�����\nx : " << x << endl << "y : " << y << endl;
	}

	return 0;
}