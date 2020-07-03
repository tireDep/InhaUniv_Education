#include<iostream>
#include<ctime>

using namespace std;

void PrintArr(int arr[]);
void HeapSort(int heapArr[], int maxRange);

const int arrSize = 10;

int main()
{
	srand((unsigned)time(NULL));
	int heapArr[arrSize] = { 0 };

	for (int i = 0; i < arrSize; i++)
		heapArr[i] = rand() % arrSize + 1;

	//cout << "정렬 전\n";
	//PrintArr(heapArr);

	// heapSort
	HeapSort(heapArr, arrSize - 1);
	// heapSort
	cout << "정렬 후\n";
	PrintArr(heapArr);

	return 0;
}

void PrintArr(int arr[])
{
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << " ";
		//if (i == 0 || i == 2)
		//	cout << endl;
	}
	cout << endl;
}

void HeapSort(int heapArr[], int maxRange)
{
	int temp;
	int childIndex;
	int parentIndex;
	int i = maxRange;
	
	if (maxRange == 0)
		return;

	while(i > 0 && i <= maxRange)// for (int i = maxRange; i > 0; i -= 2)
	{
		if (i % 2 == 0)	// 오른쪽 자식
		{
			childIndex = heapArr[i] > heapArr[i - 1] ? i : i - 1;	// 자식 비교
			parentIndex = heapArr[childIndex] > heapArr[(i - 1) / 2] ? childIndex : (i - 1) / 2;	// 자식과 부모 비교
		}
		else // 왼쪽 자식
		{
			childIndex = i;	// 자식 대입
			parentIndex = heapArr[childIndex] > heapArr[(i - 1) / 2] ? childIndex : (i - 1) / 2;	// 자식과 부모 비교
		}

		if (parentIndex != (i - 1) / 2)
		{
			temp = heapArr[parentIndex];
			heapArr[parentIndex] = heapArr[(i - 1) / 2];
			heapArr[(i - 1) / 2] = temp;

			if (parentIndex * 2 + 2 >= 0 && parentIndex * 2 + 2 <= maxRange && i % 2 == 0)	// 범위 내에 있고, 현 위치가 오른쪽인 경우(짝수)
				i = (parentIndex * 2 + 2) + 2;	// 오른쪽 자식으로 i인덱스 이동, -2 대비 +2
			else if (parentIndex * 2 + 1 >= 0 && parentIndex * 2 + 1 <= maxRange && i % 2 != 0)	// 범위 내에 있고, 현 위치가 왼쪽인 경우(홀수)
				i = (parentIndex * 2 + 1) + 2;	// 왼쪽 자식으로 i인덱스 이동, -2 대비 + 2
		}

		if (i % 2 == 0)
			i -= 2;
		else
			i -= 1;
	}
	// 힙 완성 후 위치 변경
	temp = heapArr[maxRange];
	heapArr[maxRange] = heapArr[0];
	heapArr[0] = temp;

	HeapSort(heapArr, maxRange - 1);
}
