// Q : 성적표 프로그램
// A : ~ 90, B : ~ 80, C : ~ 70, D : ~ 60, F : ~ 0
#include<stdio.h>

int main()
{
	int score = 0;
	printf("점수 입력 : ");
	scanf_s("%d", &score);

	char grade = 0;
	if(60 > score)
	{
		grade = 'F';
	}
	else
	{
		grade = 'D';

		if (70 <= score && 79 >= score)
		{
			grade = 'C';
		}
		if (80 <= score && 89 >= score)
		{
			grade = 'B';
		}
		if (90 <= score)
		{
			grade = 'A';
		}
	}

	printf("성적 : %c\n", grade);
	
	return 0;
}