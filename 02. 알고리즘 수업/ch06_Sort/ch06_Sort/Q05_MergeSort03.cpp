#include<iostream>
#include<cstdlib>
#include<ctime>
#include"Stopwatch.h"

using namespace std;

void Merge(int arr[], int tempArr[], int n);
void MergeSort(int arr[], int tempArr[], int left, int right);
const int arrSize = 100000;

int main()
{
	srand((unsigned)time(NULL));
	int mergeArr[arrSize] = { 0 };
	int tempArr[arrSize] = { 0 };

	for (int i = 0; i < arrSize; i++)
		mergeArr[i] = rand() % arrSize + 1;

	STOPWATCH_C stopWatch;
	stopWatch.StartTime();
	Merge(mergeArr, tempArr, arrSize);
	stopWatch.EndTime();
	cout << stopWatch.GetElapsedTime() << endl;

	 for (int i = 0; i < arrSize; i++)
	 	cout << mergeArr[i] << " ";
	 cout << endl;
}

void Merge(int arr[], int tempArr[], int n)
{
	MergeSort(arr, tempArr, 0, n - 1);
}

void MergeSort(int arr[], int tempArr[], int left, int right)
{
	int center = (left + right) / 2;
	int p = 0;
	int k = left;
	int i = 0, j = 0;
	if (left < right)
	{
		MergeSort(arr, tempArr, left, center);
		MergeSort(arr, tempArr, center + 1, right);
		for (i = left; i <= center; i++)
			tempArr[p++] = arr[i];

		while (i <= right && j < p)
			arr[k++] = (tempArr[j] <= arr[i]) ? tempArr[j++] : arr[i++];
		while (j < p)
			arr[k++] = tempArr[j++];
	}
}