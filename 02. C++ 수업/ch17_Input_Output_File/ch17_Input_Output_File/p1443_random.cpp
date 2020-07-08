// 2진 파일 임의 접근
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

	fstream finout;	// 읽기 쓰기 스트림
	finout.open(file, ios_base::in | ios_base::out | ios_base::binary);
	// 주 : 어떤 컴파일러는 | ios_base::binary를 생략할 것을 요구

	int ct = 0;
	if (finout.is_open())
	{
		finout.seekg(0);	// 시작 위치로 감
		cout << file << " 파일의 현재 내용은 다음과 같습니다.\n";
		while (finout.read((char *)&p1, sizeof p1))
		{
			cout << ct++ << " : " << setw(LIM) << p1.name << " : "
				<< setprecision(0) << setw(12) << p1.population
				<< setprecision(2) << setw(6) << p1.g << endl;
		}
		if (finout.eof())
			finout.clear();	// eof 플래그 해제
		else
		{
			cerr << file << " 파일을 읽다가 에러 발생\n";
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << file << " 파일을 열 수 없습니다.\n";
		exit(EXIT_FAILURE);
	}

	// 레코드를 수정함
	cout << "수정할 레코드 번호를 입력하십시오 : ";
	long rec;
	cin >> rec;
	EatLine();	// 개행 제거
	if (rec < 0 || rec >= ct)
	{
		cerr << "잘못된 레코드 번호입니다. 종료\n";
		exit(EXIT_FAILURE);
	}
	streampos place = rec * sizeof p1;	// streampos형으로 변환
	finout.seekg(place);	// 임의 접근
	if (finout.fail())
	{
		cerr << "레코드를 찾다가 에러 발생\n";
		exit(EXIT_FAILURE);
	}

	finout.read((char *)&p1, sizeof p1);
	cout << "현재 레코드의 내용 : ";
	cout << rec << " : " << setw(LIM) << p1.name << " : "
		<< setprecision(0) << setw(12) << p1.population
		<< setprecision(2) << setw(6) << p1.g << endl;
	if (finout.eof())
		finout.clear();	// eof 플래그 해제

	cout << "행성의 이름을 입력하십시오. : ";
	cin.get(p1.name, LIM);
	EatLine();
	cout << "행성의 인구를 입력하십시오. : ";
	cin >> p1.population;
	cout << "행성의 중력가속도를 입력하십시오. : ";
	cin >> p1.g;

	finout.seekp(place);	// 수정할 레코드의 시작 바이트로 다시 간다
	finout.write((char *)&p1, sizeof p1) << flush;
	if (finout.fail())
	{
		cerr << "쓰다가 에러 발생\n";
		exit(EXIT_FAILURE);
	}

	// 개정된 파일을 화면에 표시
	ct = 0;
	finout.seekg(0);	// 파일의 시작 위치로 감
	cout << file << " 파일의 개정판 내용은 다음과 같습니다.\n";
	while (finout.read((char *)&p1, sizeof p1))
	{
		cout << ct++ << " : " << setw(LIM) << p1.name << " : "
			<< setprecision(0) << setw(12) << p1.population
			<< setprecision(2) << setw(6) << p1.g << endl;
	}
	finout.close();
	cout << "프로그램을 종료합니다.\n";
	return 0;
}