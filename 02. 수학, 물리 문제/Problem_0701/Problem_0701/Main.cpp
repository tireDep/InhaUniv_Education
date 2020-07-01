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
	// string time = "12:40";
	// int min = 0;
	// min += time.back() - '0';
	// time.pop_back();
	// min += (time.back() - '0') * 10;
	// time.pop_back();
	// time.pop_back();
	// 
	// int hour = 0;
	// hour += time.back() - '0';
	// time.pop_back();
	// hour += (time.back() - '0') * 10;
	// 
	// cout << hour << " : " << min << endl;
	// /* string to int */

	// testCase
	string orderTime[] = { "12:10", "12:20", "12:40", "12:40", "12:50", "13:00", "13:20" , "13:05", "13:06", "13:07", "13:08", "13:20" };
	const int arrSize = sizeof(orderTime) / sizeof(string);
	int k = 20;
	// testCase

	string *tempTime = new string[arrSize];
	for (int i = 0; i < arrSize; i++)
		tempTime[i] = orderTime[i];

	int *minTime = new int[arrSize];
	int *hourTime = new int[arrSize];
	for (int i = 0; i < arrSize; i++)	// �ʱ�ȭ
	{
		minTime[i] = 0;
		hourTime[i] = 0;
	}

	for (int i = 0; i < arrSize; i++)
	{
		minTime[i] += tempTime[i].back() - '0';
		tempTime[i].pop_back();
		minTime[i] += (tempTime[i].back() - '0') * 10;
		tempTime[i].pop_back();
		tempTime[i].pop_back();

		hourTime[i] += tempTime[i].back() - '0';
		tempTime[i].pop_back();
		hourTime[i] += (tempTime[i].back() - '0') * 10;
	}	// �ð� ��ȯ string -> int

	int temp = 0;
	int highOrder = 0;
	int tempMin = 0;
	for (int i = 0; i < arrSize; i++)
	{
		temp = 0;
		for (int j = i + 1; j < arrSize; j++)
		{
			if (minTime[j] == 0)
				tempMin = 60;
			else
				tempMin = minTime[j];

			if (abs(minTime[i] - tempMin) <= k && abs(hourTime[i] - hourTime[j]) <= 1)
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
