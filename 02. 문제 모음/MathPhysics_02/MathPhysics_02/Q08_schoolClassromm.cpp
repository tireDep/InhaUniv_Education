// Q. 학교에 100개의 사물함과 100명의 학생이 있다.
// 모든 사물함은 개학 첫 날에는 닫혀있다. 학생이 교실로 들어가면서 s1이라는 첫 번째 학생은 모든 사물함을 연다
// 두 번째 학생 s2는 두 번째 사물함 L2부터 시작하여 하나씩 건너 뛰면서 사물함을 닫는다.
// 학생 s3은 세 번째 사물함 L3부터 시작하여 세 번째 사물함마다 상태를 변경한다.(열린건 닫고, 닫힌 것은 연다)
// 학생 s4는 L4 사물함 부터 시작하여 다섯번째 사물함 마다 사물함의 상태를 변경한다.
// 학생 s5는 L5 사물함 부터 시작하여 다섯 번째 사물함 마다 사물함의 상태를 변경한다.
// 이 작업은 학생 s100이 L100 사물함을 변경할 때 까지 계속된다.
// 모든 학생이 교실을 통과하고 나간 다음, 어떤 사물함이 열려있는지 확인하고, 열려있는 모든 사물함 번호를 출력하는 프로그램을 작성하라.

#include<iostream>

using namespace std;

const int arrSize = 100;

int main()
{
	int cabinet[arrSize] = { 0 };	// 0 : close, 1 : open

	for (int i = 0; i < arrSize; i++)
	{
		for (int j = i; j < arrSize; j += i + 1)
			cabinet[j] = cabinet[j] == 0 ? 1 : 0;
	}

	int cnt = 0;
	cout << "열려있는 사물함의 번호\n";
	for (int i = 0; i < arrSize; i++)
	{
		if (cabinet[i] != 0)
		{
			cout << "Cabinet : " << i + 1 << endl;
			cnt++;
		}
	}

	cout << "열려있는 사물함의 개수 : " << cnt << endl;

	return 0;
}