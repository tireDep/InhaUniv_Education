#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

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
	for (int i = 0; i < inputCnt; i++)
		gatItem[i] = -1;

	// °¡Ã­ È®·ü ¹× °è»ê
	for (int i = 0; i < arrSize; i++)
	{
		gatchaRate[i] = basicRate[i] * inputCnt / 100;
	}
	
	double gatNum;
	int i = 0;
	int accumulateRate;
	while (inputCnt > 0)
	{
		// °¡Ã­ »Ì±â
		gatNum = rand() % 100;
		// gatNum = gatNum * (inputCnt / 100);

		i = 0;
		while (gatItem[i] != -1)
		{
			i++;
			if (gatNum == gatItem[i])
			{
				gatNum = rand() % 100;
				i = 0;
			}
		}
		gatItem[i] = gatNum;
		inputCnt--;
		gatNum = gatNum * inputCnt / 100;
		
		// for(int i=0;i<100;i++)
		// 	cout << gatItem[i] << " ";

		// cout << endl << gatNum << endl;

		accumulateRate = 0;
		for (int i = 0; i < arrSize; i++)
		{
			accumulateRate += gatchaRate[i];

			if (accumulateRate >= gatNum)
			{
				itemList[i]++;
				break;
			}
		}
		cout << inputCnt << endl;
	}

	for (int i = 0; i < arrSize; i++)
		cout << itemList[i] << " ";

	delete[]gatItem;

	return 0;
}