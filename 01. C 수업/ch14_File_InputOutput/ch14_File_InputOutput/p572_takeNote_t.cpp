// 571p
#include<stdio.h>
#include<stdlib.h>

void SeekTest();

int main()
{
	SeekTest();
}

void SeekTest()
{
	FILE *fp;
	fopen_s(&fp, "seek.txt", "w");
	fputs("ABCDEFGHIJ", fp);
	fclose(fp);

	fopen_s(&fp, "seek.txt", "r");
	fseek(fp, 0, SEEK_SET);	// 맨 앞으로 포인터 이동	// A 출력
	fprintf(stdout, "%c \n", fgetc(fp));

	fseek(fp, 2, SEEK_SET);	// 맨 앞으로 포인터 이동 + 2 // C 출력
	fprintf(stdout, "%c \n", fgetc(fp));

	fseek(fp, -1, SEEK_END);	// 맨 뒤로 포인터 이동 -1 // J 출력
	fprintf(stdout, "%c \n", fgetc(fp));

	fseek(fp, -2, SEEK_CUR);	// 맨 뒤로 포인터 이동 -1 // I 출력
	fprintf(stdout, "%c \n", fgetc(fp));

	rewind(fp);	// 파일 포인터를 맨 앞으로 옮김
	fprintf(stdout, "%c \n", fgetc(fp));

	fclose(fp);
	// system("notepad.exe seek.txt");
}

/*
--------------------------------------------------------------------------------------
feof() : 파일 포인터가 끝에 위치하고 있는지 확인
- 0을 반환 하면 파일 포인터가 끝에 있는 것이 아님
- 그렇지 않으면 0이 아닌 값을 반환

_access() : 특정 파일의 존재 유무 및 접근 권한을 확인
- 0을 반환하면 파일에 대해 mode 인자로 전달된 접근 허용
- -1을 반환하면 파일이 존재하지 않거나 접근할 수 없음 의미

[인자들]
- const char *path : 접근 검사를 할 파일이 저장된 경로가 저장된 메모리에 대한 포인터
- int mode : 접근 검사 값
--> 00 : 파일의 존재 유무만 확인
--> 02 : 쓰기 전용 모드인지 확인
--> 04 : 읽기 전용 모드인지 확인
--> 06 : 읽기/쓰기가 모두 가능한지 확인
--------------------------------------------------------------------------------------
*/