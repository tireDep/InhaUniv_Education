#include<stdio.h>
#include<stdlib.h>

struct  _USERDATA
{
	char szName[16];
	char szPhone[16];
	int test;
};

void main()
{
	FILE *fp = NULL;
	
	_USERDATA userData = { "HoSung","123-4567", 0};

	fopen_s(&fp, "Test.dat", "wb");
	if (fp == NULL)
		return;

	fwrite(&userData, sizeof(userData), 1, fp);
	fclose(fp);

	system("notepad.exe Test.dat");
	// 바이너리 모드로 파일을 생성하여 썼지만 그 내용이 문자열로 해석할 수 있는 것이기 때문에 메모장으로 내용 확인 가능
	// 하지만 실제 값이 0인 것들은 메모장에 표시될 수 없으므로 실제 내용을 완전히 보여준 것은 아님

	return;
}