// 105p
// Q : getchar() �Լ��� ȣ���Ͽ� ����ڷκ��� ���� �� ���� �̻��� �Է¹ް�, ���߿��� �� ��° ���ڸ� ȭ�鿡 ���
#include<stdio.h>

int main()
{	
	printf("�Է� : ");
	getchar();
	// rewind(stdin);
	printf("��� : %c\n", getchar()); // ���ۿ� �����ִ� ���ڸ� �Է¹޾ƿ�
	return 0;
}