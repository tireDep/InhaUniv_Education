#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

void PickGatch(int cnt, double gatItem[]);
void AddItemList(int cnt, double gatItem[], double gatchaRate[], int itemList[]);
void PrintItemList(int itemList[]);

const int arrSize = 11;
const int maxGatchaSize = 100;

int main()
{
	srand((unsigned)time(NULL));
	double gatchaRate[arrSize] = { 1,3,3,5,5,5,10,10,10,10,38 };
	int itemList[arrSize] = { 0 };
	double gatItem[maxGatchaSize] = { 0 };
	int inputCnt;

	cout << "��í Ƚ�� �Է� : ";
	cin >> inputCnt;

	while (1)
	{
		if (inputCnt < 0)
			break;

		if (inputCnt >= 0)
		{
			if (inputCnt > maxGatchaSize)
			{	// 100 ����
				PickGatch(maxGatchaSize, gatItem);
				AddItemList(maxGatchaSize, gatItem, gatchaRate, itemList);
			}
			else
			{	// 100 �ʰ�
				PickGatch(inputCnt, gatItem);
				AddItemList(inputCnt, gatItem, gatchaRate, itemList);
			}
			inputCnt -= maxGatchaSize;
		}	// if
	}	// while

	PrintItemList(itemList);

	return 0;
}

void PickGatch(int cnt, double gatItem[])
{
	bool isDouble;
	double gatNum;

	for (int i = 0; i < cnt; i++)
	{
		gatNum = rand() % maxGatchaSize;
		isDouble = false;
		for (int j = 0; j < i; j++)
		{
			if (gatNum == gatItem[j])
			{
				i--;
				isDouble = true;
			}
		}

		if (isDouble != true)
			gatItem[i] = gatNum;
	}
}

void AddItemList(int cnt, double gatItem[], double gatchaRate[], int itemList[])
{
	double accumulateRate;

	for (int i = 0; i < cnt; i++)
	{
		accumulateRate = 0;
		for (int k = 0; k < arrSize; k++)
		{
			accumulateRate += gatchaRate[k];
			if (accumulateRate > gatItem[i])
			{
				itemList[k]++;
				break;
			}
		}	// for_j
	}	// for_i
}	// void AddItemList()

void PrintItemList(int itemList[])
{
	cout << endl;
	// TODO : ��±��� ����
	for (int i = 0; i < arrSize; i++)
	{
		switch (i)
		{
		case 0:
			if(itemList[i] != 0) cout << "5��   : " << itemList[i] << "��" << endl << endl;
			break;
		case 1:
			if (itemList[i] != 0) cout << "4�� A : " << itemList[i] << "��" << endl << endl;
			break;
		case 2:
			if (itemList[i] != 0) cout << "4�� B : "<< itemList[i] << "��" << endl << endl;
			break;
		case 3:
			if (itemList[i] != 0) cout << "3�� A : " << itemList[i] << "��" << endl << endl;
			break;
		case 4:
			if (itemList[i] != 0) cout << "3�� B : " << itemList[i] << "��" << endl << endl;
			break;
		case 5:
			if (itemList[i] != 0) cout << "3�� C : " << itemList[i] << "��" << endl << endl;
			break;
		case 6:
			if (itemList[i] != 0) cout << "2�� A : " << itemList[i] << "��" << endl << endl;
			break;
		case 7:
			if (itemList[i] != 0) cout << "2�� B : " << itemList[i] << "��" << endl << endl;
			break;
		case 8:
			if (itemList[i] != 0) cout << "2�� C : " << itemList[i] << "��" << endl << endl;
			break;
		case 9:
			if (itemList[i] != 0) cout << "2�� D : " << itemList[i] << "��" << endl << endl;
			break;
		case 10:
			if (itemList[i] != 0) cout << "1��   : " << itemList[i] << "��" << endl << endl;
			break;
		default:
			break;
		}
	}
}