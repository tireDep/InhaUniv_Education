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

		for (int j = 0; j < i; j++)
		{
			if (i == 0)
				break;

			if (gatchaResult[j] == gatchaRate)
			{
				i--;
				isDouble = true;
				break;
			}
		}

		if (isDouble == false)
		{
			if (gatchaRate / inputNum * 100 == 0.0 )
				itemArr[0]++;
			else if (gatchaRate / inputNum * 100 >= 1.0 && gatchaRate / inputNum * 100 <= 6.0)
			{
				int selectItem = rand() % 2;
				int maxNum = 3 * inputNum / 100;
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
			else if (gatchaRate / inputNum * 100 >= 7.0 && gatchaRate / inputNum * 100 <= 21.0)
			{
				int selectItem = rand() % 3;
				int maxNum = 5 * inputNum / 100;
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
			else if (gatchaRate / inputNum * 100 >= 22.0 && gatchaRate / inputNum * 100 <= 61.0)
			{
				int selectItem = rand() % 4;
				int maxNum = 10 * inputNum / 100;
				
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

	return 0;
}