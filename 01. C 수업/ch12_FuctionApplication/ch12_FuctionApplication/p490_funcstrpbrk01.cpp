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
	// ã�� ���ڵ��� �Է� ����

	while ((pszStart = strpbrk(pszStart, szSet)) != NULL)	// ��� ���ڿ��� ��ġ�ϴ� ���ڰ� �ִ��� �˻�
	{
		printf("[%p] Index : %d %c\n", pszStart, pszStart - szBuffer, *pszStart);

		pszStart++;
		// ��ġ�ϴ� �ϳ��� ã�����Ƿ� �������� �̵� �� ��� Ž��
	}

	return 0;
}