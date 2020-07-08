// Q. ����ڷκ��� �ҽ� ������ ����, �ҽ� ������ �̸�, ���� ���� �̸��� �Է¹޾�
// ���ο� �ϳ��� ���Ϸ� ���ϵ��� �����ϴ� ���α׷��� �ۼ��϶�

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
	cout << "�ҽ� ������ ���� �Է� : ";
	cin >> inputNum;
	inputNum--;

	string fileName;
	cout << "�ҽ� ������ �̸� �Է� (Ȯ���� ���� �Է�) : ";
	cin >> fileName;

	string destFile;
	cout << "���� ���� �̸� �Է� (Ȯ���� ���� �Է�) : ";
	cin >> destFile;

	ifstream readFile;
	ofstream writeFile;
	string tempName;

	writeFile.open(destFile, ios_base::out | ios_base::binary);
	if (!writeFile.is_open())
	{
		cout << "���� ���� ����\n";
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
				cout << "���� ���� ����\n";
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
	cout << "���� ��ġ�� �Ϸ�\n";

	return 0;
}

void Reset(char temp[], int fileSize)
{
	for (int i = 0; i < fileSize; i++)
		temp[i] = 0;
}