// 408p
#include<stdio.h>
#include<malloc.h>	// _msize()
#include<string.h>

int main()
{
	char *pszBuffer = NULL, *pszNewBuffer = NULL;

	pszBuffer = (char *)malloc(12);
	sprintf_s(pszBuffer, 12, "%s", "TestString");
	printf("[%p] %d %s\n", pszBuffer, _msize(pszBuffer), pszBuffer);

	pszNewBuffer = (char *)realloc(pszBuffer, 32);
	if (pszNewBuffer == NULL)
	{
		free(pszBuffer);
	}

	sprintf_s(pszNewBuffer, 32, "%s", "TestStringData");
	printf("[%p] %d %s\n", pszNewBuffer, _msize(pszNewBuffer), pszNewBuffer);
	free(pszNewBuffer);

	return 0;
}
/*
----------------------------------------------------------------------------------------------------------------
void realloc() : �̹� �Ҵ�� �޸𸮸� ���Ҵ��ϴ� �Լ�
- ����
-> void *memblock : ������ ���� �Ҵ�� �޸� �ּ�, ���� �� �ּҰ� NULL�̸� malloc()�Լ��� �����ϰ� ����
-> size_t size : �ٽ� �Ҵ���� �޸��� ����Ʈ ���� ũ��

int sprintf() : ���ڿ��� Ư�� �ּ��� �޸𸮿� ����ϴ� �Լ�
- ����
-> char *buffer : ��� ���ڿ��� ����� �޸� �ּ�
-> const char *format : ���� ���ڿ��� ����� �޸� �ּ�
-> [, argument] : ���� ���ڿ��� �����ϴ� ���� ���ڵ�

- vs2015 ���Ȱ�ȭver ����
-> char *buffer : ��� ���ڿ��� ����� �޸� �ּ�
-> size_t_BufferCount : ��� ���ڿ��� �޸� ũ��
-> const char *format : ���� ���ڿ��� ����� �޸� �ּ�
-> [, argument] : ���� ���ڿ��� �����ϴ� ���� ���ڵ�

- ��ȯ��
-> ��µ� ���ڿ��� ����

----------------------------------------------------------------------------------------------------------------

sprintf()�� ���, ����ȭ�� ������ε� ����
=> ���ڿ��� ��� ��ü�ϴ� ���
=> ��, �ð��� ���� �ɸ� �� �ֱ� ������ ��Ȳ�� �°� ����ؾ���

==> �ð��� �����ϴ� ����� ������ �ش� ������ ������ �� �׶��׶� ����ϴ� ��� (�ð��� ����, �޸𸮰����� ����)
----------------------------------------------------------------------------------------------------------------
*/