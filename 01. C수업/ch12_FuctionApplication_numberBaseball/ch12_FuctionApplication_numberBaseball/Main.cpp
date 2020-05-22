// Q. ���� �߱�����
#include"BasicHeader.h"
#include"FucHeader.h"

int main()
{
	int inputNum, tempNum;
	int answerArr[3] = { 0 };
	int inputArr[3] = { 0 };
	int arrSize = sizeof(inputArr) / sizeof(int);

	int ball, strike;	// �������� ����
	int checkCnt, checkZero, paul;	// �Ŀ���� ����

	char inputAns = 0;
	do
	{
		SetNumber(answerArr);
		// printf("%d %d %d\n", answerArr[0], answerArr[1], answerArr[2]);
		SetPaul(&paul);

		while (1)
		{
			SetVal(&ball, &strike, &checkCnt, &checkZero);
			printf("���ڸ� �Է��Ͻÿ�(3�ڸ�, 1 ~ 9) : ");
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
				printf("\n������ ������ ���� �ʽ��ϴ�.\n");
				if (CheckPaul(&paul))
					break;
				else
					continue;

			} // �Ŀ� üũ

			InputNumber(inputArr, inputNum);

			if (CheckTwice(inputArr, arrSize, 1) != 3)
			{
				printf("\n�ߺ��� ������ �Է��Դϴ�.\n");
				if (CheckPaul(&paul))
					break;
				else
					continue;
			} // �Ŀ� üũ

			CheckAnswer(answerArr, inputArr, arrSize, &strike, &ball);

			// ���� üũ
			if (strike == 0 && ball == 0)
			{
				PrintScore("No Ball No Strike\n", -1);
				continue;
			}
			else if (strike == 3)
			{
				printf("����!\n������ %d, %d, %d �Դϴ�.\n", answerArr[0], answerArr[1], answerArr[2]);
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
		printf("\n�����(Y/N) : ");
		scanf_s("%c", &inputAns, 1);
		puts("");

		if (tolower(inputAns) == 'y')
		{
			system("cls");
			continue;
		}
		else
		{
			puts("������ �����մϴ�.");
			break;
		}

	} while (1);

	return 0;
}