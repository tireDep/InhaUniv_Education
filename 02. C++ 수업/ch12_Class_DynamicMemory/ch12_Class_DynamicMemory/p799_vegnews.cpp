#include<iostream>
#include"p793_strngbad.h"

using std::cout;

void CallMe1(StringBad &);	// ������ ����
void CallMe2(StringBad);	// ������ ����

int main()
{
	using std::endl;
	{
		cout << "���� ����� �����Ѵ�.\n";
		StringBad headLine1("Celery Stalks at Midnight");
		StringBad headLine2("Lettuce Prey");
		StringBad sports("Spinach Leaves Bowl for Dollars");

		cout << endl;
		cout << "headLine1 : " << headLine1 << endl;
		cout << "headLine2 : " << headLine2 << endl;
		cout << "sports : " << sports << endl;
		
		CallMe1(headLine1);
		cout << "headLine1 : " << headLine1 << endl;
		
		// ---------- �����߻� �ڵ� ---------- 
		// CallMe2(headLine2);
		// cout << "headLine2 : " << headLine2 << endl;

		// CallMe2() �Լ� ���� ����, �ٷ� �Ҹ��ڰ� �����
		// ----------  �����߻� �ڵ� ---------- 
		
		// ---------- �����߻� �ڵ� ----------
		// cout << "�ϳ��� ��ü�� �ٸ� ��ü�� �ʱ�ȭ\n";
		// StringBad sailor = sports;
		// cout << "sailor : " << sailor << endl;

		// '='�� ���� ������ �����ε��� ��� � �۵��� �� �� ��
		// ��ü ������ �����ڰ� ������� �ʾƼ� � ��ü���� ��
		// ---------- �����߻� �ڵ� ----------

		// ---------- �����߻� �ڵ� ----------
		// cout << "�ϳ��� ��ü�� �ٸ� ��ü�� ����\n";
		// StringBad knot;
		// knot = headLine1;
		// cout << "knot : " << knot << endl;
		// cout << "�� ����� �������´�.\n";

		// knot�� ó�� �������� "C++"�� �������� x
		// knot�� ������鼭 headLine1�� ������ ������
		// ---------- �����߻� �ڵ� ----------

		cout << endl;
	}
	/*
	�Ҹ��� �����
	- �������� �̷���� �ֱ� ������, �� �������� ����� ��ü���� �ı��ȴ�.
	*/

	cout << "main()�� ��\n";

	return 0;
}

void CallMe1(StringBad &rsb)
{
	cout << "\n������ ���޵� StringBad\n";
	cout << "    \"" << rsb << "\"\n";
}

void CallMe2(StringBad rsb)
{
	cout << "\n������ ���޵� StringBad\n";
	cout << "    \"" << rsb << "\"\n";

	// �� �Լ� ���� ��, �Ҹ��ڰ� �����
}
