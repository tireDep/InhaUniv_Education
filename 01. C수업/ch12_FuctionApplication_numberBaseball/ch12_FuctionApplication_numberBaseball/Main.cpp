// Q. 숫자 야구게임
#include"BasicHeader.h"
#include"FucHeader.h"

int main()
{
	int inputNum;
	int answerArr[3] = { 0 };
	int inputArr[3] = { 0 };
	int arrSize = sizeof(inputArr) / sizeof(int);

	int ball, strike;	// 점수관련 변수
	int checkCnt, paul;	// 파울관련 변수

	while (1)
	{
		SetNumber(answerArr);
		// printf("%d %d %d\n", answerArr[0], answerArr[1], answerArr[2]);
		SetPaul(&paul);

		while (1)
		{
			SetVal(&ball, &strike, &checkCnt);

			InputNumber(&inputNum, &checkCnt, &paul);
			if (IsPaul(inputArr,arrSize,&paul,checkCnt,"\n숫자의 갯수가 맞지 않습니다.\n"))
				break;
			else if (checkCnt != 3)
				continue;

			InputNumberArr(inputArr, inputNum);
			if (IsPaul(inputArr, arrSize, &paul, CheckTwice(inputArr, arrSize),"\n중복된 숫자의 입력입니다.\n"))
				break;
			else if (CheckTwice(inputArr, arrSize) != 3)
				continue;

			CheckAnswer(answerArr, inputArr, arrSize, &strike, &ball);
			if (CheckScore(answerArr, &strike, &ball))
				break;
			else
				continue;

		}	// Play Game Loop

		if (CheckRestart())
			continue;
		else
			break;
		// Check Restart

	}	// Restart Loop

	return 0;
}
