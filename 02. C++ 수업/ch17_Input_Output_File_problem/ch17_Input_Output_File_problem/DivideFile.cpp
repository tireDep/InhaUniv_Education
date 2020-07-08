// Q. 용량이 큰 파일을 작은 용량으로 분할해서 작은 단위의 파일로 나누는 유틸리티 프로그램을 작성하라.
// 사용자로부터 소스파일을 입력받은 후, 각각 분할된 작은 파일의 바이트 값을 입력받아야 한다.

// ex)
// Enter file name : test.zip
// Enter file size : 1024
// -> File test.zip.0
// -> File test.zip.1
// ... Split Done

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void ClearBuff(char contents[], int inputNum);

int main()
{
	string inputFile;
	cout << "원본 파일 이름 입력(확장자 포함) : ";
	cin >> inputFile;

	ifstream fileP;	// 파일 읽기
	fileP.open(inputFile, ios_base::in | ios_base::binary);
	if (!fileP.is_open())
	{
		cerr << "파일 오픈 에러\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		int cnt = 0;
		long fileSize;
		int inputNum;
		ofstream fileOP;

		fileP.seekg(0, ios::end);
		fileSize = fileP.tellg();
		fileP.seekg(0, ios::beg);

		cout << "파일 크기 : " << fileSize << endl;
		cout << "파일 크기 입력 : ";
		cin >> inputNum;

		string destFile;
		char *contents = new char[inputNum + 1];
		while (fileSize > 0)
		{
			ClearBuff(contents, inputNum);	// 초기화
			cout << "파일 크기 : " << fileSize << endl;
			destFile = inputFile;
			destFile = to_string(cnt) + "_" + inputFile;
			fileOP.open(destFile, ios_base::binary);
			if (!fileOP.is_open())
			{
				cout << "파일 생성 에러\n";
				exit(EXIT_FAILURE);
			}
			// cout << inputFile << endl;	// 확장자명 확인
			fileP.read((char *)contents, inputNum);

			if (inputNum > fileSize)
			{
				for (int i = 0; i < inputNum; i++)
				{
					if (contents[i] == -0)
					{
						contents[i] = '\0';
						inputNum = i;
					}
				}
			}
			else
			{
				contents[inputNum] = '\0';
			}

			fileOP.write((char *)contents, inputNum);
			cout << contents << endl;

			fileSize -= inputNum;
			fileOP.close();
			cnt++;	// 파일 이름
		}
		delete[] contents;
		fileP.close();
	}

	return 0;
}

void ClearBuff(char contents[], int inputNum)
{
	for (int i = 0; i < inputNum; i++)
		contents[i] = -0;
}