// Q. 두 점(x1, y1) (x2, y2)를 입력받아 이 두 점 사이의 거리를 출력하는 프로그램 작성
// 거리계산 공식은
// squar root { (x2 - x1)^2 + (y2 - y1)^2 }
// squar root a를 계산하기 위해 pow(a, 0.5)를 사용할 수 있음 | sqrt()함수를 사용할 수 도 있음
// ex)
// x1, y1 : 1.5, -3.4
// x2, y2 : 4, 5
// Distance : 8.764...

// 두 점 사이의 거리 계산
// squar root { (x2 - x1)^2 + (y2 - y1)^2 }

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	double x1, x2, y1, y2;
	double result = 0;
	cout << "Input x1, y1 : ";
	cin >> x1 >> y1;
	cout << endl << "Input x2, y2 : ";
	cin >> x2 >> y2;

	result = pow((x2 - x1), 2) + pow((y2 - y1), 2);
	result = pow(result, 0.5);
	cout << endl << "Distance : " << result << endl;

	return 0;
}