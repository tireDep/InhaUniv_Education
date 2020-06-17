// 배열 역순 정렬
#include<iostream>

using namespace std;

void PrintArr(int numArr[], int maxSize);

int main()
{
	int numArr[7] = { 22,57,11,32,91,68,70 };
	const int maxSize = sizeof(numArr) / sizeof(int);
	int temp = 0;

	PrintArr(numArr, maxSize);

	for (int i = 0; i < maxSize / 2; i++)
	{
		temp = numArr[i];
		numArr[i] = numArr[(maxSize - 1) - i];
		numArr[(maxSize - 1) - i] = temp;
		cout << numArr[i] << "\t" << numArr[(maxSize - 1) - i] << endl;
	}

	cout << endl;
	PrintArr(numArr,maxSize);

	return 0;
}

void PrintArr(int numArr[], int maxSize)
{
	for (int i = 0; i < maxSize; i++)
	{
		cout << numArr[i] << " ";
	}
	cout << endl << endl;
}