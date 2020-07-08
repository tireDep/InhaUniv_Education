// Q. 사용자로부터 소스 파일의 개수, 소스 파일의 이름, 목적 파일 이름을 입력받아
// 새로운 하나의 파일로 파일들을 조합하는 프로그램을 작성하라

// ex)
// Enter file number : 2
// Enter source file : test.zip.0
// Enter source file : test.zip.1
// Enter target file : temp.zip
// ... Combine Done

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void Reset(char temp[], int fileSize);

int main()
{
	int inputNum;
	cout << "소스 파일의 개수 입력 : ";
	cin >> inputNum;
	inputNum--;

	string fileName;
	cout << "소스 파일의 이름 입력 (확장자 포함 입력) : ";
	cin >> fileName;

	string destFile;
	cout << "목적 파일 이름 입력 (확장자 포함 입력) : ";
	cin >> destFile;

	ifstream readFile;
	ofstream writeFile;
	string tempName;

	writeFile.open(destFile, ios_base::out | ios_base::binary);
	if (!writeFile.is_open())
	{
		cout << "파일 생성 에러\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		int cnt = 0;
		int fileSize = 0;
		while (inputNum >= cnt)
		{
			tempName = fileName;
			tempName = to_string(cnt) + "_" + tempName;
			readFile.open(tempName, ios_base::in| ios_base::binary);
			if (!readFile.is_open())
			{
				cout << "파일 오픈 에러\n";
				writeFile.close();
				exit(EXIT_FAILURE);
			}
			
			readFile.seekg(0, ios::end);
			fileSize = readFile.tellg();
			readFile.seekg(0, ios::beg);

			char *temp = new char[fileSize];
			Reset(temp, fileSize);

			readFile.read((char *)temp, fileSize);
			writeFile.write((char *)temp, fileSize);

			cnt++;
			readFile.close();
			delete[] temp;
		}	// while
	}	// else

	writeFile.close();
	cout << "파일 합치기 완료\n";

	return 0;
}

void Reset(char temp[], int fileSize)
{
	for (int i = 0; i < fileSize; i++)
		temp[i] = 0;
}