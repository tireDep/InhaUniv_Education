// Q5. T�� �׸� 5���� ���ҷ� ���� �迭�� �Ű������� ���ϰ�, �� �迭���� ���� ū �׸��� ���� �����ϴ� ���ø� �Լ� max5()�� �ۼ��϶�.
// (ũ�Ⱑ �����Ǿ� �����Ƿ� �Ű������� �����ϴ� ��� ������ ���� �ڵ��� ���� ���� �ִ�)
// int�� �� 5���� ���� �迭��, double�� �� 5���� ���� �迭�� ���� �� ���ø� �Լ��� ����ϴ� ���α׷��� �ۼ��Ͽ� �׽�Ʈ�϶�.

#include<iostream>

template <typename t>
void InputNum(t *numArr, const char *printStr);

template <typename t>
t Max5(t *numArr);

const int arrSize = 5;

using namespace std;

int main()
{
	int iNumArr[arrSize] = { 0 };
	double dNumArr[arrSize] = { 0 };

	cout << "[Q5]\n";
	InputNum(iNumArr, "type : int");
	cout << "\nint�� �迭�� �ִ� : " << Max5(iNumArr) << endl;

	InputNum(dNumArr, "type : double");
	cout << "\ndouble�� �迭�� �ִ� : " << Max5(dNumArr) << endl;

	return 0;
}

template <typename t>
void InputNum(t *numArr, const char *printStr)
{
	for (int i = 0; i < arrSize; i++)
	{
		cout << "\n�� �Է� (" << printStr << ") : ";
		cin >> numArr[i];
	}
}

template <typename t>
t Max5(t *numArr)
{
	t maxNum;

	for (int i = 1; i < arrSize; i++)
	{
		if (i == 1)
			maxNum = numArr[i - 1];

		if (maxNum < numArr[i])
			maxNum = numArr[i];
	}
	return maxNum;
}
