// Q. 절대값을 구하는 함수 Abs() 구현 
// -> 키보드를 통해 입력 받는 절대값을 구하는 프로그램
// ex) 정수를 입력하시오 : -34
//	   절대값은 34 입니다.

#include<stdio.h>

void Abs(int num);
void Result(int result);

int main()
{
	int inputNum;
	printf("정수를 입력 하시오 : ");
	scanf_s("%d", &inputNum);

	Abs(inputNum);

	return 0;
}

void Abs(int num)
{
	if (0 > num)
	{
		return Result(num*-1);
	}
	else
	{
		return Result(num);
	}
}

void Result(int result)
{
	printf("절대값은 %d 입니다\n", result);
}