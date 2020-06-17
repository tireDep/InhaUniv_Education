// Q. 비행기의 가속도 a와 이륙속도 v가 주어졌을 때, 비행기가 이륙하기 위한 최소 활주 길이를 계산하는 프로그램 작성
// 길이 공식 : v^2 / 2a
// 사용자에게 '미터/초(m/s)' 단위로 v와 '미터/초^2(m/s^2)' 단위로 가속도를 입력하도록 알려주고,
// 최소 활주 길이를 출력

// [출력]
// Speed and Acceleration : 60 3.5
// Minimum runway length : 514.286

// +)
// 가속도 : 단위 시간당 속도의 변화량
// 가속도 구하는 공식
// 가속도 = (나중속도 - 처음속도) / 시간
// a = (v1 - v0) / t

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	double inputSpeed, inputAcceleration;
	double minWay = 0;

	cout << "Input Speed and Acceleration : ";
	cin >> inputSpeed >> inputAcceleration;

	minWay = pow(inputSpeed, 2) / (2 * inputAcceleration);
	cout << "Minimum Runway Lenght(m) : " << minWay << endl;
	
	return 0;
}

/*
----------------------------------------------
속도(v) : m/s
가속도(a) : m/s^2

단위 계산
-> (m/s)^2 / m/s^2
= (m^2/s^2) / m/s^2
= m	==> 약분되고 남은 것
----------------------------------------------
*/