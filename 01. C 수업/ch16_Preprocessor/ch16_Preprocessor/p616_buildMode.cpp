#include<stdio.h>

#ifdef _DEBUG
	#define MODEMESSAGE "Debug mode"
#else
	#define MODEMESSAGE "Release mode"
#endif // _DEBUG

int main()
{
	puts(MODEMESSAGE);
	return 0;
}

/*
-----------------------------------------------------------------------------
������ ���, Release Mode�� �����ϴ� ���� ����
- Debug Mode�� ���, ��Ŀ���� �����ϱ� ����

Debug Mode���� ����Ǵ� ���� Release Mode���� ������� ���� �� ����

���� ���� �� ������ ��
���ִ��� or �Ϸ������ ������ �� Debug Mode �׽�Ʈ -> Release Mode �׽�Ʈ
-----------------------------------------------------------------------------
*/