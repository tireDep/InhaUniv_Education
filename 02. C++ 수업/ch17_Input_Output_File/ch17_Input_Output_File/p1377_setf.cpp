// setf() : 출력 형식 지정을 제어함
#include<iostream>

int main()
{
	using std::cout;
	using std::endl;
	using std::ios_base;

	int temperature = 63;

	cout << "오늘의 수온 : ";
	cout.setf(ios_base::showpos);
	cout << temperature << endl;	// 플러스 부호 사용

	cout << "프로그래머들에게 그 값은\n";
	cout << std::hex << temperature << endl;	// 출력에 16진 사용
	cout.setf(ios_base::uppercase);				// 16진 출력에 대문자 사용
	cout.setf(ios_base::showbase);				// 16진 출력에 OX 사용
	cout << "또는\n";
	cout << temperature << endl;

	cout << true << "!의 값은 ";
	cout.setf(ios_base::boolalpha);
	cout << true << "이다.\n";

	return 0;
}