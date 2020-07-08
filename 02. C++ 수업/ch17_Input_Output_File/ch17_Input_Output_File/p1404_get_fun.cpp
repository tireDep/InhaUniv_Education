// get(), getline() 사용
// getline() : 입력 스트림에 있는 종료 문자을 읽고 버림
// get() : 그대로 남겨 둠
#include<iostream>

const int Limit = 255;

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	char input[Limit];

	cout << "getline()이 처리할 문자열을 입력하십시오.\n";
	cin.getline(input, Limit, '#');
	cout << "다음과 같이 입력하셨습니다.\n";
	cout << input << "\n1단계 완료\n";

	char ch;
	cin.get(ch);
	cout << "다음 입력 문자는 " << ch << "입니다.\n";

	if (ch != '\n')
		cin.ignore(Limit, '\n');	// 그 줄의 나머지를 읽고 버린다

	cout << "get()이 처리할 문자열을 입력하십시오.\n";
	cin.get(input, Limit, '#');
	cout << "다음과 같이 입력하셨습니다.\n";
	cout << input << "\n2단계 완료\n";

	cin.get(ch);
	cout << "다음 입력 문자는 " << ch << "입니다" << endl;

	return 0;
}