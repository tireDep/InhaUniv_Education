// Q6. T형 항목들을 원소로 가진 배열과, 그 배열의 원소 개수를 나타내는 정수를 매개변수로 취하고 그 배열에서 가장 큰 항목을
// 리턴하는 템플릿 함수 maxn()을 작성하라.
// int형 값 6개를 가진 배열과, double형 값 4개를 자진 배열에 대해 그 템플릿 함수를 사용하는 프로그램을 작성하여 테스트하라.
// 또한 이 프로그램은 char를 지시하는 포인터의 배열과, 포인터의 개수를 매개변수로 취하고, 가장 긴 문자열의 주소를 리턴하는
// 특수화를 제공해야 한다.
// 여러개의 문자열이 가장 긴 길이를 갖는 것으로 나온다면, 가장 먼저 나오는 문자열의 주소를 리턴해야 한다.
// 5개의 문자열 포인터를 가진 배열을 사용하여 그 특수화를 테스트하라

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
	cout << "\nint형 배열의 최댓값 : " << MaxN(iNumArr, inputArrSize) << endl;

	InputArrSize(inputArrSize, "type : double");
	double *dNewNumArr = new double[inputArrSize];
	InputData(dNumArr, "type : double", inputArrSize);
	cout << "\ndouble형 배열의 최댓값 : " << MaxN(dNumArr, inputArrSize) << endl;

	InputArrSize(inputArrSize, "type : char **");
	int temp = inputArrSize;
	int strLen = inputArrSize;
	char **charStr = new char*[inputArrSize];
	InputArrSize(inputArrSize, "최대 문자열 길이");
	for (int i = 0; i < temp; i++)
	{
		charStr[i] = new char[inputArrSize + 1];
		memset(charStr[i], '\0', inputArrSize + 1);

		cout << "문자열 입력 : ";
		cin >> charStr[i];
	}

	cout << "\n가장 긴 문자열 : " << MaxN(charStr, strLen) << endl;

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
	cout << "\n배열의 사이즈 입력 (" << printStr << ") : ";
	cin >> inputArrSize;
}

template <typename t>
void InputData(t *dataArr, const char *printStr, int maxSize)
{
	for (int i = 0; i < maxSize; i++)
	{
		cout << "\n값 입력 (" << printStr << ") : ";
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