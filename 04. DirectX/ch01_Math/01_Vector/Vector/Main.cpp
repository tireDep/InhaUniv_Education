#include <iostream>
#include "cVector.h"

using namespace std;

int main()
{
	// cVector3 temp;
	// cVector3 uVec(1,-1,0);
	// cVector3 vVec(3,2,1);
	// 
	// if (uVec == vVec)
	// 	cout << "두 벡터 비교 : " << "두 벡터가 같음" << endl << endl;
	// else
	// 	cout << "두 벡터 비교 : " << "두 벡터가 같지 x" << endl << endl;
	// // >> 벡터 비교
	// 
	// temp = uVec + vVec;
	// cout <<"Vector + : ";
	// temp.PrintValue();
	// cout << endl;
	// // >> 벡터 덧셈
	// 
	// cout << "Dot Product : " << uVec.Dot(uVec, vVec) << endl << endl;
	// // >> 벡터 내적
	// 
	// temp = uVec.Cross(uVec, vVec);
	// cout << "Cross Product : ";
	// temp.PrintValue();
	// cout << endl;
	// // >> 벡터 외적


	// ------------------------------------------------------------------------------

	cVector3 vec1(1, 0, 0);
	cVector3 vec2(0, 1, 0);

	cout << "[ 단위 벡터를 이용한 확인 ]" << endl;
	cout << "vec1 == vec2 : " << (vec1 == vec2) << endl;	// print : 0
	cout << "vec1 != vec2 : " << (vec1 != vec2) << endl;	// print : 1
	cout << endl;

	cVector3 vec3 = (vec1 + vec2);
	cout << "vec1 + vec2 : ";
	vec3.PrintValue();

	cVector3 vec4 = (vec1 - vec2);
	cout << "vec1 - vec2 : ";
	vec4.PrintValue();
	cout << endl;

	cVector3 vecCross = cVector3::Cross(vec1, vec2);
	cout << "vec1 X vec2 : ";
	vecCross.PrintValue();

	cVector3 vecCross2 = cVector3::Cross(vec2, vec1);
	cout << "vec2 X vec1 : ";
	vecCross2.PrintValue();
	cout << endl;

	cout << "[ 벡터를 이용한 확인 ]" << endl;

	cVector3 uVec(-1, 3, 2);
	cVector3 vVec(3, -4, 1);

	cVector3 temp = uVec + vVec;
	temp.PrintValue();

	temp = uVec - vVec;
	temp.PrintValue();

	temp = uVec * 3 + vVec * 2;
	temp.PrintValue();

	temp = uVec * -2 + vVec;
	temp.PrintValue();

	temp = uVec.Normalize();
	temp.PrintValue();
	cout << endl;

	// ------------------------------------------------------------------------------

	cVector3 uVec2(1, 1, 0);
	cVector3 vVec2(-2, 2, 0);
	// cVector3 uVec2(1, 1, 1);
	// cVector3 vVec2(2, 3, 4);

	// >> 내적해서 0보다 크면 예각, 0보다 작으면 둔각, 0이면 90도
	// >> 충돌체크할 때 사용할 수 있음

	float degree = cVector3::Dot(uVec2, vVec2);
	cout << degree << endl;

	// cVector3 u(-1, 3, 2);
	// cVector3 v(3, -4, 1);

	// cVector3 u(1, 1, 1);
	// cVector3 v(2, 3, 4);

	cVector3 u(1,1,0);
	cVector3 v(-2,2,0);

	degree = cVector3::GetDegree(u, v);
	cout << degree << endl;

	// ------------------------------------------------------------------------------

	// >>>
	// 어떤 좌표계를 기준으로 점 A = (0,0,0), B = (0,1,3), C = (5,1,0) 이 세점이 하나의 삼각형을 정의한다고 하자
	// 이 삼각형에 수직인 벡터를 구하라
	// <<<

	// -> 한 점에서 다른 점으로 진행하는 벡터 2개 구한 후(뺄셈) 외적 계산

	cVector3 a(0, 0, 0);
	cVector3 b(0, 1, 3);
	cVector3 c(5, 1, 0);

	cVector3 ca = c - a;
	cVector3 ba = b - a;
	
	cVector3 result = cVector3::Cross(ba, ca);
	result.PrintValue();

	float degree2 = cVector3::GetDegree(a, result);
	cout << degree2 << endl;
	// >> 각도 확인

}