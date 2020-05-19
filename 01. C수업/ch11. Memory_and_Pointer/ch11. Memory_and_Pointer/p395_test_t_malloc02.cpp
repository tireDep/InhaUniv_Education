// Q. 입력개수를 미리 지정하지 않고 숫자를 입력 받을때마다 메모리를 늘려가면서 전체 수와 합을 출력
// (기존의 프로그램 수정) 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void PrintArr(int cnt, int *resultArr, int result);

int main()
{
	int cnt = 0;
	int result = 0;
	int *tempArr = NULL;
	int *resultArr = (int *)malloc(sizeof(int));

	int inputNum;
	int cntCheck = 0;	// 배열크기 계산

	while (1)
	{
		cntCheck = cnt + 1;

		printf("숫자 입력 : ");
		scanf_s("%d", &inputNum);

		if (inputNum <= -1)
		{
			break;
		}
		else
		{
			/*
			-------------------------------------------------
			개념
			temp :	 x  x  o  o | xo oo	oo	oo | ...
			result : x  x  x  o | o	 o	xx	oo | ...

			+) memcpy()로 배열 복사할 경우, 크기는 sizeof(배열)*배열크기
			-------------------------------------------------
			*/

			tempArr = (int *)malloc(sizeof(int) * cntCheck);

			memcpy(tempArr, resultArr, sizeof(resultArr) * cntCheck);	// tempArr에 직전값들 저장
			*(tempArr + cnt) = inputNum;	// tempArr에 입력값 저장

			free(resultArr);	// 메모리 해제
			resultArr = (int *)malloc(sizeof(int) * cntCheck);	// resultArr 재할당

			memcpy(resultArr, tempArr, sizeof(tempArr) * cntCheck);	// resultArr에 값 저장

			result += inputNum;
			cnt++;
		}
		free(tempArr);
	}

	PrintArr(cnt, resultArr, result);
	free(resultArr);
	
	return 0;
}

void CalcArr(int cnt, int *tempArr, int *resultArr, int result)
{
	return;
}	// void CalcArr()

void PrintArr(int cnt, int *resultArr, int result)
{
	printf("\n입력받은 수는 [ ");
	for (int i = 0; i < cnt; i++)
	{
		printf("%d ", resultArr[i]);
	}
	printf("] 이고 합은 [ %d ] 이다.\n", result);

	return;
}	// void PrintArr()