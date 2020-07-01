#include<iostream>
#include<ctime>

using namespace std;

void PrintArr(int arr[]);
void QuickSort(int lv, int rv, int quickSort[]);

const int arrSize = 5;

int main()
{
	srand((unsigned)time(NULL));

	int quickArr[arrSize] = { 2,1,5,3,4 };

	for (int i = 0; i < arrSize; i++)
		quickArr[i] = rand() % arrSize + 1;

	cout << "정렬 전\n";
	PrintArr(quickArr);
	QuickSort(0, arrSize - 1, quickArr);

	cout << "정렬 후\n";
	PrintArr(quickArr);
	
	return 0;
}

void PrintArr(int arr[])
{
	for (int i = 0; i < arrSize; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void QuickSort(int lv, int rv, int quickArr[])
{
	int temp;
	int left = lv;
	int right = rv;
	int index = (lv + rv) / 2;
	cout << lv << " " << rv << " " << (lv + rv) / 2<<endl;
	cout << "index : " << quickArr[index] << endl;
	int pivot =  quickArr[(lv + rv)/2];
	cout << "pivot : "<< (lv+rv) / 2 <<"/"<<pivot << endl;
	while (left <= right)
	{
		// cout << quickArr[left] << "/" << left << ", " << quickArr[right] << "/" << right << endl;
		while (pivot > quickArr[left])
			left++;
		while (pivot < quickArr[right]) 
			right--;

		if (left <= right)
		{
			if (left != right)
			{
				temp = quickArr[left];
				quickArr[left] = quickArr[right];
				quickArr[right] = temp;
			}
			right--;
			left++;
		}

		cout << "<<<";
		PrintArr(quickArr);
	}

	// cout << quickArr[left] << "/" << left << ", " << quickArr[right] << "/" << right << endl;
	// cout << "pivot : " << quickArr[pivot] << "/" << pivot << endl;
	PrintArr(quickArr);

	if (lv < right)
		QuickSort(lv, right, quickArr);
	if (left < rv)
		QuickSort(left, rv, quickArr);

}