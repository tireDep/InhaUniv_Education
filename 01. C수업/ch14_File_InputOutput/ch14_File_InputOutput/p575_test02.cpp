// 575p
// Q. 현재 경로에서 'TestFile.txt' 텍스트 파일을 연 후, 
// 사용자가 입력한 문자열을 뒤에 이어서 추가한 후 다시 저장하는 프로그램을 작성하시오.

#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp = NULL;

	fopen_s(&fp, "TestFile.txt", "w");
	fprintf(fp, "%s\n", "First String");
	fclose(fp);

	fopen_s(&fp, "TestFile.txt", "a");
	rewind(fp);
	fprintf(fp, "%s\n", "Second String");
	/*
	질문할 것 : 덮어쓰기 안됨?
	*/

	fclose(fp);
	
	
	system("notepad.exe TestFile.txt");
}