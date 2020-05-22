#include "BasicHeader.h"
#include "FucHeader.h"

void SetPaul(int *paul)
{
	*paul = 0;
} // void SetPaul()

void SetVal(int *ball, int *strike, int *checkCnt, int *checkZero)
{
	*ball = 0;
	*strike = 0;
	*checkCnt = 0;
	*checkZero = 0;
}	// void SetVal()

void SetNumber(int *ansArr)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 3; i++)
	{
		ansArr[i] = rand() % 9 + 1;
		i = CheckTwice(ansArr, i, 0);
	}

	return;
}	// void SetNumber()

bool CheckPaul(int *paul)
{
	(*paul)++;
	printf("파울입니다. 세번 파울이면 아웃입니다.\n\n");
	PrintScore("Paul", *paul);
	puts("");
	if (*paul == 3)
	{
		return true;
		// 다시 실행 할 수 있게 변경해보기
	}
	else
	{
		return false;
	}
}	// bool CheckPaul()

int CheckTwice(int *arr, int maxI, int pos)
{
	for (int j = 0; j < maxI - pos; j++)
	{
		if (arr[j] == arr[maxI - pos])
		{
			maxI--;
			break;
		}
	}

	return maxI;
}	// int CheckTwice()

void InputNumber(int *inputArr, int inputNum)
{
	int powNum = 0;
	int cnt = 0;
	for (int i = 2; i >= 0; i--)
	{
		powNum = pow(10, i);
		inputArr[cnt] = inputNum / powNum;
		inputNum = inputNum % powNum;
		cnt++;
	}
}	// void InputNumber()

void CheckAnswer(int *answerArr, int *inputArr, int arrSize, int *strike, int *ball)
{
	for (int i = 0; i < arrSize; i++)
	{
		for (int j = 0; j < arrSize; j++)
		{
			if (answerArr[i] == inputArr[j])
			{
				if (i == j)
				{
					(*strike)++;
				}
				else
				{
					(*ball)++;
				}
			}

		}// for_j
	}	// for_i
}	// void CheckAnswer()

void PrintScore(char *scoreName, int score)
{
	if (score == -1)
	{
		printf("%s\n", scoreName);
	}
	else if (score != 0)
	{
		printf("%s : %d\n", scoreName, score);
	}
}	// void PrintScore()
