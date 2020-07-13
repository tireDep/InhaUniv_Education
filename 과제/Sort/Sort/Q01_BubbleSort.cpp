/*
----------------------------------------------------
[ ���� ����(Bubble Sort) ]

arr : 6 4 3 7 1 9 8
0��°, 1��° �� �� �� 0��°�� �� Ŭ ��� Swap

arr : 4 6 3 7 1 9 8
1��°, 2��° �� �� �� 1��°�� �� Ŭ ��� Swap

arr : 4 3 6 7 1 9 8
n - 1, n ��° �� �� �� n -1 ��°�� �� Ŭ ��� Swap

arr : 4 3 6 1 7 9 8
arr : 4 3 6 1 7 9 8
arr : 4 3 6 1 7 8 9
�� ������ �ε��� ���� �Ϸ�
�ٽ� �� ó�� �ε����� ���ư��� �ش� �۾��� �ݺ�

�۾��� n - 1ȸ �ݺ��Ǹ� ���� ����

�ð� ���⵵ : O(n^2)
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
	cout << "�迭 ũ�� �Է� : ";
	cin >> arrSize;

	int *sortArr = new int[arrSize];
	for (int i = 0; i < arrSize; i++)
		sortArr[i] = rand() % arrSize + 1;

	cout << "���� �� : ";
	PrintArr(sortArr, arrSize);
	
	// BubbleSort(sortArr, arrSize);
	// BubbleSort2(sortArr, arrSize);
	BubbleSort3(sortArr, arrSize);;

	cout << "���� �� : ";
	PrintArr(sortArr, arrSize);

	delete[] sortArr;
	return 0;
}

void BubbleSort(int sortArr[], int arrSize)
{
	// �⺻���� ��������
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
	// ������ �˰��� : � �н����� ����� ��ȯ Ƚ���� 0�̸�, ������ �Ϸ�� ����
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
	// ������ �˰��� : ��ĵ ������ ������ ���� ����
	int k = 0;	// a[k]���� ������ ��Ҵ� ������ ��ģ ����
	int last = 0;	//  ���������� ��ȯ�� ������ ��ġ ����
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