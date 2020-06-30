#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

void PickGatch(int inputCnt, double gatItem[]);
void AddItemList(int inputCnt, double gatItem[], double gatchaRate[], int itemList[]);
void PrintItemList(int itemList[]);

const int arrSize = 11;

int main()
{
	srand((unsigned)time(NULL));
	double basicRate[arrSize] = { 1,3,3,5,5,5,10,10,10,10,38 };
	double gatchaRate[arrSize] = { 0 };
	int itemList[arrSize] = { 0 };
	int inputCnt;

	cout << "°¡Ã­ È½¼ö ÀÔ·Â : ";
	cin >> inputCnt;

	double *gatItem = new double[inputCnt];

	// °¡Ã­ È½¼ö¿¡ µû¸¥ °¡Ã­ È®·ü °è»ê
	for (int i = 0; i < arrSize; i++)
	{
		// gatchaRate[i] = basicRate[i] * inputCnt / 100;
	
		gatchaRate[i] = basicRate[i];
	}

	// °¡Ã­ »Ì±â ¹× Áßº¹ Ã¼Å©
	if (inputCnt <= 100)
	{
		PickGatch(inputCnt, gatItem);
		AddItemList(inputCnt, gatItem, gatchaRate, itemList);
	}
	else
	{
		int divideVal;
		int multiVal = 10;
		while (1)
		{
			if (inputCnt >= 100 * multiVal && inputCnt <= 990 * multiVal + 9)
			{
				divideVal = 1 * multiVal;
				break;
			}
			else
				multiVal *= 10;
		}

		int checkEnd = divideVal;
		while (checkEnd > 0)
		{
			checkEnd--;
			if(inputCnt > 100) inputCnt /= divideVal;

			PickGatch(inputCnt, gatItem);
			AddItemList(inputCnt, gatItem, gatchaRate, itemList);
			//PrintItemList(itemList);
			for (int i = 0; i < inputCnt; i++)
				gatItem[i] = 0;
		}
	}


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
		gatNum = rand() % 100;
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
		checkRate = gatItem[i] * inputCnt / 100;
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
	for (int i = 0; i < arrSize; i++)
		cout << itemList[i] << " ";
}