// 377p
// �����Ϳ� �迭
#include<stdio.h>

int main()
{
	puts("[�迭�� �̿��� ���]");
	
	int numArr[3] = { 10,20,30 };

	printf("%x %x %x\n", numArr, numArr + 0, &numArr[0]);	// numArr�� ù��° �ּ� ǥ�� ���, 3�� ��� numArr[0]�� �ּҸ� ����Ŵ
	printf("%x %x\n", numArr + 1, &numArr[1]);	// numArr[1]�� �ּ�
	printf("%x %x\n", numArr + 2, &numArr[2]);	// numArr[2]�� �ּ�
	puts("");

	printf("%d %d %d\n", *numArr, *(numArr + 0), *&(numArr[0]));
	printf("%d %d\n", *(numArr + 1), *&(numArr[1]));
	printf("%d %d\n", *(numArr + 2), *&(numArr[2]));
	puts("");

	for (int i = 0; i < 3; i++)
	{
		printf("%d %d %d\n", *(numArr + i), *&numArr[i], numArr[i]);
	}
	puts("");

	printf("�ּ��� ũ�� : %d %d %d\n", sizeof(numArr), sizeof(numArr + 0), sizeof(&numArr[0]));
	// ù��° ��� : ��ü�� ũ��
	// �ι�° & ����° ��� : ù��° ����� ũ��

	printf("�迭�� ���� : %d\n", sizeof(numArr) / sizeof(int));
	puts("");

	// ------------------------------------------------------------------------------
	
	puts("[�����͸� �̿��� ���]");

	int *p = NULL;
	p = numArr;

	printf("%x %x %x\n", p, p + 0, &p[0]);
	printf("%x %x\n", p + 1, &p[1]);
	printf("%x %x\n", p + 2, &p[2]);
	puts("");

	printf("%d %d %d\n", *p, *(p + 0), *&p[0]);
	printf("%d %d\n", *(p + 1), *&p[1]);
	printf("%d %d\n", *(p + 2), *&p[2]);
	puts("");

	for (int i = 0; i < 3; i++)
	{
		printf("%d %d %d\n", *(p + i), *&p[i], p[i]);
	}
	puts("");

	/*
	---------------------------------------------------
	*&�� ���޾� ���� ���, ���Ǵ� �Ϳ� ����!
	---------------------------------------------------
	*/

	printf("�迭�� ũ�� : %d\n�������� ũ�� : %d\n", sizeof(numArr), sizeof(p));
	puts("");

	// ------------------------------------------------------------------------------

	*p = 40;
	p = numArr + 1; // == &numArr[1];
	*p = 50;
	printf("%d %d %d\n", *p, *(p + 1), *(p + 2));
	puts("");

	p = numArr + 2; // == &numArr[2];
	*p = 60;
	printf("%d %d %d\n", *(p - 2), *(p - 1), *p);
	puts("");

	return 0;

}