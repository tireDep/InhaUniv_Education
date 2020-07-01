#include "Stopwatch.h"
#include <iostream>
#include <ctime>
#include<vector>
using namespace std;

void PrintArr(int shellSort[]);

const int arrSize = 100000;

int main()
{
	vector<vector<int> > test(10,vector<int>(10));
	cout << test.size() << endl;

	srand((unsigned)time(NULL));

	STOPWATCH_C stopWatch;
	int *shellSort = new int [arrSize];

	for (int i = 0; i < arrSize; i++)
		shellSort[i] = rand() % arrSize + 1;
	
	//cout << "���� ��\n";
	//PrintArr(shellSort);

	// ���а��� ����� �� ���, ���ĵ����ʴ� ��찡 ���� �� ����
	// �ذ�å �� 1 : n/3 + 1
	int temp;
	int chanPos = (arrSize / 3) + 1;
	int finVal = chanPos;

	stopWatch.StartTime();
	for (int i = 0; i < finVal; i++)
	{
		//cout << i << "i��\n";
		for (int j = 0; j + chanPos < arrSize; j++)
		{
			// PrintArr(shellSort);
			// cout << endl;
			if (shellSort[j] > shellSort[j + chanPos])
			{
				temp = shellSort[j];
				shellSort[j] = shellSort[j + chanPos];
				shellSort[j + chanPos] = temp;
				j -= 2;	// ���� �� �պκ� ���ĵ� ���� ��
				// cout << "!!!";
				// PrintArr(shellSort);
			}
		}
		chanPos--;
	}
	stopWatch.EndTime();
	
	//cout << "���� ��\n";
	//PrintArr(shellSort);

	cout << "\n�����ð� : " << stopWatch.GetElapsedTime() << "��"<< endl;
	delete[] shellSort;

	return 0;
} 

void PrintArr(int shellSort[])
{
	for (int i = 0; i < arrSize; i++)
		cout << shellSort[i] << " ";
	cout << endl;
}