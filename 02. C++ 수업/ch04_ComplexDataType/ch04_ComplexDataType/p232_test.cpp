// 232p 5 + 6 + 9
// Q5. candybar ����ü�� �� ���� ����� ������ �ִ�.
// ù ��° ����� ĵ����� ��ǥ�� ����, �� ��° ����� ĵ����� �߷�(�Ҽ��� ���� �� ����), �� ��° ����� ĵ����� Į�θ� ����
// ����ü�� �����ϰ�, snack�̶�� ĵ����� ����ü ������ ������� Ư�� ������ �ʱ�ȭ�϶�(Moch Munchm, 2.3, 350)
// �ʱ�ȭ�� ������ ������ �� �Բ� �ϰ�, ���� ������ ������ ���

// Q6. �� ���� ĵ��� ����ü�� ���ҷ� ������ �迭�� �����, �� �迭�� ����ü ���ҵ��� ���ϴ� ������ �ʱ�ȭ �� ��
// ����ü�� ������ ����ϴ� ���α׷� �ۼ�

// Q9. �� ���� ĵ��� ����ü ������ �����ϴ� ��ſ� new�� ����Ͽ� �� �迭�� �������� ����

#include<iostream>
#include<string>

using namespace std;

struct CandyBar_S
{
	string candyName;
	double candyWeight;
	int candyCal;
};

int main()
{
	CandyBar_S snack = { "Mocha Munch", 2.3,350 };
	cout << "Q5.\n";
	cout << "[���]\n��ǥ�� : " << snack.candyName 
		<< "\n�߷� : " << snack.candyWeight 
		<< "\nĮ�θ� : " << snack.candyCal;

	
	CandyBar_S candyArr[3];
	CandyBar_S snack_1 = { "Mocha Munch", 2.3,350 };
	CandyBar_S snack_2 = { "Banna Chips", 5.7,700 };
	CandyBar_S snack_3 = { "Strawberry Chips", 4.5 ,500 };
	candyArr[0] = snack_1;
	candyArr[1] = snack_2;
	candyArr[2] = snack_3;
	cout << "\n\nQ6.\n";
	for (int i = 0; i < 3; i++)
	{
		cout << "[���]\n��ǥ�� : " << candyArr[i].candyName 
			<< "\n�߷� : " << candyArr[i].candyWeight 
			<< "\nĮ�θ� : " << candyArr[i].candyCal << endl;
	}

	CandyBar_S *snackNew = new CandyBar_S[3];
	snackNew[0] = snack_1;
	snackNew[1] = snack_2;
	snackNew[2] = snack_3;

	cout << "\n\nQ9.\n";
	for (int i = 0; i < 3; i++)
	{
		cout << "[���]\n��ǥ�� : " << candyArr[i].candyName 
			<< "\n�߷� : " << candyArr[i].candyWeight 
			<< "\nĮ�θ� : " << candyArr[i].candyCal << endl;
	}
	delete[] snackNew;

	return 0;
}