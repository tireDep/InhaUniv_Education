// Q. 사용자로부터 양의 정수 하나 입력받음, 그 수 만큼 3의 배수를 출력하는 프로그램 작성
#include<stdio.h>

int main()
{
	int input = 0;

	printf("양의 정수 입력 : ");
	scanf_s("%d", &input);

	if (input < 1)
	{
		puts("양의 정수가 아니므로 1로 보정");
		input = 1;
	}

	int num = 1;
	while (num <= input)
	{
		printf("%d ", num*3);
		num++;
	}
	puts("");

	return 0;
}