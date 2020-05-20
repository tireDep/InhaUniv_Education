// Q. 입력개수를 미리 지정하지 않고 숫자를 입력 받을때마다 메모리를 늘려가면서 전체 수와 합을 출력
// (기존의 프로그램 수정) 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include <crtdbg.h>	// 메모리 누수

// #define _CRTDBG_MAP_ALLOC // 메모리 누수

void CheckFree(int *arr);
void PrintArr(int cnt, int *resultArr, int result);

int main()
{
	// _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);	// 메모리 누수
	// _CRTDBG_ALLOC_MEM_DF : 할당 체크
	// _CRTDBG_LEAK_CHECK_DF : 누수 체크
	

	_crtBreakAlloc = 72;	// 메모리 누수
	// 디버깅시 누수가 일어난 위치에 중단점 설정해줌

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

			CheckFree(resultArr);
			resultArr = (int *)malloc(sizeof(int) * cntCheck);	// resultArr 재할당

			memcpy(resultArr, tempArr, sizeof(tempArr) * cntCheck);	// resultArr에 값 저장

			result += inputNum;
			cnt++;
		}
		CheckFree(tempArr);
	}

	PrintArr(cnt, resultArr, result);
	CheckFree(resultArr);
	
	// _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	// _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
	// _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_DEBUG);
	// 메모리 누수
	// 덤프 위치 리다이렉트

	// _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	// _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	// _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	// _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	// _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	// _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	// 메모리 누수
	// 콘솔 리다이렉트

	_CrtDumpMemoryLeaks();	// 메모리 누수
	// 디버깅시 메모리 누수가 일어난 부분을 확인해 줌
	// {} 안의 숫자가 메모리 누수가 일어난 부분

	return 0;
}

/*
-------------------------------------------------------------------
메모리 해제에 주의하기!
- 메모리를 해지하는 순간에 메모리가 존재하지 않을 수도 있음(에러남)
==> 메모리가 할당되어있는지 확인 후 해제
if(동적할당메모리변수 != NULL)
	free()
else
	// 선언이 되지 않았거나
	// 중간에 해제 되었거나
-------------------------------------------------------------------
*/

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

void CheckFree(int *arr)
{
	if (arr != NULL)
	{
		free(arr);
	}
}