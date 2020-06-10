// 554p
#include<stdio.h>
#include<stdlib.h>

void main()
{
	FILE *fp = NULL;

	fopen_s(&fp, "TEST.txt", "w");

	printf("파일 포인터의 주소 : %x\n", *fp);
	fprintf(fp, "%s\n", "Test String");
	printf("파일 포인터의 주소 : %x\n", *fp);
	fprintf(fp, "%s\n", "Hello World");
	printf("파일 포인터의 주소 : %x\n", *fp);
	
	/*
	-------------------------------------------------
	파일 포인터는 값이 증감함에 따라 값이 변경됨!
	- 맨 끝을 가리키고 있음
	-------------------------------------------------
	*/

	fclose(fp);

	system("notepad.exe TEST.txt");
	// 메모장이 실행됨
}