/* 
Q. ���簢�� �����

�� �������� ǥ�� �Է����� �� ���� ���� n�� m�� �־����ϴ�.
��(*) ���ڸ� �̿��� ������ ���̰� n, ������ ���̰� m�� ���簢�� ���¸� ����غ�����.

���� ����
n�� m�� ���� 1000 ������ �ڿ����Դϴ�.
*/

#include <stdio.h>

int main(void) {
	int nNum, mNum;
	scanf_s("%d %d", &nNum, &mNum);

	for (int i = 0; i < mNum; i++)
	{
		for (int j = 0; j < nNum; j++)
		{
			printf("*");
		}
		puts("");
	}
	return 0;
}