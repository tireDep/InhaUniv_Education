// 89p
#include<stdio.h>

int main()
{
	int age;
	char name[32] = { 0 };

	printf("나이를 입력하세요 : ");
	scanf_s("%d%*c", &age);
	// %*c : 버퍼 비우기

	printf("이름을 입력하세요 : ");
	gets_s(name);

	printf("당신의 나이는 %d이고 이름은 '%s' 입니다.\n", age, name);

	return 0;
}

// ---------- 주의 ---------
// 한글은 영어보다 약 2배 정도 큼!
// 문자열 뒤에는 \0 들어감!
// gets : 라인 자체 읽을 때
// scanf : 각각 입력 받을 때 유리
// -------------------------