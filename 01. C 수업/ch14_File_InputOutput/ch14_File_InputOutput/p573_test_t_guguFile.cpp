// Q. 
// - ���α׷� �󿡼� ���� 99.txt�� ���� �� ���Ͽ� �������� �����ϴ� ���α׷� �ۼ�, fprintf() �̿�
// - fseek() �Լ��� �̿��ؼ� ���ϴ� ���� ���븸 ã�Ƽ� ����ϴ� ���α׷� �ۼ�

#include<stdio.h>

int main()
{
	FILE *fp = NULL;
	fopen_s(&fp, "99.txt", "w");

	for (int i = 0; i <= 9; i++)
	{
		if (i <= 1) continue;
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0) continue;
			fprintf(fp, "%2d x %2d = %2d\n", i, j, i*j);
		}
		fprintf(fp,"            \n"); // ����12 + \n + eof = 14	
		/*
		-------------------------------
		[����]
		- ������ ���� ������ ������!
		-------------------------------
		*/
	}
	fclose(fp);

	fopen_s(&fp, "99.txt", "r");
	char printArr[128] = { 0 };
	int inputNum;
	printf("���ϴ� �� �Է� : ");
	scanf_s("%d", &inputNum);

	if (inputNum <= 1)
		inputNum = 2;
	else if (inputNum >= 10)
		inputNum = 9;
	// ������ ����

	fseek(fp, 14 * 10 * (inputNum - 2), SEEK_SET);	
	/*
	-------------------------------------------------------------
	[����]
	- 14 : NULL�� ���� ������ ��(12 + \n + eof)
	- 10 : �ش� ���� ����(1~9 + \n)
	- -2 : ���� 0�� ��ġ���� 2���� ���۵Ǳ� ������, -2�� ����� ��
	-------------------------------------------------------------
	*/
	for (int i = 0; i < 9; i++)
	{
		fprintf(stdout, "%s", fgets(printArr, sizeof(printArr), fp));
	}

	fclose(fp);

	return 0;
}