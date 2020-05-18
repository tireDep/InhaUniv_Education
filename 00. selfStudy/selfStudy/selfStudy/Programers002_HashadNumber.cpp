/*
Q. 하샤드 수 구하기
양의 정수 x가 하샤드 수이려면 x의 자릿수의 합으로 x가 나누어져야 합니다. 
예를 들어 18의 자릿수 합은 1+8=9이고, 18은 9로 나누어 떨어지므로 18은 하샤드 수입니다. 
자연수 x를 입력받아 x가 하샤드 수인지 아닌지 검사하는 함수, solution을 완성해주세요.

제한 조건
x는 1 이상, 10000 이하인 정수입니다.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int x);

int main()
{
	int inputNum;
	scanf_s("%d", &inputNum);

	solution(inputNum);

	return 0;
}


bool solution(int x)
{
	int check = 0;
	int temp = x;

	for (int i = 10000; i > 0; i = i / 10)
	{
		check = check + temp / i;
		temp = temp%i;
	}

	if (x % check == 0)
	{
		puts("하샤드 수 O");
		return true;
	}
	else
	{
		puts("하샤드 수 X");
		return false;
	}
}