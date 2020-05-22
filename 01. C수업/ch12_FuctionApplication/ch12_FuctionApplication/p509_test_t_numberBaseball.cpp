// Q. 숫자 야구게임

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
		printf("숫자를 입력하시오(3자리) : ");
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
		- check 2개(스트라이크, 볼)
		- for() 두개 사용?

		+) 같은 숫자 입력시 파울로 처리
		*/

		printf("%d %d %d\n", inputArr[0], inputArr[1], inputArr[2]);
	}
	printf("정답");

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
		}	// 0 제거
		*/

		for (int j = 0; j < i; j++)
		{
			if (temp[j] == temp[i])
			{
				i--;
				break;
			}
		}	// 중복 제거
	}

	return;
}	// void SetNumber()