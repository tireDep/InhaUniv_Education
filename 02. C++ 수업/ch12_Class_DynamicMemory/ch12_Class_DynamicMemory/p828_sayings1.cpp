#include<iostream>
#include"p824_string1.h"

const int ArSize = 10;
const int MaxLen = 81;

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	String name;
	cout << "�ȳ��Ͻʴϱ�? ������ ��� �ǽʴϱ�?\n";
	cin >> name;

	cout << endl << name << "��! ������ ���� �Ӵ� " << ArSize << "�� �� �Է��� �ֽʽÿ�(�������� Enter)\n";
	
	String sayings[ArSize];	// ��ü���� �迭
	char temp[MaxLen];	// ���ڿ� ������ ���� �ӽ� ����
	int i = 0;

	for (i = 0; i < ArSize; i++)
	{
		cout << i + 1 << " : ";
		cin.get(temp, MaxLen);
		
		while (cin && cin.get() != '\n')	// ���� ������ �Է� ����
			continue;

		// cin : ����, ���� ���� + ���� Ű���� ���ۿ� ���ܵ� => space ������ �Է¹��� �� ����, enter�� ������ �Է� ����
		// cin.get() : ����, ���� ���� + ���ڸ� �Է� ���� => space ������ ��� �Է� ���� �� ����, enter�� ���͵� �Է¹��� ���ڷ� ����

		if (!cin || temp[0] == '\0')	// �Է��� �����߰ų� �� �� �Է��̸� i�� ������Ű�� ����
			break;
		else
			sayings[i] = temp;	// �����ε� ���� ������ ���
	}

	int total = i;	// �о���� �� �� ��
	if (total > 0)
	{
		cout << "\n������ ���� �Ӵ���� �Է��ϼ̽��ϴ�.\n";

		for (i = 0; i < total; i++)
			cout << sayings[i][0] << " : " << sayings[i] << endl;

		int shortest = 0;
		int first = 0;
		for (i = 1; i < total; i++)
		{
			if (sayings[i].Length() < sayings[shortest].Length())
				shortest = i;
			if (sayings[i] < sayings[first])
				first = i;
		}

		cout << "\n���� ª�� �Ӵ� : " << sayings[shortest] << endl;
		cout << "���� ������ ���� �տ� ������ �Ӵ� : " << sayings[first] << endl;
		cout << "\n�� ���α׷��� " << String::HowMany() << "���� String ��ü�� ����Ͽ����ϴ�. �̻�!\n\n";
	}
	else
		cout << "\n�Է±���! �̻�!\n";

	return 0;
}