// Q. ���� �߱�����
#include"BasicHeader.h"
#include"FucHeader.h"

int main()
{
	int inputNum;
	int answerArr[3] = { 0 };
	int inputArr[3] = { 0 };
	int arrSize = sizeof(inputArr) / sizeof(int);

	int ball, strike;	// �������� ����
	int checkCnt, paul;	// �Ŀ���� ����

	while (1)
	{
		SetNumber(answerArr);
		// printf("%d %d %d\n", answerArr[0], answerArr[1], answerArr[2]);
		SetPaul(&paul);

		while (1)
		{
			SetVal(&ball, &strike, &checkCnt);

			InputNumber(&inputNum, &checkCnt, &paul);
			if (IsPaul(inputArr,arrSize,&paul,checkCnt,"\n������ ������ ���� �ʽ��ϴ�.\n"))
				break;
			else if (checkCnt != 3)
				continue;

			InputNumberArr(inputArr, inputNum);
			if (IsPaul(inputArr, arrSize, &paul, CheckTwice(inputArr, arrSize),"\n�ߺ��� ������ �Է��Դϴ�.\n"))
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
