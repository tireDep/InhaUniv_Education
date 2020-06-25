#include<iostream>
#include<cstdlib>
#include<ctime>
#include"Stopwatch.h"

using namespace std;

void Swap(int sortArr[], int indexI, int indexJ);
void SelectionSort(int selectionArr[]);
void BubbleSort(int bubbleArr[]);

const int arrSize = 100000;

int main()
{
	srand((unsigned)time(NULL));

	STOPWATCH_C stopWatch;

	int bubbleArr[arrSize];
	int selectionArr[arrSize];
	int tempNum;
	bool isDouble;
	for (int i = 0; i < arrSize; i++)
	{
		isDouble = false;
		tempNum = rand() % arrSize + 1;
		//for (int j = 0; j < i; j++)
		//{
		//	if (bubbleArr[j] == tempNum)
		//		isDouble = true;
		//}
		//if (!isDouble)
		{
			bubbleArr[i] = tempNum;
			selectionArr[i] = tempNum;
		}
		//else
		//	i--;
	}	// 랜덤 값 저장

	cout << "[선택정렬]\n";
	stopWatch.StartTime();
	SelectionSort(selectionArr);
	stopWatch.EndTime();
	cout << endl << "결과 값 : " << stopWatch.GetElapsedTime() << "m/s" << endl << endl;

	cout << "[버블정렬]\n";
	stopWatch.StartTime();
	BubbleSort(bubbleArr);
	stopWatch.EndTime();
	cout << endl << "결과 값 : " << stopWatch.GetElapsedTime() << "m/s"  << endl << endl;

	return 0;
}

void Swap(int sortArr[], int indexI, int indexJ)
{
	int temp;

	temp = sortArr[indexI];
	sortArr[indexI] = sortArr[indexJ];
	sortArr[indexJ] = temp;
}

void SelectionSort(int selectionArr[])
{
	int smallIndex;
	for (int i = 0; i < arrSize - 1; i++)
	{
		smallIndex = i;
		for (int j = i + 1; j < arrSize; j++)
		{
			if (selectionArr[smallIndex] > selectionArr[j])
				smallIndex = j; // Swap(selectionArr, i, j); // 	
		}
		Swap(selectionArr, i, smallIndex);
	}
}

void BubbleSort(int bubbleArr[])
{
	for (int i = 0; i < arrSize; i++)
	{
		for (int j = 0; j < arrSize - i; j++)
		{
			if (bubbleArr[i] < bubbleArr[j])
				Swap(bubbleArr, i, j);
		}
	}

	/*int flag = 0;
	for (int i = 0; i < arrSize - 1; i++)
	{
		for (int j = 0; j < arrSize - (i + 1); j++)
		{
			if (bubbleArr[j] > bubbleArr[j + 1])
			{
				Swap(bubbleArr, j, j + 1);
				flag = 1;
			}
		}

		if (flag == 0)
		{
			cout << "정렬완료";
			return;
		}
	}*/
}