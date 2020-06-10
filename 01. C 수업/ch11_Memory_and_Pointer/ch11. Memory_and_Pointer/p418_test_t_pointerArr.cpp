// Q. ���� �ڵ带 �̿�, �������� ���� ���·� ��µǵ��� ���α׷��� �ۼ�
// char *string[2] = {"I Love C", "Hello World"};
// ��� 
// I Love C World

#include<stdio.h>

void Add(double x, double y);
void Minus(double x, double y);

int main()
{
	char *string[2] = { "I Love C","Hello World" };

	printf("%c ", string[0][0]);
	printf("%s ", *string + 2);
	printf("%s\n", string[1] + 6);

	// test
	puts("");
	printf("%c\n", string[0][0]);
	printf("%c\n", string[1][0]);
	printf("%c\n", **string);
	printf("%c\n", *string[1]);

	puts("");
	
	// �ʱ�

	// ������ �迭 : �迭�� ��Ұ� ������
	// �迭 ������ : �迭�� ����Ű�� ������

	// ������ �迭
	int a = 10, b = 20, c = 30;
	int *pA[3] = { NULL,NULL,NULL };
	
	// �迭 ������
	int arr[2][3] = { 10, 20, 30, 40, 50 ,60 };
	int(*pArr)[3] = NULL;

	pA[0] = &a;
	pA[1] = &b;
	pA[2] = &c;


	printf("%x %x %x\n", &a, &b, &c);
	printf("%x %x %x\n", pA[0], pA[1], pA[2]);
	printf("%x %x %x\n", *(pA+0), *(pA + 1), *(pA + 2));

	printf("%d %d %d\n", *&a, *&b, *&c);
	printf("%d %d %d\n", *pA[0], *pA[1], *pA[2]);
	printf("%d %d %d\n", **(pA + 0), **(pA + 1), **(pA + 2));

	pArr = arr;

	puts("=================================================");

	printf("%d %d %d\n", pArr[0][0], pArr[0][1], pArr[0][2]);
	printf("%d %d %d\n", pArr[1][0], pArr[1][1], pArr[1][2]);
	

	// �Լ� ������
	double x = 3.1, y = 5.5;
	void(*pFunc)(double, double);
	printf("'add' address : %x\n", Add);
	printf("'pFunc' address : %x\n", &pFunc);

	pFunc = Add;
	pFunc(x, y);

	pFunc = Minus;
	pFunc(x, y);

	return 0;
}

void Add(double x, double y)
{
	double result = x + y;
	printf("result : %.2lf + %.2lf = %.2lf\n", x, y, result);
}

void Minus(double x, double y)
{
	double result = x - y;
	printf("result : %.2lf - %.2lf = %.2lf\n", x, y, result);
}