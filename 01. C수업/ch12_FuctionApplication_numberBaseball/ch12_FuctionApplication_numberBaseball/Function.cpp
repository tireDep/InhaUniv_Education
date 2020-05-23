#include "BasicHeader.h"
#include "FucHeader.h"

void SetPaul(int *paul)
{
	*paul = 0;
} // void SetPaul()

void SetVal(int *ball, int *strike, int *checkCnt)
{
	*ball = 0;
	*strike = 0;
	*checkCnt = 0;
}	// void SetVal()

void SetNumber(int *ansArr)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 3; i++)
	{
		ansArr[i] = rand() % 9 + 1;
		i = CheckTwice(ansArr, i);
	}
}	// void SetNumber()

bool IsPaul(int *inputArr, int arrSize, int *paul, int isPaul, char *string)
{
	if (isPaul != 3)
	{
		printf("%s", string);
		if (CheckPaul(paul))
			return true;
		else
			return false;
	}
	return false;
}	// bool IsPaul()

bool CheckPaul(int *paul)
{
	(*paul)++;
	printf("파울입니다. 세번 파울이면 아웃입니다.\n\n");
	PrintScore("Paul", *paul);
	puts("");
	if (*paul == 3)
		return true;
	else
		return false;
}	// bool CheckPaul()

int CheckTwice(int *arr, int maxI)
{
	for (int j = 0; j < maxI; j++)
	{
		if (arr[j] == arr[maxI - j + 1])
		{
			maxI--;
			break;
		}
	}

	return maxI;
}	// int CheckTwice()

void InputNumber(int *inputNum, int *checkCnt, int *paul)
{
	int _inputNum, tempNum;
	printf("숫자를 입력하시오(3자리, 1 ~ 9) : ");
	scanf_s("%d", &_inputNum);

	*inputNum = _inputNum;
	tempNum = _inputNum;
	while (tempNum > 0)
	{
		if (tempNum % 10 <= 0)
			break;
		tempNum /= 10;
		(*checkCnt)++;
	}	// Check Input Cnt & Check Input Zero
}	// void InputNumber()

void InputNumberArr(int *inputArr, int inputNum)
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

bool CheckScore(int *answerArr, int *strike, int *ball)
{
	if (*strike == 0 && *ball == 0)
	{
		PrintScore("No Ball No Strike\n", -1);
		return false;
	}
	else if (*strike == 3)
	{
		printf("정답!\n정답은 %d, %d, %d 입니다.\n", answerArr[0], answerArr[1], answerArr[2]);
		return true;
	}
	else
	{
		PrintScore("Ball", *ball);
		PrintScore("Strike", *strike);
		puts("");
		return false;
	}
}	// bool CheckScore()

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

bool CheckRestart()
{
	char inputAns = 0;

	rewind(stdin);
	printf("\n재시작(Y/N) : ");
	scanf_s("%c", &inputAns, 1);
	puts("");

	if (tolower(inputAns) == 'y')
	{
		system("cls");
		return true;
	}
	else
	{
		puts("게임을 종료합니다.");
		return false;
	}
}	// bool CheckRestart()
