// 117p
// Q : �� ������ �Է¹޾� ����� ����� ����ϴ� ���α׷� + ��Ģ����
#include<stdio.h>

int main()
{
	float num1, num2;
	printf("�� ������ �Է��ϼ��� : ");
	scanf_s("%f %f", &num1, &num2);
	// scanf_s("%f%*c", &num1);
	// scanf_s("%f%*c", &num2);

	float result = 0;
	result = (num1 + num2) / 2;
	printf("AVG : %.2f\n", result);

	puts("\n------- ��Ģ���� ��� -------");
	result = num1 + num2;
	printf(" + : %.2f\n", result);
	
	result = num1 - num2;
	printf(" - : %.2f\n", result);
	
	result = num1 * num2;
	printf(" * : %.2f\n", result);
	
	result = num1 / num2;
	printf(" / : %.2f\n", result);
}