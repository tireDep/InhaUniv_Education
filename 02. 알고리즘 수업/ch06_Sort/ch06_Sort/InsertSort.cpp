#include<iostream>
#include<ctime>
#include<cstdlib>
#include"Stopwatch.h"

using namespace std;

void PrintArr(int insertArr[]);

const int arrSize = 100000;

int main()
{
	srand((unsigned)time(NULL));
	
	STOPWATCH_C stopWatch;
	int insertArr[arrSize] = { 0 };
	for (int i = 0; i < arrSize; i++)
	{
		insertArr[i] = rand() % arrSize + 1;
	}

	int temp;
	stopWatch.StartTime();
	for (int i = 0; i < arrSize - 1; i++)
	{
		for (int j = i + 1; j > 0; j--)
		{
			if (insertArr[j - 1] > insertArr[j])
			{
				temp = insertArr[j - 1];
				insertArr[j - 1] = insertArr[j];
				insertArr[j] = temp;
				// Swap()으로 둘 경우 시간이 너무 오래 걸림
			}
			else
				break;
		}
	}
	stopWatch.EndTime();

	cout << stopWatch.GetElapsedTime() << endl;

	return 0;
}

void PrintArr(int insertArr[])
{
	for (int i = 0; i < arrSize; i++)
	{
		cout << insertArr[i] << " ";
	}
	cout << endl;
}