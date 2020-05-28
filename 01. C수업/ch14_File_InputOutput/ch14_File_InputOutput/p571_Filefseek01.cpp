// 571p
#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp = NULL;

	fopen_s(&fp, "Test.dat", "rb");

	fseek(fp, 0, SEEK_END);
	printf("size of Test.dat : %u\n", ftell(fp));

	fclose(fp);
}

/*
---------------------------------------------------------------------------------------
fseek() : 파일을 특정 위치부터 읽을 수 있는 함수(파일 입출력 포인터 특정 위치로 강제 이동)
[인자들]
- FILE *stream : 파일 구조체에 대한 포인터
- long offset : 기준 위치에 대한 바이트 단위 오프셋
- int origin : 기준 위치(SEEK_SET/처음, SEEK_CUR/현재, SEEK_END/끝)

ftell() : 파일 입출력 포인터가 어느 위치에 있는지 알려주는 함수 
[인자들]
- FILE *stream : 파일 구조체에 대한 포인터
---------------------------------------------------------------------------------------
*/