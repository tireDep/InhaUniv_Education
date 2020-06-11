// Q. 삼각형의 3개의 점(x1, y1), (x2, y2), (x3, y3)을 입력하여 면적을 출력하는 프로그램 작성
// 공식
// s = (side1 + side2 + side3) / 2
// 면적 = sqrt( s * (s - side1) * (s - side2) * (s - side3))
// 헤론의 공식

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	double x1, y1, x2, y2, x3, y3;
	double calcSide1, calcSide2, calcSide3;
	double calcS, result = 0;

	cout << "첫번째 좌표 입력(x1, y1) : ";
	cin >> x1 >> y1;
	cout << endl << "두번째 좌표 입력(x2, y2) : ";
	cin >> x2 >> y2;
	cout << endl << "세번째 좌표 입력(x3, y3) : ";
	cin >> x3 >> y3;

	calcSide1 = pow((x2 - x1), 2) + pow((y2 - y1), 2);
	calcSide1 = pow(calcSide1, 0.5);

	calcSide2 = pow((x3 - x2), 2) + pow((y3 - y2), 2);
	calcSide2 = pow(calcSide2, 0.5);

	calcSide3 = pow((x1 - x3), 2) + pow((y1 - y3), 2);
	calcSide3 = pow(calcSide3, 0.5);

	calcS = (calcSide1 + calcSide2 + calcSide3) / 2;
	result = sqrt(calcS * (calcS - calcSide1) * (calcS - calcSide2) * (calcS - calcSide3));
	
	calcSide1 = 5;
	calcSide1 = 6;
	calcSide1 = 7;
	calcS = (5 + 6 + 7) / 2;
	// 
	result = pow(calcS *(calcS - calcSide1)*(calcS - calcSide2)*(calcS - calcSide3), 2);
	cout << endl << "삼각형의 면적 : " << result << endl;

	return 0;
}