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
	// ���̳ʸ� ���� ������ �����Ͽ� ������ �� ������ ���ڿ��� �ؼ��� �� �ִ� ���̱� ������ �޸������� ���� Ȯ�� ����
	// ������ ���� ���� 0�� �͵��� �޸��忡 ǥ�õ� �� �����Ƿ� ���� ������ ������ ������ ���� �ƴ�

	return;
}