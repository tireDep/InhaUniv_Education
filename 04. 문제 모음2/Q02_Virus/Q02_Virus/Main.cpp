// Q. 질병 통제 예방센터에 근무중인 당신의 주 업무는 바이러스 감염자 수의 예측이다.
// 
// 바이러스의 초기 감염자 : A
// 바이러스의 시간당 증가 배수 : B
// 바이러스가 퍼져나간 시간 : T
// 
// 위와 같은 데이터가 주어졌을 때 T시간이 지나고 나서 최종 감염자 수를 예측해야 한다
// 
// 예를 들어서 초기 감염자(A)가 2명, 증가 배수(B)가 4, 시간(T)인 경우
// 최종 감염자의 수는 2*4*4*4 = 128명으로 예측할 수 있다.
// 
// 입력 포맷 >
// 입력 데이터는 딱 한 줄이 주어지며 A B T 값이 공백으로 분리되어 순서대로 제공된다
//
// 제약 조건 >
// 1 <= A <= 100
// 1 <= B <= 100
// 1 <= T <= 10^13
//
// 출력 포맷 >
// T 시간이 지난 후 최종 감염자의 수를 10^9+7(1000000007) 값으로 나눈 후
// 그 나머지 값을 출력한다
// 샘플 입력 >
// 2 3 20
// 
// 샘플 출력 >
// 973568760

#include <iostream>

using namespace std;

int main()
{
	long int iPeople = 0;
	long long int fMulNum = 0;
	long long int fTime = 0;

	cin >> iPeople >> fMulNum >> fTime;

	// long long int fResult = iPeople * pow(fMulNum, fTime);
	// long long int fDivide = pow(10, 9) + 7;
	
	long long int fResult = iPeople;
	long long int fDivide = pow(10, 9) + 7;
	for (int i = 0; i < fTime; i++)
	{
		if (fResult * fMulNum <= 0)
		{
			fResult /= fDivide;
			cout << "testtesttestttest" << endl;
			cout << i << endl;
		}
		fResult *= fMulNum;
	}

	cout << fResult << endl;
	// cout << "result : " << fResult % fDivide << endl;

	return 0;
}