// 575p
// Q. ���� ��ο��� 'TestFile.txt' �ؽ�Ʈ ������ �� ��, 
// ����ڰ� �Է��� ���ڿ��� �ڿ� �̾ �߰��� �� �ٽ� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

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
	������ �� : ����� �ȵ�?
	*/

	fclose(fp);
	
	
	system("notepad.exe TestFile.txt");
}