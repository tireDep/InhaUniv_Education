// 521p
#include<stdio.h>
#include<string.h>

typedef struct UseData_s
{
	int nAge;
	char szName[32];
	char szPhone[32];
}UserData_s;

int main()
{
	UserData_s user = { 0,"," };

	user.nAge = 10;
	strcpy_s(user.szName, "Hoon");
	strcpy_s(user.szPhone, "010-1234-1234");

	printf("%d��, %s, %s\n", user.nAge, user.szName, user.szPhone);

	return 0;
}

/*
--------------------------------------------------------------------
������ ���� typedef�� ������ ������ �ʾƵ� ����ü �̸����� ��� ������
--------------------------------------------------------------------
*/