#include<stdio.h>

struct UserData_s
{
	char name[32];
	char num[32];

	UserData_s *pNext;
};

void SelfRefPtr();

int main()
{
	SelfRefPtr();
}

void SelfRefPtr()
{

	UserData_s user1 = { "name1", "1111", NULL };
	UserData_s user2 = { "name2", "2222", NULL };
	UserData_s user3 = { "name3", "3333", NULL };

	user1.pNext = &user2;
	user2.pNext = &user3;
	
	/*
	printf("%s %s \n", user1.name, user1.num);
	printf("%s %s \n", user1.pNext->name, user1.pNext->num);
	printf("%s %s \n", user1.pNext->pNext->name, user1.pNext->pNext->num);
	*/

	UserData_s * pUser = &user1;
	while (pUser != NULL)
	{
		printf("%s %s \n", pUser->name, pUser->num);
		pUser = pUser->pNext;
	}
	// Single Linked List

	return;
}

/*

pUser p123[a123]

user1 a123[a,b123]
user2 b123[b,c123]
user3 c123[c,NULL]

*/