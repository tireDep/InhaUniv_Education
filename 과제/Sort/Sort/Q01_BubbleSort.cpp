/*
----------------------------------------------------
[ 버블 정렬(Bubble Sort) ]

arr : 6 4 3 7 1 9 8
0번째, 1번째 값 비교 후 0번째가 더 클 경우 Swap

arr : 4 6 3 7 1 9 8
1번째, 2번째 값 비교 후 1번째가 더 클 경우 Swap

arr : 4 3 6 7 1 9 8
n - 1, n 번째 값 비교 후 n -1 번째가 더 클 경우 Swap

arr : 4 3 6 1 7 9 8
arr : 4 3 6 1 7 9 8
arr : 4 3 6 1 7 8 9
맨 마지막 인덱스 정렬 완료
다시 맨 처음 인덱스로 돌아가서 해당 작업을 반복

작업이 n - 1회 반복되면 정렬 종료

시간 복잡도 : O(n^2)
----------------------------------------------------
*/

#include<iostream>
#include<cstdlib>
#include<ctime>

#define Swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

void BubbleSort(int sortArr[], int arrSize);
void BubbleSort2(int sortArr[], int arrSize);
void BubbleSort3(int sortArr[], int arrSize);

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
	
	// BubbleSort(sortArr, arrSize);
	// BubbleSort2(sortArr, arrSize);
	BubbleSort3(sortArr, arrSize);;

	cout << "정렬 후 : ";
	PrintArr(sortArr, arrSize);

	delete[] sortArr;
	return 0;
}

void BubbleSort(int sortArr[], int arrSize)
{
	// 기본적인 버블정렬
	for (int i = 0; i < arrSize; i++)
	{
		for (int j = 0; j < arrSize - i - 1; j++)
		{
			if (sortArr[j] > sortArr[j + 1])
				Swap(int, sortArr[j], sortArr[j + 1]);
		}
	}
}

void BubbleSort2(int sortArr[], int arrSize)
{
	// 개선된 알고리즘 : 어떤 패스에서 요소의 교환 횟수가 0이면, 정렬이 완료된 상태
	int exChan;
	for (int i = 0; i < arrSize - 1; i++)
	{
		exChan = 0;
		for (int j = arrSize - 1; j > i; j--)
		{
			if (sortArr[j - 1] > sortArr[j])
			{
				Swap(int, sortArr[j - 1], sortArr[j]);
				exChan++;
			}
		}
		if (exChan == 0)
			break;
	}
}

void BubbleSort3(int sortArr[], int arrSize)
{
	// 개선된 알고리즘 : 스캔 범위를 제한한 버블 정렬
	int k = 0;	// a[k]보다 앞쪽의 요소는 정렬을 마친 상태
	int last = 0;	//  마지막으로 교환을 수행한 위치 저장
	while (k < arrSize - 1)
	{
		last = arrSize - 1;
		for (int j = arrSize - 1; j > k; j--)
		{
			if (sortArr[j - 1] > sortArr[j])
			{
				Swap(int, sortArr[j - 1], sortArr[j]);
				last = j;
			}
		}
		k = last;
	}
}

void PrintArr(int sortArr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
		cout << sortArr[i] << " ";
	cout << endl;
}