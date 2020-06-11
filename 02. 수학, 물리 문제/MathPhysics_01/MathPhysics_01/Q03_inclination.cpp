// Q. 두 개의 점(x1, y1)과 (x2, y2)의 좌표를 입력받아 두 선을 잇는 선의 기울기를 출력하는 프로그램을 작성하라
// 공식 : (y2 - y1) / (x2 - x1)

#include<iostream>

using namespace std;

int main()
{
	int x1, y1, x2, y2;
	int result = 0;

	cout << "첫번째 좌표 입력(x1, y1) : ";
	cin >> x1 >> y1;
	cout << endl << "두번째 좌표 입력(x2, y2) : ";
	cin >> x2 >> y2;

	result = (y2 - y1) / (x2 - x1);
	cout << endl << "기울기 값 : " << result << endl;

	return 0;
}