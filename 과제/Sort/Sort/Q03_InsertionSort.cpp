/*
----------------------------------------------------
[ ��������(Insertion Sort) ]

arr : 6 4 1 7 3 9 8
0��° �ε����� ���ĵǾ��ٰ� ����, 1��° �ε����� ��
1��° �ε����� �� ���� ��� 0��° �ε����� ������ ����

arr : 4 6 1 7 3 9 8
1��° �ε������� ���ĵǾ��ٰ� ����, 2��° �ε����� 0 ~ 1��° �ε����� ��
�� ���� �ε����� ������ ��� �� �ε����� �տ� ����

arr : 1 4 6 7 3 9 8
arr : 1 3 4 6 7 9 8
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
void InsertionSort(int sortArr[], int arrSize);
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

	InsertionSort(sortArr, arrSize);

	cout << "���� �� : ";
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