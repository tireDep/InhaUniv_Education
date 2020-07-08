// 2�� ���� �����
#include<iostream>	//  ��κ��� �ý��ۿ��� �ʿ� x
#include<fstream>
#include<iomanip>
#include<cstdlib>	// exit()

inline void EatLine() { while (std::cin.get() != '\n')continue; }

struct planet
{
	char name[20];
	double popluation;
	double g;
};

const char *file = "planets.dat";

int main()
{
	using namespace std;
	planet p1;
	cout << fixed << right;

	// �ʱ� ���� ȭ�� ǥ��
	ifstream fin;
	fin.open(file, ios_base::in | ios_base::binary);	// 2�� ����
	// �� : � �����Ϸ��� ios_base::binary ��带 �޾Ƶ����� x

	if (fin.is_open())
	{
		cout << file << " ������ ���� ������ ������ �����ϴ�.\n";
		while (fin.read((char *)&p1, sizeof p1))
		{
			cout << setw(20) << p1.name << " : "
				<< setprecision(0) << setw(12) << p1.popluation
				<< setprecision(2) << setw(6) << p1.g << endl;
		}
		fin.close();
	}

	// ���ο� �����͸� �߰�
	ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);
	if (!fout.is_open())
	{
		cerr << "����� ���� " << file << " ������ �� �� �����ϴ�.\n";
		exit(EXIT_FAILURE);
	}

	cout << "�༺�� �̸��� �Է��Ͻʽÿ�.(�������� �� �� �Է�) : ";
	cin.get(p1.name, 20);
	while (p1.name[0] != '\0')
	{
		EatLine();
		cout << "�༺�� �α��� �Է��Ͻʽÿ�. : ";
		cin >> p1.popluation;
		cout << "�༺�� �߷°��ӵ��� �Է��Ͻʽÿ�. : ";
		cin >> p1.g;
		EatLine();
		fout.write((char *)&p1, sizeof p1);
		cout << "�༺�� �̸��� �Է��Ͻʽÿ�.(�������� �� �� �Է�) : ";
		cin.get(p1.name, 20);
	}
	fout.close();

	// ������ ������ ȭ�鿡 ǥ���Ѵ�
	fin.clear();
	fin.open(file, ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		cout << file << " ������ ������ ������ ������ �����ϴ�.\n";
		while (fin.read((char *)&p1, sizeof p1))
		{
			cout << setw(20) << p1.name << " : "
				<< setprecision(0) << setw(12) << p1.popluation
				<< setprecision(2) << setw(6) << p1.g << endl;
		}
		fin.close();
	}

	cout << "���α׷��� �����մϴ�.\n";

	return 0;
}