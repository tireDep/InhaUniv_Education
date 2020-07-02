#include<iostream>
#include<ctime>

using namespace std;

void MergeSort(int left, int right, int mergeArr[]);
void Sorting(int left, int right, int mergeArr[]);

void PrintArr(int arr[]);

const int arrSize = 8;
int tempArr[arrSize] = { 0 };

int main()
{
	srand((unsigned)time(NULL));
	int mergeArr[arrSize] = {};

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

void MergeSort(int left, int right, int mergeArr[])
{
	if (left == right) return;
	int mid;
	mid = (left + right) / 2;
	MergeSort(left, mid, mergeArr);
	MergeSort(mid + 1, right, mergeArr);
	Sorting(left, right, mergeArr);

	// if (mergeArr[start] >= mergeArr[mid])
	// {
	// 	temp = mergeArr[start];
	// 	mergeArr[start] = mergeArr[mid];
	// 	mergeArr[mid] = temp;
	// 	start++;
	// }
	// else if(mergeArr[start] < mergeArr[mid])
	// 	mid++;
	// cout << "<<<";
	// PrintArr(mergeArr);
	// cout << "start : " << start << ", mid : " << mid << ", fin : " << fin << endl;
}

void Sorting(int left, int right, int mergeArr[])
{
	int L, R, k, a;
	int mid = (left + right) / 2;
	L = left;
	R = mid + 1;
	k = left;

	while (L <= mid && R <= right)
		tempArr[k++] = mergeArr[L] <= mergeArr[R] ? mergeArr[L++] : mergeArr[R++];

	if (L>mid)
		for (a = R; a <= right; a++)
			tempArr[k++] = mergeArr[a];
	else
		for (a = L; a <= mid; a++)
			tempArr[k++] = mergeArr[a];

	for (a = left; a <= right; a++)
		mergeArr[a] = tempArr[a];

}