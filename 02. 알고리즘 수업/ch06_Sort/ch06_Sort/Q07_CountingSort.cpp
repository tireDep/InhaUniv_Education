/*
--------------------------------------------------------
[��� ����(Counting Sort)]
arr : 5, 7, 0, 2, 4, 10, 3, 1, 3

highNum = 10 �̹Ƿ�, highNum ũ�� ��ŭ�� �迭 ����
������ ���� ������ �迭�� ����

0 1 2 3 4 5 6 7 8 9 10
1 1 1 2 1 1 0 1 0 0  1

������ 9�� �̹Ƿ�, 9 ũ�� ��ŭ�� �迭 ����
������� �迭�� ������ŭ ������

0 1 2 3 4 5 6 7 8 
0 1 2 3 3 4 5 7 10

- ������ �ϳ� �޸𸮰� ���� ����
- ������ ��쿡�� �����
--------------------------------------------------------
*/

#include<iostream>
#include<ctime>
#include"Stopwatch.h"

using namespace std;

void PrintArr(int arr[], int size);
void Reset(int arr[], int size);

const int arrSize = 5;

int main()
{
	int countArr[arrSize] = { 0 };
	srand((unsigned)time(NULL));
	for (int i = 0; i < arrSize; i++)
		countArr[i] = rand() % arrSize + 1;
	
	int max = countArr[0];
	for (int i = 0; i < arrSize; i++)
	{
		if (max < countArr[i])
			max = countArr[i];
	}

	int *tempArr = new int[max + 1];
	int *sortArr = new int[arrSize];
	Reset(tempArr, max + 1);
	Reset(sortArr, arrSize);
	
	STOPWATCH_C stopWatch;
	stopWatch.StartTime();
	for (int i = 0; i < arrSize; i++)
	{
		tempArr[countArr[i]] += 1;	// countArr[i] - min
	}

	//cout << ">>>"; 
	//PrintArr(tempArr, max + 1);

	for (int i = 1; i < max + 1; i++) // max - min + 1
	{
		tempArr[i] += tempArr[i - 1];
	}
	//cout << ">>>";
	//PrintArr(tempArr, max + 1);

	for (int i = arrSize - 1; i >= 0; i--)
	{
		sortArr[--tempArr[countArr[i]]] = countArr[i];	// countArr[i] - min
	}
	//cout << ">>>";
	//PrintArr(tempArr, max + 1);
	stopWatch.EndTime();
	PrintArr(sortArr, arrSize);

	/*
	// 1��
	int *tempArr = new int[arrSize];
	int cnt = 0;
	int maxCnt = 0;
	STOPWATCH_C stopWatch;
	stopWatch.StartTime();
	for (int i = 0; i < arrSize; i++)
	{
		cnt = 0;
		for (int j = 0; j < arrSize; j++)
		{
			if (countArr[j] == i + 1)
			{
				countArr[j] = -1;
				cnt++;
			}
		}
		tempArr[i] = cnt;
		maxCnt += cnt;
	}
	// 1��

	// 2��
	int *sortArr = new int[maxCnt];
	for (int i = 0; i < maxCnt; i++)
		sortArr[i] = 0;	// �ʱ�ȭ

	int i = 0, j = 0;
	while (1)
	{
		if (j == maxCnt)
			break;

		if (tempArr[i] != 0)
		{
			sortArr[j] = i + 1;
			tempArr[i]--;
			j++;
		}
		else
			i++;
	}
	stopWatch.EndTime();
	// 2��
	*/
	delete[] tempArr;
	delete[] sortArr;
	return 0;
}

void PrintArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void Reset(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		arr[i] = 0;
}