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

	cout << "가챠 횟수 입력 : ";
	cin >> inputCnt;

	while (1)
	{
		if (inputCnt < 0)
			break;

		if (inputCnt >= 0)
		{
			if (inputCnt > maxGatchaSize)
			{	// 100 이하
				PickGatch(maxGatchaSize, gatItem);
				AddItemList(maxGatchaSize, gatItem, gatchaRate, itemList);
			}
			else
			{	// 100 초과
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
	// TODO : 출력구문 정리
	for (int i = 0; i < arrSize; i++)
	{
		switch (i)
		{
		case 0:
			if(itemList[i] != 0) cout << "5성   : " << itemList[i] << "개" << endl << endl;
			break;
		case 1:
			if (itemList[i] != 0) cout << "4성 A : " << itemList[i] << "개" << endl << endl;
			break;
		case 2:
			if (itemList[i] != 0) cout << "4성 B : "<< itemList[i] << "개" << endl << endl;
			break;
		case 3:
			if (itemList[i] != 0) cout << "3성 A : " << itemList[i] << "개" << endl << endl;
			break;
		case 4:
			if (itemList[i] != 0) cout << "3성 B : " << itemList[i] << "개" << endl << endl;
			break;
		case 5:
			if (itemList[i] != 0) cout << "3성 C : " << itemList[i] << "개" << endl << endl;
			break;
		case 6:
			if (itemList[i] != 0) cout << "2성 A : " << itemList[i] << "개" << endl << endl;
			break;
		case 7:
			if (itemList[i] != 0) cout << "2성 B : " << itemList[i] << "개" << endl << endl;
			break;
		case 8:
			if (itemList[i] != 0) cout << "2성 C : " << itemList[i] << "개" << endl << endl;
			break;
		case 9:
			if (itemList[i] != 0) cout << "2성 D : " << itemList[i] << "개" << endl << endl;
			break;
		case 10:
			if (itemList[i] != 0) cout << "1성   : " << itemList[i] << "개" << endl << endl;
			break;
		default:
			break;
		}
	}
}