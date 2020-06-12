// Q. 다음 2x2 1차 방정식을 크래머의 공식을 사용해 풀이하는 프로그램을 작성하라
// ax + by = e
// cx + dy = f
// x = (ed - bf) / (ad - bc)
// y = (af - ec) / (ad - bc)
// a,b,c,d,e,f 값을 입력받아 결과를 출력하라
// ad-bc = 0이면 "해가 없음" 출력

#include<iostream>

using namespace std;

int main()
{
	int a, b, c, d, e, f;
	int x, y;

	cout << "ax + by = e" << endl << "cx + dy = f " << endl;
	cout << "숫자입력(a, b, c, d, e, f) : ";
	cin >> a >> b >> c >> d >> e >> f;

	if (a*d - b*c == 0)
		cout << "결과값\n해가 존재하지 않음" << endl;
	else
	{
		x = (e * d - b * f) / (a * d - b * c);
		y = (a * f - e * c) / (a * d - b * c);

		cout << "결과값\nx : " << x << endl << "y : " << y << endl;
	}

	return 0;
}