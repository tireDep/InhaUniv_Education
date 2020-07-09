// Q. 카페 손님이 음료를 주문한 시각이 주어질 때,
// k분 동안 주문이 최대 몇 건 들어왔는지 구하라.

// [조건]
// 음료 주문이 들어온 시각이 들어 있는 배열 order_time과
// 자연수 k가 매개변수로 주어질 때, k분 동안 주문이
// 최대 몇 건 들어왔는지 return

// 24시간 표기법
// k는 1이상 120 이하 자연 수
// k분이 시작하는 순간과 끝나는 순간에 들어온 주문 포함 카운트


#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	string orderTime[] = { "12:10", "12:20", "12:40", "12:40", "12:50", "13:00", "13:05", "13:06", "13:07", "13:08", "13:20" };
	const int arrSize = sizeof(orderTime) / sizeof(string);
	int inputTime;

	cout << "시간 입력 : ";
	cin >> inputTime;

	string *tempTime = new string[arrSize];
	for (int i = 0; i < arrSize; i++)
		tempTime[i] = orderTime[i];

	int *minTime = new int[arrSize];
	for (int i = 0; i < arrSize; i++)	// 초기화
		minTime[i] = 0;

	// 시간 변환 string -> int
	// 모두 분으로 변경해서 계산과정을 간략화함
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
		temp = 1;	// 처음 주문
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

	cout << "최대주문 : " << highOrder << endl;

	delete[] minTime;

	return 0;
}
