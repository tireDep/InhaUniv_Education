// 554p
#include<stdio.h>
#include<stdlib.h>

void main()
{
	FILE *fp = NULL;

	fopen_s(&fp, "TEST.txt", "w");

	printf("���� �������� �ּ� : %x\n", *fp);
	fprintf(fp, "%s\n", "Test String");
	printf("���� �������� �ּ� : %x\n", *fp);
	fprintf(fp, "%s\n", "Hello World");
	printf("���� �������� �ּ� : %x\n", *fp);
	
	/*
	-------------------------------------------------
	���� �����ʹ� ���� �����Կ� ���� ���� �����!
	- �� ���� ����Ű�� ����
	-------------------------------------------------
	*/

	fclose(fp);

	system("notepad.exe TEST.txt");
	// �޸����� �����
}