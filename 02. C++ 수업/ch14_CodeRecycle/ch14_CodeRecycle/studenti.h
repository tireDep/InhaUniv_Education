#pragma once

#include<iostream>
#include<string>
#include<valarray>

class Student : private std::string, private std::valarray<double>
{
private:
	typedef std::valarray<double> ArrayDb;
	std::ostream & arr_out(std::ostream & os)const;	// 출력을 위한 private 함수

public:
	Student() : std::string("Null Student"), ArrayDb() { }
	explicit Student(const std::string & s) : std::string(s), ArrayDb() { }
	explicit Student(int n) : std::string("Nully"), ArrayDb(n) { }
	Student(const std::string &s, int n) : std::string(s), ArrayDb(n) { }
	Student(const std::string & s, const ArrayDb & a) : std::string(s), ArrayDb(a) { }
	Student(const char *str, const double *pd, int n) : std::string(str), ArrayDb(pd, n) { }
	~Student() { }

	double Average() const;
	const std::string &Name() const;
	double & operator[](int i);
	double operator[](int i) const;

	// 프랜드
	friend std::istream & operator >> (std::istream & is, Student &stu);	// 1워드 입력
	friend std::istream & getline(std::istream & is, Student &stu);	// 1줄 입력

	friend std::ostream &operator << (std::ostream & os, const Student & stu);	// 출력
};