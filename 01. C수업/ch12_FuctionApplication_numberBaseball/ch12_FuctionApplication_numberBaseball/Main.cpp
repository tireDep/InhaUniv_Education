// Q. 숫자 야구게임
#include"BasicHeader.h"
#include"FucHeader.h"

int main()
{
	int inputNum, tempNum;
	int answerArr[3] = { 0 };
	int inputArr[3] = { 0 };
	int arrSize = sizeof(inputArr) / sizeof(int);

	int ball, strike;	// 점수관련 변수
	int checkCnt, checkZero, paul;	// 파울관련 변수

	char inputAns = 0;
	do
	{
		SetNumber(answerArr);
		// printf("%d %d %d\n", answerArr[0], answerArr[1], answerArr[2]);
		SetPaul(&paul);

		while (1)
		{
			SetVal(&ball, &strike, &checkCnt, &checkZero);
			printf("숫자를 입력하시오(3자리, 1 ~ 9) : ");
			scanf_s("%d", &inputNum);
			tempNum = inputNum;
			while (tempNum > 0)
			{
				if (tempNum % 10 <= 0)
					break;
				tempNum /= 10;
				checkCnt++;
			}

			if (checkCnt != 3)
			{
				printf("\n숫자의 갯수가 맞지 않습니다.\n");
				if (CheckPaul(&paul))
					break;
				else
					continue;

			} // 파울 체크

			InputNumber(inputArr, inputNum);

			if (CheckTwice(inputArr, arrSize, 1) != 3)
			{
				printf("\n중복된 숫자의 입력입니다.\n");
				if (CheckPaul(&paul))
					break;
				else
					continue;
			} // 파울 체크

			CheckAnswer(answerArr, inputArr, arrSize, &strike, &ball);

			// 점수 체크
			if (strike == 0 && ball == 0)
			{
				PrintScore("No Ball No Strike\n", -1);
				continue;
			}
			else if (strike == 3)
			{
				printf("정답!\n정답은 %d, %d, %d 입니다.\n", answerArr[0], answerArr[1], answerArr[2]);
				break;
			}
			else
			{
				PrintScore("Ball", ball);
				PrintScore("Strike", strike);
			}
			puts("");

		}

		// -----------------------------------------------------------

		rewind(stdin);
		printf("\n재시작(Y/N) : ");
		scanf_s("%c", &inputAns, 1);
		puts("");

		if (tolower(inputAns) == 'y')
		{
			system("cls");
			continue;
		}
		else
		{
			puts("게임을 종료합니다.");
			break;
		}

	} while (1);

	return 0;
}