#include<iostream>
#include<ctime>
#include"Stopwatch.h"

using namespace std;

void PrintArr(int arr[]);

const int arrSize = 100000;

int main()
{
	srand((unsigned)time(NULL));
	STOPWATCH_C stopWatch;
	int *shellSort = new int[arrSize];

	for (int i = 0; i < arrSize; i++)
		shellSort[i] = rand() % arrSize + 1;
	
	//cout << "\n정렬 전\n";
	//PrintArr(shellSort);

	/*for (int gap = arrSize / 2; gap > 0; gap /= 2)
	{
		if (gap % 2 == 0)
			gap++;

		for (int i = gap; i < arrSize; i++)
		{
			int element = shellSort[i], j = i;
			cout << "gap : " << gap << endl;
			while (j >= gap && shellSort[j - gap] > element)
			{
				shellSort[j] = shellSort[j - gap];
				j -= gap;
				cout << "<<<";
				PrintArr(shellSort);
			}
			shellSort[j] = element;
		}
		
		// PrintArr(shellSort);
	}*/


	int temp;
	int j;
	stopWatch.StartTime();
	for (int gap = arrSize / 2; gap > 0; gap /= 2)
	{
		if (gap % 2 == 0)
			gap++;

		for (int i = gap; i < arrSize; i++)
		{
			j = i;
			while (j >= gap && shellSort[j - gap] > shellSort[j])
			{
				temp = shellSort[j - gap];
				shellSort[j - gap] = shellSort[j];
				shellSort[j] = temp;

				j -= gap;
			}	// while
		}	// for_i
	}	// for_gap
	stopWatch.EndTime();

	//cout << "\n정렬 후\n";
	//PrintArr(shellSort);

	cout << "정렬 시간 : " << stopWatch.GetElapsedTime() << endl;
}

void PrintArr(int arr[])
{
	for (int i = 0; i < arrSize; i++)
		cout << arr[i] << " ";
	cout << endl;
}