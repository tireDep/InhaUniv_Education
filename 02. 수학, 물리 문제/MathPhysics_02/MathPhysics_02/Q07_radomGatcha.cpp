// Q. ������ ����� ������ ���� ��
// 5�� A�� : 1%
// 4�� B / C�� : 3%
// 3�� D / E�� : 5%
// 2�� G / H / I / H�� : 10%
// 1�� K�� : 38%
// �� ��, �� �������� ������ Ȯ���� �°� ��Ȯ�� ���� �� �ֵ��� ���α׷��� �ۼ��Ͻÿ�

// ex)
// 100�� ������ 5���� ������ �ϳ� ����
// 1000�� ������ 5���� 10�� ����

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));

	int inputNum;
	cout << "��í ���� Ƚ�� : ";
	cin >> inputNum;

	bool isDouble;
	float gatchaRate;
	int itemArr[11] = { 0 };	// A ~ K
	int *gatchaResult = new int[inputNum];
	for (int i = 0; i < inputNum; i++)
	{
		isDouble = false;
		gatchaRate = rand() % inputNum;	// 100���� : 0 ~ 99
		gatchaResult[i] = gatchaRate;

		float maxNum;
		if (gatchaRate == 0)
		{
			maxNum = 1 * inputNum / 100;
			if (gatchaResult[0] < maxNum)
			{
				i--;
				isDouble = true;
			}
			else
				gatchaResult[0]++;
		}
		else if (gatchaRate >= 1 && gatchaRate <= 6)
		{
			maxNum = 3 * inputNum / 100;
			if (gatchaResult[0] < maxNum)
			{
				i--;
				isDouble = true;
			}
			else
				gatchaResult[0]++;
		}
		else if (gatchaRate >= 7 && gatchaRate <= 21)
		{
			maxNum = 5 * inputNum / 100;
			if (gatchaResult[0] < maxNum)
			{
				i--;
				isDouble = true;
			}
			else
				gatchaResult[0]++;
		}
		else if (gatchaRate >= 22 && gatchaRate <= 61)
		{
			maxNum = 10 * inputNum / 100;
			if (gatchaResult[0] < maxNum)
			{
				i--;
				isDouble = true;
			}
			else
				gatchaResult[0]++;
		}


		if (isDouble == false)
		{
			if (gatchaRate == 0 && itemArr[0] < maxNum)
				itemArr[0]++;
			else if (gatchaRate >= 1 && gatchaRate <= 6)
			{
				int selectItem = rand() % 2;
				while (1)
				{
					if (selectItem == 0 && itemArr[1] < maxNum)
					{
						itemArr[1]++;
						break;
					}
					else if (itemArr[2] < maxNum)
					{
						itemArr[2]++;
						break;
					}
					else
					{
						selectItem = rand() % 2;
						maxNum = 3 * inputNum / 100;
					}
				}
			}
			else if (gatchaRate >= 7 && gatchaRate <= 21)
			{
				int selectItem = rand() % 3;
				while (1)
				{
					if (selectItem == 0 && itemArr[3] < maxNum)
					{
						itemArr[3]++;
						break;
					}
					else if (selectItem == 1 && itemArr[4] < maxNum)
					{
						itemArr[4]++;
						break;
					}
					else if (itemArr[5] < maxNum)
					{
						itemArr[5]++;
						break;
					}
					else
					{
						selectItem = rand() % 3;
						maxNum = 5 * inputNum / 100;
					}
				}
			}
			else if (gatchaRate >= 22 && gatchaRate <= 61)
			{
				int selectItem = rand() % 4;
				while (1)
				{
					if (selectItem == 0 && itemArr[6] < maxNum)
					{
						itemArr[6]++;
						break;
					}
					else if (selectItem == 1 && itemArr[7] < maxNum)
					{
						itemArr[7]++;
						break;
					}
					else if (selectItem == 2 && itemArr[8] < maxNum)
					{
						itemArr[8]++;
						break;
					}
					else if (itemArr[9] < maxNum)
					{
						itemArr[9]++;
						break;
					}
					else
					{
						selectItem = rand() % 4;
						maxNum = 10 * inputNum / 100;
					}
				}

			}
			else
				itemArr[10]++;
		}
	}

	for (int i = 0; i < 11; i++)
	{
		cout << i << " : " << itemArr[i] << endl;
	}

	delete[] gatchaResult;
	return 0;
}