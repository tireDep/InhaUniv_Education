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

	//cout << "���� ��\n";
	//PrintArr(heapArr);

	// heapSort
	HeapSort(heapArr, arrSize - 1);
	// heapSort
	cout << "���� ��\n";
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
		if (i % 2 == 0)	// ������ �ڽ�
		{
			childIndex = heapArr[i] > heapArr[i - 1] ? i : i - 1;	// �ڽ� ��
			parentIndex = heapArr[childIndex] > heapArr[(i - 1) / 2] ? childIndex : (i - 1) / 2;	// �ڽİ� �θ� ��
		}
		else // ���� �ڽ�
		{
			childIndex = i;	// �ڽ� ����
			parentIndex = heapArr[childIndex] > heapArr[(i - 1) / 2] ? childIndex : (i - 1) / 2;	// �ڽİ� �θ� ��
		}

		if (parentIndex != (i - 1) / 2)
		{
			temp = heapArr[parentIndex];
			heapArr[parentIndex] = heapArr[(i - 1) / 2];
			heapArr[(i - 1) / 2] = temp;

			if (parentIndex * 2 + 2 >= 0 && parentIndex * 2 + 2 <= maxRange && i % 2 == 0)	// ���� ���� �ְ�, �� ��ġ�� �������� ���(¦��)
				i = (parentIndex * 2 + 2) + 2;	// ������ �ڽ����� i�ε��� �̵�, -2 ��� +2
			else if (parentIndex * 2 + 1 >= 0 && parentIndex * 2 + 1 <= maxRange && i % 2 != 0)	// ���� ���� �ְ�, �� ��ġ�� ������ ���(Ȧ��)
				i = (parentIndex * 2 + 1) + 2;	// ���� �ڽ����� i�ε��� �̵�, -2 ��� + 2
		}

		if (i % 2 == 0)
			i -= 2;
		else
			i -= 1;
	}
	// �� �ϼ� �� ��ġ ����
	temp = heapArr[maxRange];
	heapArr[maxRange] = heapArr[0];
	heapArr[0] = temp;

	HeapSort(heapArr, maxRange - 1);
}
