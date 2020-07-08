// 2�� ���� ���� ����
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>

const int LIM = 20;

struct planet
{
	char name[LIM];
	double population;
	double g;
};

const char *file = "planets.dat";
inline void EatLine() { while (std::cin.get() != '\n') continue; }

int main()
{
	using namespace std;
	planet p1;
	cout << fixed;

	fstream finout;	// �б� ���� ��Ʈ��
	finout.open(file, ios_base::in | ios_base::out | ios_base::binary);
	// �� : � �����Ϸ��� | ios_base::binary�� ������ ���� �䱸

	int ct = 0;
	if (finout.is_open())
	{
		finout.seekg(0);	// ���� ��ġ�� ��
		cout << file << " ������ ���� ������ ������ �����ϴ�.\n";
		while (finout.read((char *)&p1, sizeof p1))
		{
			cout << ct++ << " : " << setw(LIM) << p1.name << " : "
				<< setprecision(0) << setw(12) << p1.population
				<< setprecision(2) << setw(6) << p1.g << endl;
		}
		if (finout.eof())
			finout.clear();	// eof �÷��� ����
		else
		{
			cerr << file << " ������ �дٰ� ���� �߻�\n";
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << file << " ������ �� �� �����ϴ�.\n";
		exit(EXIT_FAILURE);
	}

	// ���ڵ带 ������
	cout << "������ ���ڵ� ��ȣ�� �Է��Ͻʽÿ� : ";
	long rec;
	cin >> rec;
	EatLine();	// ���� ����
	if (rec < 0 || rec >= ct)
	{
		cerr << "�߸��� ���ڵ� ��ȣ�Դϴ�. ����\n";
		exit(EXIT_FAILURE);
	}
	streampos place = rec * sizeof p1;	// streampos������ ��ȯ
	finout.seekg(place);	// ���� ����
	if (finout.fail())
	{
		cerr << "���ڵ带 ã�ٰ� ���� �߻�\n";
		exit(EXIT_FAILURE);
	}

	finout.read((char *)&p1, sizeof p1);
	cout << "���� ���ڵ��� ���� : ";
	cout << rec << " : " << setw(LIM) << p1.name << " : "
		<< setprecision(0) << setw(12) << p1.population
		<< setprecision(2) << setw(6) << p1.g << endl;
	if (finout.eof())
		finout.clear();	// eof �÷��� ����

	cout << "�༺�� �̸��� �Է��Ͻʽÿ�. : ";
	cin.get(p1.name, LIM);
	EatLine();
	cout << "�༺�� �α��� �Է��Ͻʽÿ�. : ";
	cin >> p1.population;
	cout << "�༺�� �߷°��ӵ��� �Է��Ͻʽÿ�. : ";
	cin >> p1.g;

	finout.seekp(place);	// ������ ���ڵ��� ���� ����Ʈ�� �ٽ� ����
	finout.write((char *)&p1, sizeof p1) << flush;
	if (finout.fail())
	{
		cerr << "���ٰ� ���� �߻�\n";
		exit(EXIT_FAILURE);
	}

	// ������ ������ ȭ�鿡 ǥ��
	ct = 0;
	finout.seekg(0);	// ������ ���� ��ġ�� ��
	cout << file << " ������ ������ ������ ������ �����ϴ�.\n";
	while (finout.read((char *)&p1, sizeof p1))
	{
		cout << ct++ << " : " << setw(LIM) << p1.name << " : "
			<< setprecision(0) << setw(12) << p1.population
			<< setprecision(2) << setw(6) << p1.g << endl;
	}
	finout.close();
	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}