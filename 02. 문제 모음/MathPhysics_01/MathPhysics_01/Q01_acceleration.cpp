// Q. ������� ���ӵ� a�� �̷��ӵ� v�� �־����� ��, ����Ⱑ �̷��ϱ� ���� �ּ� Ȱ�� ���̸� ����ϴ� ���α׷� �ۼ�
// ���� ���� : v^2 / 2a
// ����ڿ��� '����/��(m/s)' ������ v�� '����/��^2(m/s^2)' ������ ���ӵ��� �Է��ϵ��� �˷��ְ�,
// �ּ� Ȱ�� ���̸� ���

// [���]
// Speed and Acceleration : 60 3.5
// Minimum runway length : 514.286

// +)
// ���ӵ� : ���� �ð��� �ӵ��� ��ȭ��
// ���ӵ� ���ϴ� ����
// ���ӵ� = (���߼ӵ� - ó���ӵ�) / �ð�
// a = (v1 - v0) / t

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	double inputSpeed, inputAcceleration;
	double minWay = 0;

	cout << "Input Speed and Acceleration : ";
	cin >> inputSpeed >> inputAcceleration;

	minWay = pow(inputSpeed, 2) / (2 * inputAcceleration);
	cout << "Minimum Runway Lenght(m) : " << minWay << endl;
	
	return 0;
}

/*
----------------------------------------------
�ӵ�(v) : m/s
���ӵ�(a) : m/s^2

���� ���
-> (m/s)^2 / m/s^2
= (m^2/s^2) / m/s^2
= m	==> ��еǰ� ���� ��
----------------------------------------------
*/