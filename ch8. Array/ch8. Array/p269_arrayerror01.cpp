// 269p
#include<stdio.h>

#define MAX 5

int main()
{
	int aList[5] = { 10,20,30,40,50 };
	int aListNew[MAX] = { 0 };	//define을 이용해서 배열 선언 가능
	int i = 0;

	// aListNew = aList; // 에러발생
	// 연산자의 왼족 피연산자가 변수가 아니라서 불가능 => 배열변수는 주소상수

	for (i = 0; i < 5; i++)
	{
		aListNew[i] = aList[i];
	}

	for (i = 0; i < 5; i++)
	{
		printf("%d\n", aListNew[i]);
	}
	putchar('\n');

	return 0;
}

/*
----------------------------------------
관습적으로 쓰이는 것
int : n + ~
float : f + ~
double : d + ~
array : a / arr / array + ~

기타 
-> _ + ~
-> 대소문자 섞어서
----------------------------------------
*/