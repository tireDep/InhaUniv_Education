// Q. 1~10���� ���� ���ϱ�
// for, while �� �� �̿�
#include<stdio.h>

int main()
{
	int result = 0;
	puts("For �� ���");
	for (int i = 0; i <= 10; i++)
	{
		result += i;
	}
	printf("%d\n", result);
	puts("");

	puts("While �� ���");
	int cnt = 0;
	result = 0;
	while (cnt <= 10)
	{
		result += cnt;
		cnt++;
	}
	printf("%d\n", result);
	puts("");

	return 0;

}