// Q : �ΰ��� ������ 100���̶� ����, ��� �Ѱ��Ǹ� �ǿ�� ������ 2�� ����
//     � ����� ����(20��)�� �� ���� ��踦 20�Ⱓ �Ϸ翡 n���� �� �ǿ��ٸ� 
//     ������ �󸶳� ����Ǿ��� �� ����� �� �� ������ ���(������)
#include<stdio.h>

int main()
{
	int inputNum = 0;

	printf("��� ���� �� : ");
	scanf_s("%d", &inputNum);
	
	int lossTime = inputNum * 2 * 365 * 20; // �� �ð�(��)
	// ���� * 2�� * 1�� * 20��

	int loseyear = lossTime / 60 / 24 / 365;
	int losemonth = lossTime / 60 / 24 % 356 / 30;
	int loseday = lossTime / 60 / 24 % 365 % 30;
	int losehour = lossTime / 60 % 24;
	int losemin = lossTime % 60;

	// -------------------- 
	// 60 : 1�ð�
	// 24 : 1�� 
	// 30 : 1��
	// 12 : 1��
	// --------------------

	printf("����� ���� : %d�� %d���� %d�� %d�ð� %d�� \n", loseyear, losemonth, loseday, losehour, losemin);
	
	int lifeTime = (24 * 60 * 365 * 100) - lossTime; // ���� ����

	int lifeyear = lifeTime / 60 / 24 / 365;
	int lifemonth = lifeTime / 60 / 24 % 356 / 30;
	int lifeday = lifeTime / 60 / 24 % 365 % 30;
	int lifehour = lifeTime / 60 % 24;
	int lifemin = lifeTime % 60;

	printf("��� ���� : %d�� %d���� %d�� %d�ð� %d��\n", lifeyear, lifemonth, lifeday, lifehour, lifemin);
	printf("            (�� %d��, 40�� ���� �� %d�� ����)\n", lifeyear, lifeyear - 40);

	return 0;

}