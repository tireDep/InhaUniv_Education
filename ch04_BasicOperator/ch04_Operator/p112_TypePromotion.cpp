// 112p
#include<stdio.h>

int main()
{
	char ch = 'A';

	printf("%c\n", ch);
	printf("%c\n", ch + 1);
	printf("%c\n", 'A' + 2);
	// A B C 출력

	puts("");
	printf("%d\n", 5.0 + 2);
	printf("%f\n", 5.0 + 2);
	// 형변환 일어남 => %d 형식으로 출력 x

	return 0;
}