// Q. 이진탐색

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
		cout << "숫자 입력( 음수 입력 시 종료 ) : ";
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
	cout << "\n검색할 수 입력 : ";
	cin >> inputNum;
	
	// 출력
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
	// 출력

	while (1)
	{
		arrMid = (arrStart + arrFin) / 2;
		
		// 출력
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
		// 출력

		if(abs(arrMid - arrFin) == 1 || abs(arrMid - arrStart) == 1)
		{
			if (numArr[arrMid - 1] != inputNum)
				isCheck = true;
			else if (numArr[arrMid] != inputNum)
				isCheck = true;
			else if (numArr[arrMid+1] != inputNum)
				isCheck = true;

			if(isCheck)
				cout << "\n\n찾는값이 존재하지 않음\n";
			break;
		}

		if (numArr[arrMid] == inputNum)
		{
			cout << "\n\n" << inputNum << "은 배열 인덱스 " << arrMid << "에 존재함\n";
			break;
		}
		else if (numArr[arrMid] > inputNum)
			arrFin = arrMid;
		else
			arrStart = arrMid;
		// 이진탐색
	}

	delete[]numArr;
}