// Q. ī�� �մ��� ���Ḧ �ֹ��� �ð��� �־��� ��,
// k�� ���� �ֹ��� �ִ� �� �� ���Դ��� ���϶�.

// [����]
// ���� �ֹ��� ���� �ð��� ��� �ִ� �迭 order_time��
// �ڿ��� k�� �Ű������� �־��� ��, k�� ���� �ֹ���
// �ִ� �� �� ���Դ��� return

// 24�ð� ǥ���
// k�� 1�̻� 120 ���� �ڿ� ��
// k���� �����ϴ� ������ ������ ������ ���� �ֹ� ���� ī��Ʈ


#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	string orderTime[] = { "12:10", "12:20", "12:40", "12:40", "12:50", "13:00", "13:05", "13:06", "13:07", "13:08", "13:20" };
	const int arrSize = sizeof(orderTime) / sizeof(string);
	int inputTime;

	cout << "�ð� �Է� : ";
	cin >> inputTime;

	string *tempTime = new string[arrSize];
	for (int i = 0; i < arrSize; i++)
		tempTime[i] = orderTime[i];

	int *minTime = new int[arrSize];
	for (int i = 0; i < arrSize; i++)	// �ʱ�ȭ
		minTime[i] = 0;

	// �ð� ��ȯ string -> int
	// ��� ������ �����ؼ� �������� ����ȭ��
	for (int i = 0; i < arrSize; i++)
	{
		minTime[i] += tempTime[i].back() - '0';
		tempTime[i].pop_back();
		minTime[i] += (tempTime[i].back() - '0') * 10;
		tempTime[i].pop_back();
		tempTime[i].pop_back();

		minTime[i] += (tempTime[i].back() - '0') * 60;
		tempTime[i].pop_back();
		minTime[i] += (tempTime[i].back() - '0') * 60 * 10;
	}

	int temp = 0;
	int highOrder = 0;
	for (int i = 0; i < arrSize; i++)
	{
		temp = 1;	// ó�� �ֹ�
		for (int j = i + 1; j < arrSize; j++)
		{
			if (abs(minTime[i] - minTime[j]) <= inputTime)
				temp++;
			else
				break;
		}
		if (temp > highOrder)
			highOrder = temp;
	}

	cout << "�ִ��ֹ� : " << highOrder << endl;

	delete[] minTime;

	return 0;
}
