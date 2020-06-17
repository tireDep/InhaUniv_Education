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
	cout << "������ ������ �̸��� �Է��Ͻÿ� : ";
	cin.getline(fileName, SIZE);

	inFile.open(fileName);
	if (!inFile.is_open())
	{
		cout << fileName << " ������ �� �� �����ϴ�.\n���α׷��� �����մϴ�.\n";
		exit(EXIT_FAILURE);
	}

	double value;
	double sum = 0.0;
	int count = 0;

	inFile >> value;
	while (inFile.good())	// �Է��� ��ȣ�ϰ� EOF�� �ƴ� ����
	{
		++count;
		sum += value;
		inFile >> value;
	}
	// �� �������� ���� or ������ �־�� �� ������ ������ ������
	// ������ ���� �ٸ� �� ����

	if (inFile.eof())
		cout << "���� ���� �����߽��ϴ�.\n";
	else if (inFile.fail())
		cout << "������ ����ġ�� �Է��� ����Ǿ����ϴ�.\n";
	else
		cout << "�� �� ���� ������ �Է��� ����Ǿ����ϴ�.\n";

	if (count == 0)
		cout << "�����Ͱ� �����ϴ�.\n";
	else
	{
		cout << "���� �׸��� ���� : " << count << endl;
		cout << "�հ� : " << sum << endl;
		cout << "��� : " << sum / count << endl;
	}

	inFile.close();
	return 0;
}
