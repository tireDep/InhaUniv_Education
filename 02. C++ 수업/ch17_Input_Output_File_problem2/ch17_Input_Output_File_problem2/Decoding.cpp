// Q. ��ȣȭ�� ������ ��ȣȭ(decoding)�ϴ� ���α׷��� �ۼ��ض�.
// ����ڰ� �Է� ���� �̸��� ��� ���� �̸��� �Է��ϸ� �Է� ������ ��ȣ�� Ǯ�� ������ ��� ���Ͽ� �����϶�.

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

const int DecodingNum = 5;

int main()
{
	string startName;
	string endName;
	cout << "���ϸ� �Է�(��ȣȭ�� ����) : ";
	cin >> startName;

	cout << "���ϸ� �Է�(����� ����) : ";
	cin >> endName;

	ifstream sFp;
	sFp.open(startName, ios_base::in | ios_base::binary);
	if (!sFp.is_open())
	{
		cout << "���� ���� ����\n";
		exit(EXIT_FAILURE);
	}

	ofstream eFp;
	eFp.open(endName, ios_base::out | ios_base::binary);
	if (!eFp.is_open())
	{
		sFp.close();
		cout << "���� ���� ����\n";
		exit(EXIT_FAILURE);
	}

	int fileSize;
	sFp.seekg(0, ios::end);
	fileSize = sFp.tellg();
	sFp.seekg(0, ios::beg);

	char tempChar;
	while (fileSize>0)
	{
		sFp.read(&tempChar, 1); // sFp.get(tempChar);	// �̰ŵ� ����
		tempChar -= DecodingNum;
		eFp << tempChar;	// eFp.put(tempChar); // �̰ŵ� ����

		fileSize--;
	}

	sFp.close();
	eFp.close();

	return 0;
}