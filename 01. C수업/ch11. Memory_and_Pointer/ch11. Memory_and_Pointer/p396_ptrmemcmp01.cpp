// 396p
#include<stdio.h>
#include<string.h>

int main()
{
	char szBuffer[12] = { "TestString" };
	char *pszData = "TestString";

	printf("%d\n", memcmp(szBuffer, pszData, 10));	// 값이 같음 : 0
	printf("%d\n", memcmp("teststring", pszData, 10));	// 왼쪽이 큼 : 1
	printf("%d\n", memcmp("DataString", pszData, 10));	// 오른쪽이 큼 : -1

	return 0;
}

/*
--------------------------------------------------------------------------
memcmp() : 메모리 비교
-1 : 뒤의 문자열이 더 큼
0 : 두 값은 동일함
1 : 앞의 문자열이 더 큼

단, 뺄셈 연산을 수행할 때 unsigned char형으로 처리, 따라서 -1은 255로 처리
--------------------------------------------------------------------------
*/