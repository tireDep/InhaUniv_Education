// Q. 사용자에게서 두 개의 정수를 입력받아 두 정수를 포함해서 그 사이에 존재하는 정수들의 합을 계산
#include<stdio.h>

int main()
{
	int temp = 0;
	int frontNum = 0, endNum = 0;
	printf("첫 번째 수 입력 : ");
	scanf_s("%d", &frontNum);

	printf("두 번째 수 입력 : ");
	scanf_s("%d", &endNum);

	if (frontNum > endNum)	// 첫 번째수가 더 클 경우
	{
		temp = frontNum;
		frontNum = endNum;
		endNum = temp;
	}

	int result = 0;
	for (int i = frontNum; i <= endNum; i++)
	{
		result += i;
	}

	/*
	int result = 0;
	if (frontNum > endNum)	// 첫 번째수가 더 클 경우
	{
		for (int i = frontNum; i >= endNum; i--)
		{
			result += i;
		}
	}
	else
	{
		for (int i = frontNum; i <= endNum; i++)
		{
			result += i;
		}
	}
	*/
	/*
	-------------------------
	효율성 면에선 차이 x
	-------------------------
	*/

	printf("\n결과 값 : %d\n", result);
	return 0;

}