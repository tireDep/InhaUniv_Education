// 399p
#include<stdio.h>

int main()
{
	char szBuffer[12] = { "TestString" };
	char *pszData = "TestString";

	printf("%d\n", szBuffer == pszData);	// �ּҺ� : 0
	printf("%d\n", "TestString" == pszData);	// ���� ���ڿ� : 1
	printf("%d\n", "DataString" == pszData);	// �ٸ� ���ڿ� : 0

	return 0;
}