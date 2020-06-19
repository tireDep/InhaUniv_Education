// Q6. T�� �׸���� ���ҷ� ���� �迭��, �� �迭�� ���� ������ ��Ÿ���� ������ �Ű������� ���ϰ� �� �迭���� ���� ū �׸���
// �����ϴ� ���ø� �Լ� maxn()�� �ۼ��϶�.
// int�� �� 6���� ���� �迭��, double�� �� 4���� ���� �迭�� ���� �� ���ø� �Լ��� ����ϴ� ���α׷��� �ۼ��Ͽ� �׽�Ʈ�϶�.
// ���� �� ���α׷��� char�� �����ϴ� �������� �迭��, �������� ������ �Ű������� ���ϰ�, ���� �� ���ڿ��� �ּҸ� �����ϴ�
// Ư��ȭ�� �����ؾ� �Ѵ�.
// �������� ���ڿ��� ���� �� ���̸� ���� ������ ���´ٸ�, ���� ���� ������ ���ڿ��� �ּҸ� �����ؾ� �Ѵ�.
// 5���� ���ڿ� �����͸� ���� �迭�� ����Ͽ� �� Ư��ȭ�� �׽�Ʈ�϶�

#include<iostream>
#include<string>

const int arrSize = 5;

void InputArrSize(int &inputArrSize, const char *printStr);

template <typename t>
void InputData(t *numArr, const char *printStr, int maxSize);

template <typename t>
t MaxN(t *numArr, int maxSize);

#define returnVal char *
template <>
returnVal MaxN<returnVal>(returnVal *numArr, int maxSize);

// char *MaxN(char **charStr, int pCnt);

template <typename t>
void Terminate(t *deleteArr);

using namespace std;

int main()
{
	int iNumArr[arrSize] = { 0 };
	double dNumArr[arrSize] = { 0 };
	
	cout << "[Q6]\n";
	int inputArrSize = 0;

	InputArrSize(inputArrSize, "type : int");
	int *iNewNumArr = new int[inputArrSize];
	InputData(iNumArr, "type : int", inputArrSize);
	cout << "\nint�� �迭�� �ִ� : " << MaxN(iNumArr, inputArrSize) << endl;

	InputArrSize(inputArrSize, "type : double");
	double *dNewNumArr = new double[inputArrSize];
	InputData(dNumArr, "type : double", inputArrSize);
	cout << "\ndouble�� �迭�� �ִ� : " << MaxN(dNumArr, inputArrSize) << endl;

	InputArrSize(inputArrSize, "type : char **");
	int temp = inputArrSize;
	int strLen = inputArrSize;
	char **charStr = new char*[inputArrSize];
	InputArrSize(inputArrSize, "�ִ� ���ڿ� ����");
	for (int i = 0; i < temp; i++)
	{
		charStr[i] = new char[inputArrSize + 1];
		memset(charStr[i], '\0', inputArrSize + 1);

		cout << "���ڿ� �Է� : ";
		cin >> charStr[i];
	}

	cout << "\n���� �� ���ڿ� : " << MaxN(charStr, strLen) << endl;

	Terminate(iNewNumArr);
	Terminate(dNewNumArr);

	for (int i = 0; i < temp; i++)
	{
		Terminate(charStr[i]);
	}
	Terminate(charStr);


	return 0;
}

void InputArrSize(int &inputArrSize, const char *printStr)
{
	cout << "\n�迭�� ������ �Է� (" << printStr << ") : ";
	cin >> inputArrSize;
}

template <typename t>
void InputData(t *dataArr, const char *printStr, int maxSize)
{
	for (int i = 0; i < maxSize; i++)
	{
		cout << "\n�� �Է� (" << printStr << ") : ";
		cin >> dataArr[i];
	}
}

template <typename t>
t MaxN(t *numArr, int maxSize)
{
	t maxNum;

	for (int i = 1; i < maxSize; i++)
	{
		if (i == 1)
			maxNum = numArr[i - 1];

		if (maxNum < numArr[i])
			maxNum = numArr[i];
	}
	return maxNum;
}

// char *MaxN(char **charStr, int pCnt);
template <>
returnVal MaxN<returnVal>(returnVal *charStr, int pCnt)
{
	char *p = charStr[0];

	for (int i = 0; i < pCnt - 1; i++)
	{
		if (strlen(charStr[i])<strlen(charStr[i + 1]))
			p = charStr[i + 1];
	}

	return p;
}

template <typename t>
void Terminate(t *deleteArr)
{
	delete[]deleteArr;
}