// 99p
#include<stdio.h>

int main()
{
	char szName[32] = { 0 };
	int nAge = 0;

	printf("���̸� �Է��ϼ��� : ");
	scanf_s("%d", &nAge); // %*c : ���� ���

	printf("�̸��� �Է��ϼ��� : ");
	//fflush(stdin); /* ������� ���� */
	// fgetchar()�� ����Ű�� �����ص� ��
	rewind(stdin); // ���� ���
	gets_s(szName,sizeof(szName));

	printf("���� : %d, �̸� : %s\n", nAge, szName);

	return 0;
}