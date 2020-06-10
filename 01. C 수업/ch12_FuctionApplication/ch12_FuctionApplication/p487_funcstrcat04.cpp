// 487p
#include<stdio.h>
#include<string.h>

char *MyStrcat(char *pszDst, char *pszSrc);

int main()
{
	char szPath[128] = { 0 };
	char *pszEnd = NULL;

	// ��� �޸𸮿� ���ڿ��� ����
	pszEnd = MyStrcat(szPath, "C:\\Program Files\\");

	// �ռ� ��ȯ�ϴ� �ּҸ� ù ��° �μ��� ȣ���� ���ڿ��� ����
	pszEnd = MyStrcat(pszEnd, "CHS\\");
	pszEnd = MyStrcat(pszEnd, "C programming");

	puts(szPath);
	
	return 0;
}

char *MyStrcat(char *pszDst, char *pszSrc)
{
	while (*pszDst != '\0')	// ��� �޸𸮿� ����� ���ڿ��� ���� ã��
	{
		++pszDst;
	}

	while (*pszSrc != '\0')	// �� �ڿ� ���ο� ���ڿ��� �̾� ����
	{
		*pszDst++ = *pszSrc++;
	}

	*++pszDst = '\0';	// �� ���� NULL ���ڷ� ������

	return --pszDst;	// �̾���� ���ڿ��� ������ ���ڰ� ����� �޸��� �ּ� ��ȯ
}