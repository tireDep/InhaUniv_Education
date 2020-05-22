// 490p
#include<stdio.h>
#include<string.h>

int main()
{
	char szBuffer[128] = { 0 };
	char szSet[128] = { 0 };
	char *pszStart = szBuffer;

	printf("Input String : ");
	gets_s(szBuffer, sizeof(szBuffer));

	printf("Input Character Set : ");
	gets_s(szSet, sizeof(szSet));
	// 찾을 문자들을 입력 받음

	while ((pszStart = strpbrk(pszStart, szSet)) != NULL)	// 대상 문자열에 일치하는 문자가 있는지 검색
	{
		printf("[%p] Index : %d %c\n", pszStart, pszStart - szBuffer, *pszStart);

		pszStart++;
		// 일치하는 하나를 찾았으므로 다음으로 이동 후 계속 탐색
	}

	return 0;
}