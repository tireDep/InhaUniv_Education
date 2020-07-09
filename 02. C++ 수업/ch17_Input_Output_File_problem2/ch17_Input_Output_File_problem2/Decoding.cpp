// Q. 암호화된 파일을 복호화(decoding)하는 프로그램을 작성해라.
// 사용자가 입력 파일 이름과 출력 파일 이름을 입력하면 입력 파일의 암호가 풀린 버전을 출력 파일에 저장하라.

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

const int DecodingNum = 5;

int main()
{
	string startName;
	string endName;
	cout << "파일명 입력(복호화할 파일) : ";
	cin >> startName;

	cout << "파일명 입력(저장될 파일) : ";
	cin >> endName;

	ifstream sFp;
	sFp.open(startName, ios_base::in | ios_base::binary);
	if (!sFp.is_open())
	{
		cout << "파일 오픈 에러\n";
		exit(EXIT_FAILURE);
	}

	ofstream eFp;
	eFp.open(endName, ios_base::out | ios_base::binary);
	if (!eFp.is_open())
	{
		sFp.close();
		cout << "파일 생성 에러\n";
		exit(EXIT_FAILURE);
	}

	int fileSize;
	sFp.seekg(0, ios::end);
	fileSize = sFp.tellg();
	sFp.seekg(0, ios::beg);

	char tempChar;
	while (fileSize>0)
	{
		sFp.read(&tempChar, 1); // sFp.get(tempChar);	// 이거도 가능
		tempChar -= DecodingNum;
		eFp << tempChar;	// eFp.put(tempChar); // 이거도 가능

		fileSize--;
	}

	sFp.close();
	eFp.close();

	return 0;
}