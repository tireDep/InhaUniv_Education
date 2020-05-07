// 99p
#include<stdio.h>

int main()
{
	char szName[32] = { 0 };
	int nAge = 0;

	printf("나이를 입력하세요 : ");
	scanf_s("%d", &nAge); // %*c : 버퍼 비움

	printf("이름을 입력하세요 : ");
	//fflush(stdin); /* 실행되지 않음 */
	// fgetchar()로 엔터키만 제거해도 됨
	rewind(stdin); // 버퍼 비움
	gets_s(szName,sizeof(szName));

	printf("나이 : %d, 이름 : %s\n", nAge, szName);

	return 0;
}