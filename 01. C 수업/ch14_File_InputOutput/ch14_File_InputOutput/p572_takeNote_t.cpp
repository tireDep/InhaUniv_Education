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
	fseek(fp, 0, SEEK_SET);	// �� ������ ������ �̵�	// A ���
	fprintf(stdout, "%c \n", fgetc(fp));

	fseek(fp, 2, SEEK_SET);	// �� ������ ������ �̵� + 2 // C ���
	fprintf(stdout, "%c \n", fgetc(fp));

	fseek(fp, -1, SEEK_END);	// �� �ڷ� ������ �̵� -1 // J ���
	fprintf(stdout, "%c \n", fgetc(fp));

	fseek(fp, -2, SEEK_CUR);	// �� �ڷ� ������ �̵� -1 // I ���
	fprintf(stdout, "%c \n", fgetc(fp));

	rewind(fp);	// ���� �����͸� �� ������ �ű�
	fprintf(stdout, "%c \n", fgetc(fp));

	fclose(fp);
	// system("notepad.exe seek.txt");
}

/*
--------------------------------------------------------------------------------------
feof() : ���� �����Ͱ� ���� ��ġ�ϰ� �ִ��� Ȯ��
- 0�� ��ȯ �ϸ� ���� �����Ͱ� ���� �ִ� ���� �ƴ�
- �׷��� ������ 0�� �ƴ� ���� ��ȯ

_access() : Ư�� ������ ���� ���� �� ���� ������ Ȯ��
- 0�� ��ȯ�ϸ� ���Ͽ� ���� mode ���ڷ� ���޵� ���� ���
- -1�� ��ȯ�ϸ� ������ �������� �ʰų� ������ �� ���� �ǹ�

[���ڵ�]
- const char *path : ���� �˻縦 �� ������ ����� ��ΰ� ����� �޸𸮿� ���� ������
- int mode : ���� �˻� ��
--> 00 : ������ ���� ������ Ȯ��
--> 02 : ���� ���� ������� Ȯ��
--> 04 : �б� ���� ������� Ȯ��
--> 06 : �б�/���Ⱑ ��� �������� Ȯ��
--------------------------------------------------------------------------------------
*/