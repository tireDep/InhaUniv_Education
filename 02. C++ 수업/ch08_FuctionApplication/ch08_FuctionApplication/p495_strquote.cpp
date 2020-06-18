// 참조변수
// 495p

#include<iostream>
#include<string>

using namespace std;

string Version1(const string &s1, const string &s2);
const string &Version2(string &s1, const string &s2);
const string &Version3(string &s1, const string &s2);

/*
---------------------------------------------
Complie은 O, Warning O,
실행시 터짐
==> 실행시 터질 경우 Warning Msg 잘 봐야함
---------------------------------------------
*/

int main()
{
	string input;
	string copy;
	string result;

	cout << "문자열을 입력하세요 : ";
	getline(cin, input);
	copy = input;
	cout << "입력한 문자열 : " << input << endl;
	
	result = Version1(copy, "***");
	cout << "\n바뀐 문자열 : " << result << endl;
	cout << "원래 문자열 : " << input << endl;

	result = Version2(copy, "###");
	cout << "\n바뀐 문자열 : " << result << endl;
	cout << "원래 문자열 : " << input << endl;

	result = Version3(copy, "@@@");
	cout << "\n바뀐 문자열 : " << result << endl;
	cout << "원래 문자열 : " << input << endl;
}

string Version1(const string &s1, const string &s2)
{
	string temp;

	temp = s2 + s1 + s2;
	return temp;
}

const string &Version2(string &s1, const string &s2)
{
	s1 = s2 + s1 + s2;
	return s1;
}

const string &Version3(string &s1, const string &s2)	// 나쁜 설계
{
	string temp;

	temp = s2 + s1 + s2;
	return temp;	// 더 이상 존재하지 않는 메모리(주소)를 반환하므로 에러남
}
