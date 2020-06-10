// Q. �Է°����� �̸� �������� �ʰ� ���ڸ� �Է� ���������� �޸𸮸� �÷����鼭 ��ü ���� ���� ���
// (������ ���α׷� ����) 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include <crtdbg.h>	// �޸� ����

// #define _CRTDBG_MAP_ALLOC // �޸� ����

void CheckFree(int *arr);
void PrintArr(int cnt, int *resultArr, int result);

int main()
{
	// _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);	// �޸� ����
	// _CRTDBG_ALLOC_MEM_DF : �Ҵ� üũ
	// _CRTDBG_LEAK_CHECK_DF : ���� üũ
	

	_crtBreakAlloc = 72;	// �޸� ����
	// ������ ������ �Ͼ ��ġ�� �ߴ��� ��������

	int cnt = 0;
	int result = 0;
	int *tempArr = NULL;
	int *resultArr = (int *)malloc(sizeof(int));

	int inputNum;
	int cntCheck = 0;	// �迭ũ�� ���

	while (1)
	{
		cntCheck = cnt + 1;

		printf("���� �Է� : ");
		scanf_s("%d", &inputNum);

		if (inputNum <= -1)
		{
			break;
		}
		else
		{
			/*
			-------------------------------------------------
			����
			temp :	 x  x  o  o | xo oo	oo	oo | ...
			result : x  x  x  o | o	 o	xx	oo | ...

			+) memcpy()�� �迭 ������ ���, ũ��� sizeof(�迭)*�迭ũ��
			-------------------------------------------------
			*/

			tempArr = (int *)malloc(sizeof(int) * cntCheck);

			memcpy(tempArr, resultArr, sizeof(resultArr) * cntCheck);	// tempArr�� �������� ����
			*(tempArr + cnt) = inputNum;	// tempArr�� �Է°� ����

			CheckFree(resultArr);
			resultArr = (int *)malloc(sizeof(int) * cntCheck);	// resultArr ���Ҵ�

			memcpy(resultArr, tempArr, sizeof(tempArr) * cntCheck);	// resultArr�� �� ����

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
	// �޸� ����
	// ���� ��ġ �����̷�Ʈ

	// _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	// _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	// _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	// _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	// _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	// _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	// �޸� ����
	// �ܼ� �����̷�Ʈ

	_CrtDumpMemoryLeaks();	// �޸� ����
	// ������ �޸� ������ �Ͼ �κ��� Ȯ���� ��
	// {} ���� ���ڰ� �޸� ������ �Ͼ �κ�

	return 0;
}

/*
-------------------------------------------------------------------
�޸� ������ �����ϱ�!
- �޸𸮸� �����ϴ� ������ �޸𸮰� �������� ���� ���� ����(������)
==> �޸𸮰� �Ҵ�Ǿ��ִ��� Ȯ�� �� ����
if(�����Ҵ�޸𸮺��� != NULL)
	free()
else
	// ������ ���� �ʾҰų�
	// �߰��� ���� �Ǿ��ų�
-------------------------------------------------------------------
*/

void PrintArr(int cnt, int *resultArr, int result)
{
	printf("\n�Է¹��� ���� [ ");
	for (int i = 0; i < cnt; i++)
	{
		printf("%d ", resultArr[i]);
	}
	printf("] �̰� ���� [ %d ] �̴�.\n", result);

	return;
}	// void PrintArr()

void CheckFree(int *arr)
{
	if (arr != NULL)
	{
		free(arr);
	}
}