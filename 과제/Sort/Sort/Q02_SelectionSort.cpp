/*
----------------------------------------------------
[ ��������(Selection Sort) ]

arr : 6 4 8 3 1 9 7
�迭�� ��ȸ�ϸ鼭 ���� ���� ���� ã��
smallIndex = 1
ã�� ���� ��ȯ��

arr : 1 4 8 3 6 9 7 
ù��° �ε��� ���� �Ϸ�
������ �κп� ���ؼ��� ���� �۾��� �ݺ���

arr : 1 3 8 4 6 9 7
arr : 1 3 4 8 6 9 7
arr : 1 3 4 6 8 9 7
arr : 1 3 4 6 7 9 8
arr : 1 3 4 6 7 8 9

�۾��� n - 1ȸ �ݺ��Ǹ� ���� ����

�ð� ���⵵ : O(n^2)
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
	cout << "�迭 ũ�� �Է� : ";
	cin >> arrSize;

	int *sortArr = new int[arrSize];
	for (int i = 0; i < arrSize; i++)
		sortArr[i] = rand() % arrSize + 1;

	cout << "���� �� : ";
	PrintArr(sortArr, arrSize);

	SelectionSort(sortArr, arrSize);

	cout << "���� �� : ";
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