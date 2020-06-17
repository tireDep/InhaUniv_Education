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
fprintf() : 형식을 지정해서 값을 입력함
fscanf() : 형식을 지정해서 값을 읽어들일 때 사용
*/