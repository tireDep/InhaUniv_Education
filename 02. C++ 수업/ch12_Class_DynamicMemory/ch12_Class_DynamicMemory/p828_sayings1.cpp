#include<iostream>
#include"p824_string1.h"

const int ArSize = 10;
const int MaxLen = 81;

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	String name;
	cout << "안녕하십니까? 성함이 어떻게 되십니까?\n";
	cin >> name;

	cout << endl << name << "씨! 간단한 영어 속담 " << ArSize << "개 만 입력해 주십시오(끝내려면 Enter)\n";
	
	String sayings[ArSize];	// 객체들의 배열
	char temp[MaxLen];	// 문자열 보관을 위한 임시 공간
	int i = 0;

	for (i = 0; i < ArSize; i++)
	{
		cout << i + 1 << " : ";
		cin.get(temp, MaxLen);
		
		while (cin && cin.get() != '\n')	// 개행 전까지 입력 받음
			continue;

		// cin : 공백, 개행 무시 + 개행 키보드 버퍼에 남겨둠 => space 단위로 입력받을 수 있음, enter가 나오면 입력 종료
		// cin.get() : 공백, 개행 포함 + 문자만 입력 받음 => space 단위로 끊어서 입력 받을 수 있음, enter가 나와도 입력받을 문자로 간주

		if (!cin || temp[0] == '\0')	// 입력이 실패했거나 빈 줄 입력이면 i를 증가시키지 않음
			break;
		else
			sayings[i] = temp;	// 오버로딩 대입 연산자 사용
	}

	int total = i;	// 읽어들인 총 줄 수
	if (total > 0)
	{
		cout << "\n다음과 같은 속담들을 입력하셨습니다.\n";

		for (i = 0; i < total; i++)
			cout << sayings[i][0] << " : " << sayings[i] << endl;

		int shortest = 0;
		int first = 0;
		for (i = 1; i < total; i++)
		{
			if (sayings[i].Length() < sayings[shortest].Length())
				shortest = i;
			if (sayings[i] < sayings[first])
				first = i;
		}

		cout << "\n가장 짧은 속담 : " << sayings[shortest] << endl;
		cout << "사전 순으로 가장 앞에 나오는 속담 : " << sayings[first] << endl;
		cout << "\n이 프로그램은 " << String::HowMany() << "개의 String 객체를 사용하였습니다. 이상!\n\n";
	}
	else
		cout << "\n입력금지! 이상!\n";

	return 0;
}