#include<stdio.h>

#include<stdarg.h>

void PrintData(int nParam)
{
	printf("PrintData() : %d\n", nParam);
}

void PrintString(const char* pszParam)
{
	printf("PrintString() : %s\n", pszParam);
}

int GetMax(int nCount, ...)	// 가변인자
{
	int nMax = -9999;
	int nParam = 0;
	int i = 0;

	va_list pList = NULL; // 가변인자 리스트
	
	va_start(pList, nCount);	// 가변인자에 대한 정보를 얻어옴

	for (int i = 0; i < nCount; i++)
	{
		nParam = va_arg(pList, int);
		if (nParam > nMax)
			nMax = nParam;
	}

	va_end(pList);	// 끝났다고 알려줌

	return nMax;
}