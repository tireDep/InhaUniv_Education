// 402p

#include<stdio.h>
#include<string.h>

int main()
{
	char szBuffer[32] = { "I am a boy." };

	printf("%p\n", szBuffer);	// �迭 �ּ� ���

	printf("%p\n", strstr(szBuffer, "am"));
	printf("%p\n", strstr(szBuffer, "boy"));
	// ��� ���ڿ����� ���ڿ��� �˻��ϰ� ã�� ��ġ(�ּ�) ���

	printf("Index : %d\n", strstr(szBuffer, "am") - szBuffer);
	printf("Index : %d\n", strstr(szBuffer, "boy") - szBuffer);
	// ���ڿ��� �˻��� ��ġ���� ������ �Ǵ� �ּҸ� ���� �ε��� ��� ����

	/*
	----------------------------------
	�߰� ����
	I'm a boy -> I'm a cat
	----------------------------------
	*/

	char *index = strstr(szBuffer, "boy");	// �ּҰ� ��ȯ
	if (index != NULL)
	{
		memcpy(index, "Cat", sizeof(char) * 3);	// �ش��ϴ� �ּҰ��� ���ڿ� ����
	}
	
	/*
	----------------------------------
	���� ���� ���� ����ȭ �ؾ���!
	���� ��츦 ����� �ڵ� ������ ��
	----------------------------------
	*/
	puts(szBuffer);

	return 0;
}