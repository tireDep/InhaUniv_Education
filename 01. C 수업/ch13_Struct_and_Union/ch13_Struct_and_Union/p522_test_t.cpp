// 구조체 배열 수정
#include<stdio.h>
#include<string.h>

struct UserData_s
{
	int nAge;
	char szName[32];
	char szPhone[32];
};

int main()
{
	UserData_s userData[4];

	/*
	userData[0].nAge = 10;
	userData[1].nAge = 11;
	userData[2].nAge = 17;
	userData[3].nAge = 12;

	strcpy_s(userData[0].szName, "김어준");
	strcpy_s(userData[1].szName, "정봉주");
	strcpy_s(userData[2].szName, "주진우");
	strcpy_s(userData[3].szName, "김용민");

	strcpy_s(userData[0].szPhone, "1234");
	strcpy_s(userData[1].szPhone, "2345");
	strcpy_s(userData[2].szPhone, "3456");
	strcpy_s(userData[3].szPhone, "4567");
	*/

	for (int i = 0; i < 4; i++)
	{
		scanf_s("%d", &userData[i].nAge);
		scanf_s("%s", userData[i].szName, sizeof(userData[i].szName));
		scanf_s("%s", userData[i].szPhone, sizeof(userData[i].szPhone));
	}


	for (int i = 0; i < 4; i++)
	{
		printf("%d, %s, %s\n", userData[i].nAge, userData[i].szName, userData[i].szPhone);
	}

	return 0;
}