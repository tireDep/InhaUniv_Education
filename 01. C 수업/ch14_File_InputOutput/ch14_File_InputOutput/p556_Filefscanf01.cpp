// 556p
// #define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

void main()
{
	int nData = 0;
	char szBuffer[128] = { 0 };
	FILE *fp = NULL;

	fopen_s(&fp, "fscanfTest.txt", "w");
	fprintf(fp, "%d, %s\n", 20, "Test");
	fclose(fp);

	fopen_s(&fp, "fscanfTest.txt", "r");
	// fscanf(fp, "%d, %s\n", &nData, szBuffer);
	fscanf_s(fp, "%d, %s\n", &nData, szBuffer, 10, 150);

	printf("%d, %s\n", nData, szBuffer);
}

/*
fprintf() : ������ �����ؼ� ���� �Է���
fscanf() : ������ �����ؼ� ���� �о���� �� ���
*/