// 2진 파일 입출력
#include<iostream>	//  대부분의 시스템에서 필요 x
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

	// 초기 내용 화면 표시
	ifstream fin;
	fin.open(file, ios_base::in | ios_base::binary);	// 2진 파일
	// 주 : 어떤 컴파일러는 ios_base::binary 모드를 받아들이지 x

	if (fin.is_open())
	{
		cout << file << " 파일의 현재 내용은 다음과 같습니다.\n";
		while (fin.read((char *)&p1, sizeof p1))
		{
			cout << setw(20) << p1.name << " : "
				<< setprecision(0) << setw(12) << p1.popluation
				<< setprecision(2) << setw(6) << p1.g << endl;
		}
		fin.close();
	}

	// 새로운 데이터를 추가
	ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);
	if (!fout.is_open())
	{
		cerr << "출력을 위해 " << file << " 파일을 열 수 없습니다.\n";
		exit(EXIT_FAILURE);
	}

	cout << "행성의 이름을 입력하십시오.(끝내려면 빈 줄 입력) : ";
	cin.get(p1.name, 20);
	while (p1.name[0] != '\0')
	{
		EatLine();
		cout << "행성의 인구를 입력하십시오. : ";
		cin >> p1.popluation;
		cout << "행성의 중력가속도를 입력하십시오. : ";
		cin >> p1.g;
		EatLine();
		fout.write((char *)&p1, sizeof p1);
		cout << "행성의 이름을 입력하십시오.(끝내려면 빈 줄 입력) : ";
		cin.get(p1.name, 20);
	}
	fout.close();

	// 개정된 파일을 화면에 표시한다
	fin.clear();
	fin.open(file, ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		cout << file << " 파일의 개정된 내용은 다음과 같습니다.\n";
		while (fin.read((char *)&p1, sizeof p1))
		{
			cout << setw(20) << p1.name << " : "
				<< setprecision(0) << setw(12) << p1.popluation
				<< setprecision(2) << setw(6) << p1.g << endl;
		}
		fin.close();
	}

	cout << "프로그램을 종료합니다.\n";

	return 0;
}