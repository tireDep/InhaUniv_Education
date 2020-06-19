// Q5. T형 항목 5개를 원소로 가진 배열을 매개변수로 취하고, 그 배열에서 가장 큰 항목을 차장 리턴하는 템플릿 함수 max5()를 작성하라.
// (크기가 고정되어 있으므로 매개변수로 전달하는 대신 루프에 직접 코딩해 넣을 수도 있다)
// int형 값 5개를 가진 배열과, double형 값 5개를 가진 배열에 대해 그 템플릿 함수를 사용하는 프로그램을 작성하여 테스트하라.

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
	cout << "\nint형 배열의 최댓값 : " << Max5(iNumArr) << endl;

	InputNum(dNumArr, "type : double");
	cout << "\ndouble형 배열의 최댓값 : " << Max5(dNumArr) << endl;

	return 0;
}

template <typename t>
void InputNum(t *numArr, const char *printStr)
{
	for (int i = 0; i < arrSize; i++)
	{
		cout << "\n값 입력 (" << printStr << ") : ";
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
