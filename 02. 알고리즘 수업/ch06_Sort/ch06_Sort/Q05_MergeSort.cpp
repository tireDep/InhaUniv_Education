#include<iostream>
#include<ctime>

using namespace std;

void MergeSort(int startI, int endI, int mergeArr[]);
void PrintArr(int arr[]); 

const int arrSize = 8;

int main()
{
	srand((unsigned)time(NULL));
	int mergeArr[arrSize] = { 4,2,2,3,1,5,7,8 };

	for (int i = 0; i < arrSize; i++)
		mergeArr[i] = rand() % arrSize + 1;
	
	cout << "정렬 전\n";
	PrintArr(mergeArr);

	MergeSort(0, arrSize - 1, mergeArr);

	cout << "정렬 후\n";
	PrintArr(mergeArr);

	return 0;
}

void PrintArr(int arr[])
{
	for (int i = 0; i < arrSize; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void MergeSort(int startI, int endI, int mergeArr[])
{
	int start = startI;
	int tempStart = startI;
	int fin = endI;
	int mid = (start + fin) / 2;
	bool isFrontDone = false;
	int temp = 0;

	if (start != mid)
	{
		MergeSort(start, mid, mergeArr);
		MergeSort(mid+1, fin, mergeArr);
	}
	
	while (start <= fin && mid <= fin)
	{
		cout << "\nstart : " << start << ", mid : " << mid << ", fin : " << fin << endl; 

		if (mergeArr[start] >= mergeArr[mid])
		{
			temp = mergeArr[start];
			mergeArr[start] = mergeArr[mid];
			mergeArr[mid] = temp;
			start++;
		}
		else if (mergeArr[start] < mergeArr[mid])
		{
			mid++;
		}
		cout << "<<<";
		PrintArr(mergeArr);
		cout << "start : " << start << ", mid : " << mid << ", fin : " << fin << endl;
	}
}