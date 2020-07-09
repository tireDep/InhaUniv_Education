// Q. GemometricObject 클래스를 확장하는 Triangle 클래스를 설계하라
// 이 클래스는 다음을 포함한다.
// 1. 삼각형의 세 변을 정의하는 3개의 double형 데이터 필드 side1, side2, side3
// 2. 각 변이 1.0인 기본 삼각형을 생성하는 인수 없는 생성자
// 3. 지정된 side1, side2, sdie3을 갖는 삼각형을 생성하는 생성자
// 4. 모든 3개의 데이터 필드에 대한 상수 접근자 함수 (const access function)
// 5. 삼각형의 면적을 반환하는 getArea() 상수 함수
// 6. 삼각형의 둘레를 반환하는 getPerimeter() 상수 함수

// Triangle 클래스와 GeometricObject 클래스를 포함하는 UML 다이어그램을 작성하고 클래스를 구현,
// 삼각형의 세 변, 색상과 삼각형이 채워졌는지를 나타내는 1 또는 0을 사용자가 입력하는 테스트 프로그램을 작성

// 프로그램은 입력 값을 사용하여 삼각형의 세 변, 색상 설정 및 채색 설정(filled)
// 속성을 가지는 Triangle 객체를 생성해야하며
// 면적, 둘레, 색상 그리고 채워졌는지의 여부를 true 또는 false로 화면에 출력해야 한다.

// +) Rectangle 클래스도 상속받는 형식으로 재구현 할 것

#include"GemometricObject.h"
#include<iostream>

using namespace std;

int main()
{
	TRIANGLE_S triangle;	// 4, 5, 6 기준 9.92157
	cout << "[삼각형]" << endl;
	cout << "삼각형의 세 변의 길이 : " << triangle.GetSide1()
		<< ", " << triangle.GetSide2() << ", " << triangle.GetSide3() << endl;
	cout << "삼각형의 면적 : " << triangle.GetArea() << endl;
	cout << "삼각형의 둘레 : " << triangle.GetPerimeter() << endl;
	cout << "\n삼각형의 색상 & 채워짐 유무\n";
	triangle.SetColor();
	if (triangle.CheckFilled())
		cout << "TRUE\n=> 삼각형이 " << triangle.GetColor() << " 색상으로 채워짐\n";
	else
		cout << "FALSE\n=> 삼각형이 " << triangle.GetColor() <<" 색상으로 채워지지 않음\n";

	RECTANGLE_C rectangle;
	cout << endl << "[직사각형]" << endl;
	cout << "직사각형의 두 변의 길이 : " << rectangle.GetWidth() << ", " << rectangle.GetHeight() << endl;
	cout << "직사각형의 면적 : " << rectangle.GetArea() << endl;
	cout << "직사각형의 둘레 : " << rectangle.GetPerimeter() << endl;
	
	CIRCLE_C circle;
	cout << endl << "[원]" << endl;
	cout << "원의 반지름 : " << circle.GetRadius() << endl;
	cout << "원의 면적 : " << circle.GetArea() << endl;
	cout << "원의 둘레 : " << circle.GetPerimeter() << endl;

	return 0;
}