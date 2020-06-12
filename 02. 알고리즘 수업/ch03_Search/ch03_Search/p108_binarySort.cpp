// Q. ����Ž��

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int cnt = 0;
	int temp = 0;
	int *numArr = new int [10];
	memset(numArr, 0, _msize(numArr));

	for (int i = 0; i < _msize(numArr) / sizeof(int); i++)
	{
		system("cls");
		cnt++;
		cout << "���� �Է�( ���� �Է� �� ���� ) : ";
		cin >> numArr[i];
		
		if (cnt == _msize(numArr) / sizeof(int))
			numArr = (int *)realloc(numArr, _msize(numArr) * 2);

		if (numArr[i] > 0 )
		{
			for (int j = 0; j <= i; j++)
			{
				if (numArr[j] > numArr[i])	// sort
				{
					temp = numArr[i];
					numArr[i] = numArr[j];
					numArr[j] = temp;
				}
			}
		}
		else
		{
			numArr[i] = 0;
			break;
		}
	}

	int inputNum = 0;
	int arrStart = 0, arrFin = cnt;
	int arrMid = (arrStart + arrFin) / 2;
	bool isCheck = false;
	cout << "\n�˻��� �� �Է� : ";
	cin >> inputNum;
	
	// ���
	cout << endl << "  | ";
	for (int i = 0; i < cnt - 1; i++)
	{
		cout << i << " ";
	}
	cout << endl << "--+";
	for (int i = 0; i < cnt - 1; i++)
	{
		cout << "---";
	}
	cout << endl << "  | ";
	// ���

	while (1)
	{
		arrMid = (arrStart + arrFin) / 2;
		
		// ���
		for (int i = 0; i < cnt; i++)
		{
			if (arrStart == i)
				cout << "<-";
			else if (arrFin - 1 == i)
				cout << "->";
			else if (arrMid == i)
				cout << "+";
			else
				cout << "  ";
		}
		cout << endl << " " << arrMid << "| ";
		for (int i = 0; i < cnt - 1; i++)
		{
			cout << numArr[i] << " ";
		}
		cout << endl << "  | ";
		// ���

		if(abs(arrMid - arrFin) == 1 || abs(arrMid - arrStart) == 1)
		{
			if (numArr[arrMid - 1] != inputNum)
				isCheck = true;
			else if (numArr[arrMid] != inputNum)
				isCheck = true;
			else if (numArr[arrMid+1] != inputNum)
				isCheck = true;

			if(isCheck)
				cout << "\n\nã�°��� �������� ����\n";
			break;
		}

		if (numArr[arrMid] == inputNum)
		{
			cout << "\n\n" << inputNum << "�� �迭 �ε��� " << arrMid << "�� ������\n";
			break;
		}
		else if (numArr[arrMid] > inputNum)
			arrFin = arrMid;
		else
			arrStart = arrMid;
		// ����Ž��
	}

	delete[]numArr;
}