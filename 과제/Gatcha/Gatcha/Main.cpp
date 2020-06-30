#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

void PickGatch(int inputCnt, double gatItem[]);
void AddItemList(int inputCnt, double gatItem[], double gatchaRate[], int itemList[]);
void PrintItemList(int itemList[]);

const int arrSize = 11;
const int maxGatchaSize = 100;

int main()
{
	srand((unsigned)time(NULL));
	double gatchaRate[arrSize] = { 1,3,3,5,5,5,10,10,10,10,38 };
	int itemList[arrSize] = { 0 };
	int inputCnt;

	cout << "��í Ƚ�� �Է� : ";
	cin >> inputCnt;

	double *gatItem = new double[maxGatchaSize];
	while (1)
	{
		if (inputCnt < 0)
			break;

		if (inputCnt >= 0)
		{
			if (inputCnt > maxGatchaSize)
			{
				PickGatch(maxGatchaSize, gatItem);
				AddItemList(maxGatchaSize, gatItem, gatchaRate, itemList);
			}
			else
			{
				PickGatch(inputCnt, gatItem);
				AddItemList(inputCnt, gatItem, gatchaRate, itemList);
			}
			inputCnt -= maxGatchaSize;
		}	// if
	}	// while

	PrintItemList(itemList);
	delete[]gatItem;

	return 0;
}

void PickGatch(int inputCnt, double gatItem[])
{
	bool isDouble;
	double gatNum;

	for (int i = 0; i < inputCnt; i++)
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

void AddItemList(int inputCnt, double gatItem[], double gatchaRate[], int itemList[])
{
	double checkRate;
	double accumulateRate;

	for (int i = 0; i < inputCnt; i++)
	{
		accumulateRate = 0;
		checkRate = gatItem[i]; // *inputCnt / maxGatchaSize;
		for (int k = 0; k < arrSize; k++)
		{
			accumulateRate += gatchaRate[k];
			if (accumulateRate > checkRate)
			{
				itemList[k]++;
				break;
			}
		}	// for_j
	}	// for_i
}	// void AddItemList()

void PrintItemList(int itemList[])
{
	// TODO : ��±��� ����
	for (int i = 0; i < arrSize; i++)
	{
		switch (i)
		{
		case 0:
			cout << "5�� : " << itemList[i] << "��" << endl;
			break;
		case 1:
			cout << "4�� A : " << itemList[i] << "��" << endl;
			break;
		case 2:
			cout << "4�� B : "<< itemList[i] << "��" << endl;
			break;
		case 3:
			cout << "3�� A : " << itemList[i] << "��" << endl;
			break;
		case 4:
			cout << "3�� B : " << itemList[i] << "��" << endl;
			break;
		case 5:
			cout << "3�� C : " << itemList[i] << "��" << endl;
			break;
		case 6:
			cout << "2�� A : " << itemList[i] << "��" << endl;
			break;
		case 7:
			cout << "2�� B : " << itemList[i] << "��" << endl;
			break;
		case 8:
			cout << "2�� C : " << itemList[i] << "��" << endl;
			break;
		case 9:
			cout << "2�� D : " << itemList[i] << "��" << endl;
			break;
		case 10:
			cout << "1�� : " << itemList[i] << "��" << endl;
			break;
			break;
		default:
			break;
		}
	}
}