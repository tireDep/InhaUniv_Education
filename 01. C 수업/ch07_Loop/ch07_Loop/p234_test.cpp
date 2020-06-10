// Q, 5행 2열의 사각형 출력하기
#include<stdio.h>

int main()
{
	int i = 0, j = 0;
	while (5 > i)
	{
		while (5 > j)
		{
			printf("*\t");
			j++;
		}
		puts("");
		i++;
		j = 0;
	}
	return 0;
}