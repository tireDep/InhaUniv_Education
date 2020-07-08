// 파일에 저장한다
#include<iostream>	//  이것은 많은 시스템에서 필요 x
#include<fstream>
#include<string>

int main()
{
	using namespace std;
	string fileName;

	cout << "새 파일을 위한 이름을 입력하십시오. : ";
	cin >> fileName;

	// 새 파일을 위한 출력 스트림 객체를 fout 이라는 이름으로 생성한다
	ofstream fout(fileName.c_str());

	fout << "비밀 번호 노출에 주의하십시오.\n";	// 파일에 기록
	cout << "비밀 번호를 입력하십시오. : ";	// 화면에 출력
	float secret;
	cin >> secret;
	fout << "귀하의 비밀 번호는 " << secret << "입니다.\n";
	fout.close();	// 파일 닫기

	// 새 파일을 위한 입력 스트림 객체를 fin이라는 이름으로 생성
	ifstream fin(fileName.c_str());
	cout << fileName << " 파일의 내용은 다음과 같습니다.\n";
	char ch;
	while (fin.get(ch))	// 파일로부터 한 문자를 읽음
		cout << ch;	// 그 문자를 화면에 출력

	cout << "프로그램을 종료합니다.\n";
	fin.close();

	return 0;
}