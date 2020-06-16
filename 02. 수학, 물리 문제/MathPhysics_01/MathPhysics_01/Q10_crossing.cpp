// Q. 그림과 같이 선 1의 두점은 (x1, y1)과 (x2, y2)로, 선 2의 두 점은 (x3,y3), (x4, y4)로 주어진다.
// 두 선의 교차점은
// (y1 - y2)x - (x1 - x2)y = (y1 - y2)x1 - (x1 - x2)y1
// (y3 - y4)x - (x3 - x4)y = (y3 - y4)x3 - (x3 - x4)y3
// 이 1차 방정식은 크래머의 공식으로 해를 구할 수 있다.
// 방정식의 해가 없다면 두 선은 평행하다.
// 4개의 점을 입력받아 교차점을 출력하는 프로그램을 작성하라

// ex)
// 2, 2, 5, -1.0, 4.0, 2.0, -1.0, -2.0
// Intersecting Point is : (2.8889, 1.1111)

// +) 크래머의 공식
// ax + by = e
// cx + dy = f
// x = (ed - bf) / (ad - bc)
// y = (af - ec) / (ad - bc)
// ad - bc = 0이면 "해가 없음"

#include<iostream>

using namespace std;

int main()
{
	float x1, x2, x3, x4;
	float y1, y2, y3, y4;

	cout << "점 입력(x1, y1) : ";
	cin >> x1 >> y1;
	cout << "점 입력(x2, y2) : ";
	cin >> x2 >> y2;
	cout << "점 입력(x3, y3) : ";
	cin >> x3 >> y3;
	cout << "점 입력(x4, y4) : ";
	cin >> x4 >> y4;

	if (((y1 - y2) * (x3 - x4) - (x1 - x2) * (y3 - y4)) == 0)
	{
		cout << "해가 없음" << endl;
		return 0;
	}
	
	// 음수조심!
	float x = (((y1 - y2) * x1 - (x1 - x2) * y1) * -(x3 - x4) - -(x1 - x2) * ((y3 - y4) * x3 - (x3 - x4) * y3)) / ((y1 - y2) * -(x3 - x4) - -(x1 - x2) * (y3 - y4));
	//					// e //						 // d //	  // b //				 // f //					// a //	     // d //	   // b //	   // c //
	float y = ((y1 - y2) * ((y3 - y4) * x3 - (x3 - x4) * y3) - ((y1 - y2) * x1 - (x1 - x2) * y1) * (y3 - y4)) / ((y1 - y2) * -(x3 - x4) - -(x1 - x2) * (y3 - y4));
	//			// a //					// f //					 // e //							// c //		 // a //	   // d //	    // b //	   // c //

	cout << x << " " << y << endl;
	
	return 0;
}