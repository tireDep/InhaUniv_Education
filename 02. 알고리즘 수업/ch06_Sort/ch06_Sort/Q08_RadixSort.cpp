/*
기수정렬 / Radix Sort
-> 재귀함수
*/
#include<iostream>
#include<ctime>
#include<vector>
#include<queue>

using namespace std;

void PrintArr(int arr[]);

const int arrSize = 10;
const int maxNum = 9998;
const int maxPos = 1000;

int main()
{
	int radixArr[arrSize] = { 0 };
	srand((unsigned)time(NULL));
	for (int i = 0; i < arrSize; i++)
	{
		radixArr[i] = rand() % maxNum + 1;
		//if (radixArr[i] < 1000)
		//	radixArr[i] += 1000;
	}

	PrintArr(radixArr);

/*	vector<vector<int>> sortArr(arrSize, vector<int>(0));
	for (int i = 0; i < arrSize; i++)
	{
		sortArr.at(radixArr[i] / 1000).push_back(radixArr[i]);
	}

	for (int i = 0; i < arrSize; i++)
	{
		sortArr.at(i).back() / 10 % 10;
	}

	// / 1000 : 1000 자리
	// / 100 % 10 : 100 자리
	// / 10 % 10	: 10 자리
	// % 10 : 1 자리

	// PrintVec();
	// vector<int>::iterator iter;
	// for (int i = 0; i < arrSize; i++)
	// {
	// 	cout << i << " : ";
	// 	for (iter = sortArr[i].begin(); iter != sortArr[i].end(); iter++)
	// 	{
	// 		cout << *iter << " ";
	// 	}
	// 	cout << endl;
	// }
	// PrintVec();

	vector<int>::iterator iter;
	for (int i = 0; i < arrSize; i++)
	{
		cout << i << " : ";
		for (iter = sortArr[i].begin(); iter != sortArr[i].end(); iter++)
		{
			cout << *iter << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < arrSize; i++)
	{
		for (iter = sortArr[i].begin(); iter != sortArr[i].end(); iter++)
		{
			cout << *iter%thousand/100 << " ";
		}
		cout << endl;
	}
	*/

	queue<int> sortArr[arrSize];
	int pos = 10;
	int min = 1;
	while (min <= maxPos)
	{
		for (int i = 0; i < arrSize; i++)
			sortArr[(radixArr[i] % pos) / min].push(radixArr[i]);

		//cout << "---";
		//for (int i = 0; i < arrSize;)
		//{
		//	if (sortArr[i].size())
		//	{
		//		cout << sortArr[i].front() << " ";
		//		sortArr[i].pop();
		//	}
		//	else
		//		i++;
		//}

		for (int i = 0, j = 0; i < arrSize;)
		{
			if (sortArr[i].size())
			{
				radixArr[j++] = sortArr[i].front();
				sortArr[i].pop();
			}
			else
				i++;
		}
		min *= 10;
		pos *= 10;
		cout << ">>> ";
		PrintArr(radixArr);
	}

	PrintArr(radixArr);

	return 0;
}

void PrintArr(int arr[])
{
	for (int i = 0; i < arrSize; i++)
		cout << arr[i] << " ";
	cout << endl;
}