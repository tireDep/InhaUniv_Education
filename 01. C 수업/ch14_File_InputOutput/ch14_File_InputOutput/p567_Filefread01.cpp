#include<stdio.h>

struct _USERDATA
{
	char szName[16];
	char szPhone[16];
};

void main()
{
	FILE *fp = NULL;
	_USERDATA userData = { 0 };

	fopen_s(&fp, "Test.dat", "rb");
	if (fp == NULL)
		return;

	fread(&userData, sizeof(userData), 1, fp);
	puts(userData.szName);
	puts(userData.szPhone);

}

/*
--------------------------------------------------------
�ռ� ������ ������ ������Ʈ ������ �־���� ������ ���� ����
--------------------------------------------------------
*/