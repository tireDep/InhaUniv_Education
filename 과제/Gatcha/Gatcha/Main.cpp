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

	cout << "가챠 횟수 입력 : ";
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
	// TODO : 출력구문 정리
	for (int i = 0; i < arrSize; i++)
	{
		switch (i)
		{
		case 0:
			cout << "5성 : " << itemList[i] << "개" << endl;
			break;
		case 1:
			cout << "4성 A : " << itemList[i] << "개" << endl;
			break;
		case 2:
			cout << "4성 B : "<< itemList[i] << "개" << endl;
			break;
		case 3:
			cout << "3성 A : " << itemList[i] << "개" << endl;
			break;
		case 4:
			cout << "3성 B : " << itemList[i] << "개" << endl;
			break;
		case 5:
			cout << "3성 C : " << itemList[i] << "개" << endl;
			break;
		case 6:
			cout << "2성 A : " << itemList[i] << "개" << endl;
			break;
		case 7:
			cout << "2성 B : " << itemList[i] << "개" << endl;
			break;
		case 8:
			cout << "2성 C : " << itemList[i] << "개" << endl;
			break;
		case 9:
			cout << "2성 D : " << itemList[i] << "개" << endl;
			break;
		case 10:
			cout << "1성 : " << itemList[i] << "개" << endl;
			break;
			break;
		default:
			break;
		}
	}
}