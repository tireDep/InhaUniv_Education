// Q. ���� �߱�����

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

void SetNumber(int *temp);

int main()
{
	int answerArr[3] = { 0 };
	
	SetNumber(answerArr);

	printf("%d %d %d\n", answerArr[0], answerArr[1], answerArr[2]);

	int inputNum = 0;
	int inputArr[3] = { 0 };
	int check = 0;
	int powNum = 0;
	while (check<3)
	{
		printf("���ڸ� �Է��Ͻÿ�(3�ڸ�) : ");
		scanf_s("%d", &inputNum);

		int cnt = 0;
		int powNum = 0;
		for (int i = 2; i >= 0; i--)
		{
			powNum = pow(10, i);
			inputArr[cnt] = inputNum / powNum;
			inputNum = inputNum % powNum;
			cnt++;
		}
		check++;
		
		/*
		todo
		- check 2��(��Ʈ����ũ, ��)
		- for() �ΰ� ���?

		+) ���� ���� �Է½� �Ŀ�� ó��
		*/

		printf("%d %d %d\n", inputArr[0], inputArr[1], inputArr[2]);
	}
	printf("����");

	return 0;
}

void SetNumber(int *temp)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 3; i++)
	{
		temp[i] = rand() % 9 + 1;
		/*
		if (temp[i] == 0)
		{
			i--;
			continue;
		}	// 0 ����
		*/

		for (int j = 0; j < i; j++)
		{
			if (temp[j] == temp[i])
			{
				i--;
				break;
			}
		}	// �ߺ� ����
	}

	return;
}	// void SetNumber()