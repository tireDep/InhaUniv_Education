// 347p
// Q. 사용자가 입력한 값에서 최댓값 구하기와 코드 분할

#include"test.h"

int main()
{
	int aList[3] = { 0 };
	int nMax = -9999, i = 0;

	for (i = 0; i < 3; i++)
	{
		aList[i] = GetData();
	}

	nMax = GetMax(aList[0], aList[1], aList[2]);

	printData(aList[0], aList[1], aList[2], nMax);
	
	return 0;

}