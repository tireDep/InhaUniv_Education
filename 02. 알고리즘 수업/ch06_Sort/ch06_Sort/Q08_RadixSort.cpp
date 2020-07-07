/*
기수정렬 / Radix Sort
-> 재귀함수
*/
#include<iostream>
#include<ctime>
#include<vector>

using namespace std;

void PrintArr(int arr[]);

const int arrSize = 10;
const int maxNum = 9999;
const int thousand = 1000;

int main()
{
	int radixArr[arrSize] = { 0 };
	srand((unsigned)time(NULL));
	for (int i = 0; i < arrSize; i++)
	{
		radixArr[i] = rand() % maxNum + 1;
		if (radixArr[i] < 1000)
			radixArr[i] += 1000;
	}

	PrintArr(radixArr);

	vector<vector<int>> sortArr(arrSize, vector<int>(0));
	for (int i = 0; i < arrSize; i++)
	{
		sortArr.at(radixArr[i] / thousand).push_back(radixArr[i]);
	}

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

	return 0;
}

void PrintArr(int arr[])
{
	for (int i = 0; i < arrSize; i++)
		cout << arr[i] << " ";
	cout << endl;
}