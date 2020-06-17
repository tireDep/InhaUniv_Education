// ������Ʈ�� �浹 �Ǻ�(2D �⺻ �浹����)

// Q. �� ���簢���� ���� �߽����� ��ǥ (x, y)�� �� w, ���� h�� �Է¹޾� 
// �� ��° ���簢���� ù ��° ���簢���� ���ο� �ִ���, ù ��° ���簢���� ��ġ�� ���� �Ǵ��ϴ� ���α׷� �ۼ�
// ���� / �ܺ� �Ǵ�

// ex)
// R1 : 2.5, 4, 2.5, 43
// R2 : 1.5, 5, 0.5, 3
// => R2�� R1�� ���ο� �ִ�.

// [ �������� : ó�� �Է��� ŭ ]

#include<iostream>
#include<cmath>

using namespace std;

struct RECTANGLE_S
{
	float x;
	float y;
	float w;
	float h;
};

struct RECPOS_S
{
	float x[4];
	float y[4];
};

void InputRec(RECTANGLE_S *firstRec, RECTANGLE_S *secRec);
void RecPos(RECTANGLE_S *rectangle, RECPOS_S *recPos);
void CalcRec(RECPOS_S *fRecPos, RECPOS_S *sRecPos, bool *isCheck);

int main()
{
	RECTANGLE_S firstRec;
	RECTANGLE_S secRec;
	InputRec(&firstRec, &secRec);

	RECPOS_S fRecPos;
	RECPOS_S sRecPos;
	RecPos(&firstRec, &fRecPos);
	RecPos(&secRec, &sRecPos);

	bool isCheck = false;
	int checkCnt = 0;
	int posCnt = 2;

	CalcRec(&fRecPos, &sRecPos, &isCheck);

	if (isCheck)
	{
		// 1 : ���� ����
		for (int i = 0; i < 4; i++)
		{
			if (i == 0 || i == 2)
				posCnt = 2;
			else if (i == 1 || i == 3)
				posCnt = -2;

			// 21
			// 34
			// �� ���

			// �� ���� 2�� : �� �𼭸� ������ �۰ų� ������
			// �� ���� 2�� : �� �𼭸��� �ݴ� ��ġ �𼭸� ������ ũ�ų� ������ 
			// => ù ��° �簢���� '�� ��° �𼭸�'�� �� ��° �簢���� 'ù ��° �𼭸�'�� ������ ��� �� �Ǻ� ���� �߰���(�̰��� ��ħ)
			if (fRecPos.x[i] >= sRecPos.x[i] && fRecPos.y[i] >= sRecPos.y[i] && fRecPos.x[posCnt] <= sRecPos.x[i] && fRecPos.y[posCnt] <= sRecPos.y[i])
				checkCnt++;
		}
		if (checkCnt == 4)
			cout << "�簢�� ���ο� ������" << endl;
		// 2 : ��ħ
		else
			cout << "�簢���� ��ħ" << endl;
	}
	else
	{
		// 3: �ܺ� ����
		cout << "�簢�� �ܺο� ������" << endl;
	}

	return 0;
}

void InputRec(RECTANGLE_S *firstRec, RECTANGLE_S *secRec)
{
	cout << "ù ��° �簢���� ��ǥ �Է�(�߽��� ��ǥ : x, y) : ";
	cin >> firstRec->x >> firstRec->y;
	cout << "ù ��° �簢���� ��ǥ �Է�(���� ���� : w, h) : ";
	cin >> firstRec->w >> firstRec->h;

	cout << "�� ��° �簢���� ��ǥ �Է�(�߽��� ��ǥ : x, y) : ";
	cin >> secRec->x >> secRec->y;
	cout << "�� ��° �簢���� ��ǥ �Է�(���� ���� : w, h) : ";
	cin >> secRec->w >> secRec->h;
}

void RecPos(RECTANGLE_S *rectangle, RECPOS_S *recPos)
{
	// �簢���� ��ǥ
	int minus = -1;
	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
			recPos->x[i] = rectangle->x + rectangle->w / 2;
			recPos->y[i] = rectangle->y + rectangle->h / 2;
			break;
		case 1:
			recPos->x[i] = rectangle->x + -(rectangle->w / 2);
			recPos->y[i] = rectangle->y + rectangle->h / 2;
			break;
		case 2:
			recPos->x[i] = rectangle->x + -(rectangle->w / 2);
			recPos->y[i] = rectangle->y + -(rectangle->h / 2);
			break;
		case 3:
			recPos->x[i] = rectangle->x + rectangle->w / 2;
			recPos->y[i] = rectangle->y + -(rectangle->h / 2);
			break;
		default:
			break;
		}
	}

	// cout << endl;
	// for (int i = 0; i < 4; i++)
	// {
	// 	cout << recPos->x[i] << " " << recPos->y[i] << endl;
	// }
}

void CalcRec(RECPOS_S *fRecPos, RECPOS_S *sRecPos, bool *isCheck)
{
	// ù��° �簢���� ���� �𼭸��� �ι�° �簢���� ���ϴ� �𼭸� ����			: x
	// ù��° �簢���� ���ϴ� �𼭸��� �ι�° �簢���� ���� �𼭸� ���� ����	: x
	// ù��° �簢���� ���ϴ� �𼭸��� �ι�° �簢���� ���� �𼭸� ���� ����	: y
	// ù��° �簢���� ���� �𼭸��� �ι�° �簢���� ���ϴ� �𼭸��� ����		: y 
	// https://progdev.tistory.com/8

	if ((fRecPos->x[0] >= sRecPos->x[2]) && (fRecPos->x[2] <= sRecPos->x[0]) && (fRecPos->y[2] <= sRecPos->y[0]) && (fRecPos->y[0] >= sRecPos->y[2]))
		*isCheck = true;
	else
		*isCheck = false;
}
