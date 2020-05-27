// ����ü �������

#include<stdio.h>

#pragma pack(push,1)

struct userData_s
{
	char ch;
	int nAge;
};

struct myData
{
	char ch;
	int nAge;
	double dData;
};

#pragma pack(pop)

int main()
{
	printf("%d\n", sizeof(userData_s));
	printf("%d\n", sizeof(myData));

	return 0;
}


/*
------------------------------------------------------------------------------
#pragma pack�� ������, ����ü ��� ���㿡 ���ؼ� 8����Ʈ�� �⺻ ������

���ÿ��� ��� x,
but ���� ������̳� �ܺη� ������ ��� ������ ����ǰ� �����Ⱚ�� �����ȴ�!
------------------------------------------------------------------------------
*/

/*
��Ʈ�ʵ�
- ����ü ����� ����Ʈ ������ �ƴ� ��Ʈ ���� �����͸� �ٷ�� ����� ����Ǵ� ����ü
- �� ������� x, �˾Ƹ� �� ��

struct _dataFlag
{
	unsigned char main : 1;	// 8��Ʈ �� ������ 1��Ʈ
	unsigned char left : 2;	// ������ 2~3 ��Ʈ
	unsigned char right : 3;	// ������ 4~6 ��Ʈ
	unsigned char top : 2;	// ���� 2��Ʈ
};

*/