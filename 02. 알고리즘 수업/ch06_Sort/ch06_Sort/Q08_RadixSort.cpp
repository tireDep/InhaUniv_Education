/*
---------------------------------------------------------------
[�������(Radix Sort)]
arr : 152, 352, 350, 270, 339, 750, 670, 650, 430, 110

���� ū �ڸ����� ���� �ڸ����� �ش��ϴ� ť�� ����
or ���� ���� �ڸ����� ���� �ڸ����� ������� �ش��ϴ� ť�� ����
-> ���� �ڸ����� ������
0 : 350, 270, 750, 670, 650, 430, 110
1 : 
2 : 152, 352, 
3 :
4 : 
5 :
6 : 
7 : 
8 : 
9 : 339

���� �ڸ����� �ش��ϴ� ť�� ������� ����
-> ���� �ڸ�
0 : 
1 : 110
2 : 
3 : 430, 339
4 : 
5 : 350, 750, 650, 152, 352
6 : 
7 : 270, 670,
8 : 
9 : 

���� �ڸ����� �ش��ϴ� ť�� ������� ����
-> ���� �ڸ�
0 :
1 : 110, 152
2 : 270
3 : 339, 350, 352
4 : 430
5 : 
6 : 650, 670
7 : 750
8 :
9 :

���ĿϷ�
---------------------------------------------------------------
*/

#include<iostream>
#include<ctime>
#include<queue>

using namespace std;

void PrintArr(int arr[]);

const int arrSize = 10;

int main()
{
	int radixArr[arrSize] = { 0 };
	srand((unsigned)time(NULL));
	for (int i = 0; i < arrSize; i++)
	{
		radixArr[i] = rand() % arrSize + 1;
	}

	PrintArr(radixArr);

	queue<int> sortArr[arrSize];
	int pos = 10;
	int min = 1;
	while (min <= arrSize)
	{
		for (int i = 0; i < arrSize; i++)
			sortArr[(radixArr[i] % pos) / min].push(radixArr[i]);

		for (int i = 0, j = 0; i < arrSize;)
		{
			if (sortArr[i].size())
			{
				radixArr[j++] = sortArr[i].front();
				sortArr[i].pop();
			}
			else
				i++;
		}
		min *= 10;
		pos *= 10;
		cout << ">>> ";
		PrintArr(radixArr);
	}

	PrintArr(radixArr);

	return 0;
}

void PrintArr(int arr[])
{
	for (int i = 0; i < arrSize; i++)
		cout << arr[i] << " ";
	cout << endl;
}