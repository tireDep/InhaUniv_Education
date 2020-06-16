// 358p

#include<iostream>
#include<fstream>	// file I/O
#include<cstdlib>	// exit(()

const int SIZE = 60;

using namespace std;

int main()
{
	char fileName[SIZE];
	ifstream inFile;
	cout << "데이터 파일의 이름을 입력하시오 : ";
	cin.getline(fileName, SIZE);

	inFile.open(fileName);
	if (!inFile.is_open())
	{
		cout << fileName << " 파일을 열 수 없습니다.\n프로그램을 종료합니다.\n";
		exit(EXIT_FAILURE);
	}

	double value;
	double sum = 0.0;
	int count = 0;

	inFile >> value;
	while (inFile.good())	// 입력이 양호하고 EOF가 아닌 동안
	{
		++count;
		sum += value;
		inFile >> value;
	}
	// 맨 마지막에 개행 or 공백이 있어야 맨 마지막 값까지 읽혀짐
	// 에디터 별로 다를 수 있음

	if (inFile.eof())
		cout << "파일 끝에 도달했습니다.\n";
	else if (inFile.fail())
		cout << "데이터 불일치로 입력이 종료되었습니다.\n";
	else
		cout << "알 수 없는 이유로 입력이 종료되었습니다.\n";

	if (count == 0)
		cout << "데이터가 없습니다.\n";
	else
	{
		cout << "읽은 항목의 개수 : " << count << endl;
		cout << "합계 : " << sum << endl;
		cout << "평균 : " << sum / count << endl;
	}

	inFile.close();
	return 0;
}
