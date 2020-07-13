/*
----------------------------------------------------
[ 선택정렬(Selection Sort) ]

arr : 6 4 8 3 1 9 7
배열을 순회하면서 가장 작은 값을 찾음
smallIndex = 1
찾은 값을 교환함

arr : 1 4 8 3 6 9 7 
첫번째 인덱스 정렬 완료
나머지 부분에 대해서도 같은 작업을 반복함

arr : 1 3 8 4 6 9 7
arr : 1 3 4 8 6 9 7
arr : 1 3 4 6 8 9 7
arr : 1 3 4 6 7 9 8
arr : 1 3 4 6 7 8 9

작업이 n - 1회 반복되면 정렬 종료

시간 복잡도 : O(n^2)
----------------------------------------------------
*/

#include<iostream>
#include<cstdlib>
#include<ctime>

#define Swap(type, x, y) do { type t = x; x = y; y = t; } while(0)
void SelectionSort(int sortArr[], int arrSize);
void PrintArr(int sortArr[], int arrSize);

using namespace std;

int main()
{
	srand((unsigned)time(NULL));

	int arrSize = 0;
	cout << "배열 크기 입력 : ";
	cin >> arrSize;

	int *sortArr = new int[arrSize];
	for (int i = 0; i < arrSize; i++)
		sortArr[i] = rand() % arrSize + 1;

	cout << "정렬 전 : ";
	PrintArr(sortArr, arrSize);

	SelectionSort(sortArr, arrSize);

	cout << "정렬 후 : ";
	PrintArr(sortArr, arrSize);

	delete[] sortArr;
	return 0;
}

void SelectionSort(int sortArr[], int arrSize)
{
	int min;
	for (int i = 0; i < arrSize - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < arrSize; j++)
		{
			if (sortArr[min] > sortArr[j])
				min = j;
		}
		Swap(int, sortArr[min], sortArr[i]);
	}
}

void PrintArr(int sortArr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
		cout << sortArr[i] << " ";
	cout << endl;
}