// Q. 길이가 7인 int형 배열을 선언하고, 사용자로부터 총 7개의 정수를 입력받아
// 입력된 정수 중 최댓값&최솟값, 정수의 총 합을 출력하는 프로그램 작성
#include<stdio.h>

int main()
{
	int nArray[7] = { 0 };
	int input;

	for (int i = 0; i < 7; i++)
	{
		scanf_s("%d", &input);
		nArray[i] = input;
	}

	int min = nArray[0];
	int max = nArray[0];
	int sum = 0;
	for (int i = 0; i < sizeof(nArray) / sizeof(int); i++)
	{

		/*
		if (max < nArray[i])
		{
		max = nArray[i];
		}

		if (min > nArray[i])
		{
		min = nArray[i];
		}
		*/

		max = max < nArray[i] ? nArray[i] : max;
		min = min > nArray[i] ? nArray[i] : min;
		// 삼항 연산자 -> ? 참 : 거짓

		sum += nArray[i];
	}

	printf("\nMax : %d\n", max);
	printf("Min : %d\n", min);
	printf("Sum : %d\n", sum);

	return 0;
}