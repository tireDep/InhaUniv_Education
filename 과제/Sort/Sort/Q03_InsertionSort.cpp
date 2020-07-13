/*
----------------------------------------------------
[ 삽입정렬(Insertion Sort) ]

arr : 6 4 1 7 3 9 8
0번째 인덱스가 정렬되었다고 가정, 1번째 인덱스와 비교
1번째 인덱스가 더 작을 경우 0번째 인덱스의 앞으로 삽입

arr : 4 6 1 7 3 9 8
1번째 인덱스까지 정렬되었다고 가정, 2번째 인덱스와 0 ~ 1번째 인덱스를 비교
더 작은 인덱스를 만났을 경우 그 인덱스의 앞에 삽입

arr : 1 4 6 7 3 9 8
arr : 1 3 4 6 7 9 8
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
void InsertionSort(int sortArr[], int arrSize);
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

	InsertionSort(sortArr, arrSize);

	cout << "정렬 후 : ";
	PrintArr(sortArr, arrSize);

	delete[] sortArr;
	return 0;
}

void InsertionSort(int sortArr[], int arrSize)
{
	int temp;
	int j;
	for (int i = 1; i < arrSize; i++)
	{
		temp = sortArr[i];
		for (j = i ; j > 0 && sortArr[j - 1] > temp; j--)
		{
			sortArr[j] = sortArr[j - 1];
		}
		sortArr[j] = temp;
	}
}

void PrintArr(int sortArr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
		cout << sortArr[i] << " ";
	cout << endl;
}