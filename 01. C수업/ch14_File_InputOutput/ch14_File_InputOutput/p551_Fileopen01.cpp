// 551p
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void main()
{
	FILE *fp = NULL;

	// fp = fopen("test.txt", "w");
	fopen_s(&fp, "Test2.txt", "w");

	/*
	--------------------------------------------------------------------
	r / r+ : �ؽ�Ʈ �б� / ���� ����	/ ����
	w / w+ : �ؽ�Ʈ ���� / ������ �����ϴ� ���� ���� ����	/ ���� ����
	a / a+ : �ؽ�Ʈ �߰� / ���� ���� �ڿ� �߰�	/ ���� ����
	�ڿ� b / b+�� ������ ���̳ʸ� ����
	--------------------------------------------------------------------
	*/

	if (fp == NULL)
	{
		puts("ERROR : Failed to open file");
		return;
	}

	fclose(fp);

	return;
}
