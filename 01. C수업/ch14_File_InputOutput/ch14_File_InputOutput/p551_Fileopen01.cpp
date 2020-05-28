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
	r / r+ : 텍스트 읽기 / 파일 열기	/ 에러
	w / w+ : 텍스트 쓰기 / 기존에 존재하던 파일 내용 삭제	/ 새로 생성
	a / a+ : 텍스트 추가 / 기존 내용 뒤에 추가	/ 새로 생성
	뒤에 b / b+가 붙으면 바이너리 파일
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
