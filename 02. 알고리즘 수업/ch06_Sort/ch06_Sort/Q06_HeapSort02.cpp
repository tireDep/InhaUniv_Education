#include<iostream>
#include<ctime>
#include"Stopwatch.h"

using namespace std;

#define SIZE 10000000
int iArr[SIZE];

void heapSort(int *arr, int size);
void heapify(int *arr, int node, int size);
void topdown(int *arr, int node, int size);
void printTree(int *arr, int node, int size);
void SWAP(int arr, int ref, int temp);

int main()
{
	// randomArr(iArr, SIZE, 1, SIZE);
	srand((unsigned)time(NULL));
	for (int i = 0; i < SIZE; i++)
		iArr[i] = rand() % SIZE + 1;
	//printArr(iArr, SIZE); cout << endl;
	// Stopwatch watch;
	STOPWATCH_C stopWatch;
	//int test[] = { 3,10,2,10,3,8,3,3,10,1 };
	stopWatch.StartTime();
	heapSort(iArr, SIZE);
	stopWatch.EndTime();;


	//printArr(iArr, SIZE);
	cout << stopWatch.GetElapsedTime() << "ms" << endl;
}

void heapSort(int * arr, int size)
{
	heapify(arr, 0, size);

	int nTemp = 0;
	for (size_t i = 0; i < size; i++)
	{
		SWAP(arr[0], arr[size - 1 - i], nTemp);
		topdown(arr, 0, size - 1 - i);
	}
}

void heapify(int * arr, int node, int size)
{
	int left = node * 2 + 1;
	int right = node * 2 + 2;
	if (left < size)
	{
		heapify(arr, left, size);
	}
	else
		return;
	if (right < size)
	{
		heapify(arr, right, size);
	}

	topdown(arr, node, size);
}

void topdown(int * arr, int node, int size)
{
	int copyNode = node;
	int left = node * 2 + 1;
	int right = node * 2 + 2;
	int temp = 0;
	while (1)
	{
		if (left >= size)
			break;

		bool isleft;
		if (right >= size)
			isleft = true;
		else
			isleft = (arr[left] > arr[right]);

		int & ref = isleft ? arr[left] : arr[right];

		if (arr[copyNode] < ref)
		{
			SWAP(arr[copyNode], ref, temp);

			if (isleft)
				copyNode = left;
			else
				copyNode = right;

			left = copyNode * 2 + 1;
			right = copyNode * 2 + 2;
		}
		else
			break;
	}
}


void printTree(int *arr, int node, int size)
{
	static int count = 0;

	int i = 0;
	while (i != pow(2, count) && node + i < size)
	{
		for (int j = 0; j < size / (count + 1) - 1; j++)
			cout << " ";
		cout << arr[node + i];
		if (i % 2 == 0)
			for (int j = 0; j < size / (count + 1) - 1; j++)
				cout << " ";
		i++;
	}
	cout << endl << endl;
	count++;
	int left = node * 2 + 1;
	if (left < size)
		printTree(arr, left, size);
	else
		count = 0;
}

void SWAP(int arr, int ref, int temp)
{
	temp = arr;
	arr = ref;
	ref = temp;
}