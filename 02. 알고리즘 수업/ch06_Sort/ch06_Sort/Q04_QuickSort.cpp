#include<iostream>
#include<ctime>

using namespace std;

void PrintArr(int arr[]);
void QuickSort(int lv, int rv, int quickSort[]);

const int arrSize = 5;

int main()
{
	srand((unsigned)time(NULL));

	int quickArr[arrSize] = { 1,3,3,2,3 };

	//for (int i = 0; i < arrSize; i++)
	//	quickArr[i] = rand() % arrSize + 1;

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
	int pivot = (lv + rv) / 2;
	cout << "pivot : " << quickArr[pivot] << endl;
	while (lv <= rv)
	{
		cout << quickArr[lv] << "/" << lv << ", " << quickArr[rv] << "/" << rv << endl;
		if (quickArr[pivot] < quickArr[rv] && pivot <= rv)
			rv--;
		if (quickArr[pivot] > quickArr[lv] && pivot >= lv)
			lv++;

		if (quickArr[lv] >= quickArr[rv] && (quickArr[lv] >= quickArr[pivot] && quickArr[rv] <= quickArr[pivot]))
		{
			temp = quickArr[lv];
			quickArr[lv] = quickArr[rv];
			quickArr[rv] = temp;
			rv--;
			lv++;
			//pivot = lv; 
		}
		cout << "<<<";
		PrintArr(quickArr);
	}

	cout << quickArr[lv] << "/" << lv << ", " << quickArr[rv] << "/" << rv << endl;
	cout << "pivot : " << quickArr[pivot] << "/" << pivot << endl;
	PrintArr(quickArr);
	if (lv > rv)
	{
		temp = quickArr[rv];
		quickArr[rv] = quickArr[pivot];
		quickArr[pivot] = temp;
	}
		
}