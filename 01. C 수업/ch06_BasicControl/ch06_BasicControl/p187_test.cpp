// 187p
// Q : ���� ��� ��� ���α׷�
#include<stdio.h>

int main()
{
	puts("���� ��� ���");
	
	int busRate = 1000;
	int inputAge = 0;
	printf("�����Է� : ");
	scanf_s("%d", &inputAge);

	if (20 > inputAge)
	{
		busRate -= busRate*0.25;
	}

	// if(inputAge>=20 ? busRate = busRate : busRate = busRate -  busRate*0.25)

	printf("������� : %d��\n", busRate);

	return 0;
}