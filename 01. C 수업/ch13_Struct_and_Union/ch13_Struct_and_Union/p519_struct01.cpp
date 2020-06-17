// 519p
#include<stdio.h>
#include<string.h>

struct UseData_s
{
	int nAge;
	char szName[32];
	char szPhone[32];
};

int main()
{
	UseData_s user = { 0,"," };

	user.nAge = 10;
	strcpy_s(user.szName, "Hoon");
	strcpy_s(user.szPhone, "010-1234-1234");

	printf("%d»ì, %s, %s\n", user.nAge, user.szName, user.szPhone);

	return 0;
}