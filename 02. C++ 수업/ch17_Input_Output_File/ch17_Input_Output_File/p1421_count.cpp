// 리스트에 나열한 파일들에 있는 문자들을 카운트
#include<iostream>
#include<fstream>
#include<cstdlib>

int main(int argc, char *argv[])
{
	using namespace std;	
	if (argc == 1)	// 매개변수들이 없으면 종료
	{
		cerr << "사용법 : " << argv[0] << " fileName[s]\n";
		exit(EXIT_FAILURE);
	}

	ifstream fin;	// 스트림을 염
	long count;
	long total = 0;
	char ch;

	for (int file = 1; file < argc; file++)
	{
		fin.open(argv[file]);	// 스트림을 argv[file]에 연결
		if (!fin.is_open())
		{
			cerr << argv[file] << " 파일을 열 수 없습니다.\n";
			fin.clear();
			continue;
		}
		count = 0;
		while (fin.get(ch))
			count++;

		cout << argv[file] << " 파일에 들어 있는 문자 수는 " << count << "입니다.\n";
		total += count;
		fin.clear();	// 일부 컴파일러에서 요구
		fin.close();	// 파일과의 연결을 끊는다
	}

	cout << "전체 파일에 들어 있는 문자 수는 " << total << "입니다.\n";

	return 0;
}