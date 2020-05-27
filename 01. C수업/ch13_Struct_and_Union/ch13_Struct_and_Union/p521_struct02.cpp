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

	printf("%d살, %s, %s\n", user.nAge, user.szName, user.szPhone);

	return 0;
}

/*
--------------------------------------------------------------------
지금은 굳이 typedef로 선언을 해주지 않아도 구조체 이름으로 사용 가능함
--------------------------------------------------------------------
*/