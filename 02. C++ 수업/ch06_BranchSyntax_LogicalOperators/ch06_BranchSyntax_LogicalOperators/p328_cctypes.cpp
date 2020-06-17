// 328p

#include<iostream>
#include<cctype>

using namespace std;

int main()
{
	char ch;
	int whiteSpace = 0;
	int digits = 0;
	int chars = 0;
	int punct = 0;
	int others = 0;

	cout << "분석할 텍스트를 입력하십시오. 입력의 끝을 @로 표시하십시오.\n";
	cin.get(ch);

	while (ch != '@')
	{
		if (isalpha(ch)) // 영문자
			chars++;
		else if (isspace(ch))	// 화이트 스페이스(공백, 개행 등)
			whiteSpace++;
		else if (isdigit(ch))	// 숫자
			digits++;
		else if (ispunct(ch))	// 구두점
			punct++;
		else
			others++;

		cin.get(ch);
	}

	cout << endl 
		<< "알파벳 문자 : " << chars << ", " 
		<< "화이트 스페이스 : " << whiteSpace << ", " 
		<< "숫자 : " << digits << ", " 
		<< "구두점 : " << punct << ", " 
		<< "기타 : " << others << endl;

	return 0;

}