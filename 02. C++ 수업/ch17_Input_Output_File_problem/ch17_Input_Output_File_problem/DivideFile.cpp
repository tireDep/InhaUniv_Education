// Q. �뷮�� ū ������ ���� �뷮���� �����ؼ� ���� ������ ���Ϸ� ������ ��ƿ��Ƽ ���α׷��� �ۼ��϶�.
// ����ڷκ��� �ҽ������� �Է¹��� ��, ���� ���ҵ� ���� ������ ����Ʈ ���� �Է¹޾ƾ� �Ѵ�.

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
	cout << "���� ���� �̸� �Է�(Ȯ���� ����) : ";
	cin >> inputFile;

	ifstream fileP;	// ���� �б�
	fileP.open(inputFile, ios_base::in | ios_base::binary);
	if (!fileP.is_open())
	{
		cerr << "���� ���� ����\n";
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

		cout << "���� ũ�� : " << fileSize << endl;
		cout << "���� ũ�� �Է� : ";
		cin >> inputNum;

		string destFile;
		char *contents = new char[inputNum + 1];
		while (fileSize > 0)
		{
			ClearBuff(contents, inputNum);	// �ʱ�ȭ
			cout << "���� ũ�� : " << fileSize << endl;
			destFile = inputFile;
			destFile = to_string(cnt) + "_" + inputFile;
			fileOP.open(destFile, ios_base::binary);
			if (!fileOP.is_open())
			{
				cout << "���� ���� ����\n";
				exit(EXIT_FAILURE);
			}
			// cout << inputFile << endl;	// Ȯ���ڸ� Ȯ��
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
			cnt++;	// ���� �̸�
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