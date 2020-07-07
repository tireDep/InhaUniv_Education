#include<iostream>
#include<cstdlib>
#include<ctime>

#define Swap(type, x, y) do{ type t=x; x=y; y=t; } while(0)

using namespace std;

void Heap(int arr[], int n);
void DownHeap(int arr[], int left, int right);
// void Swap(int x, int y);

const int arrSize = 100;

int main()
{
	srand((unsigned)time(NULL));
	int heapArr[arrSize] = { 0 };

	for (int i = 0; i < arrSize; i++)
		heapArr[i] = rand() % arrSize + 1;

	Heap(heapArr, arrSize);

	for (int i = 0; i < arrSize; i++)
		cout << heapArr[i] << " ";
	cout << endl;
}

void Heap(int arr[], int n)
{
	for (int i = (n - 1) / 2; i >= 0; i--)
		DownHeap(arr, i, n - 1);
	for (int i = n - 1; i > 0; i--)
	{
		Swap(int, arr[0], arr[i]);
		DownHeap(arr, 0, i - 1);
	}
}

void DownHeap(int arr[], int left, int right)
{
	int temp = arr[left];	// 루트
	int child;
	int parent;

	int cl, cr;
	for (parent = left; parent < (right + 1) / 2; parent = child)
	{
		cl = parent * 2 + 1;	// 왼쪽 자식
		cr = cl + 1;

		child = (cr <= right&&arr[cr] > arr[cl]) ? cr : cl;	// 큰 값 선택
		if (temp >= arr[child])
			break;
		arr[parent] = arr[child];
	}
	arr[parent] = temp;
}

// void Swap(int x, int y)
// {
// 	int temp;
// 	do
// 	{
// 		temp = x;
// 		x = y;
// 		y = temp;
// 	} while (0);
// }
// 