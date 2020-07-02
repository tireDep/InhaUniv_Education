#include"studentc.h"

using std::ostream;
using std::endl;
using std::istream;
using std::string;

// public
double Student::Average() const
{
	if (scores.size() > 0)
		return scores.sum() / scores.size();
	else
		return 0;
}

const string & Student::Name() const
{
	return name;
}

double & Student::operator[](int i)
{
	return scores[i];
	// valarray<double>::operator[] () 사용
}

double Student::operator[](int i) const
{
	return scores[i];
}

// private
ostream & Student::arr_out(std::ostream & os) const
{
	int i;
	int lim = scores.size();
	if (lim > 0)
	{
		for (i = 0; i < lim; i++)
		{
			os << scores[i] << " ";
			if (i % 5 == 4)
				os << endl;
		}
		if (i % 5 != 0)
			os << endl;
	}
	else
		os << "빈 배열 ";
	
	return os;
}

// 프랜드
istream & operator >> (std::istream & is, Student &stu)
{
	is >> stu.name;
	return is;
}

istream & getline(std::istream & is, Student &stu)
{
	getline(is, stu.name);
	return is;
}

ostream & operator << (std::ostream & os, const Student & stu)
{
	os << stu.name << " 학생의 성적표\n";
	stu.arr_out(os);	// scores를 위해 private 메서드 사용
	return os;
}