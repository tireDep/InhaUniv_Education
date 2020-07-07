#include<iostream>
#include<string>
#include<memory>

class Report
{
private:
	std::string str;
public:
	Report(const std::string s) :str(s) { std::cout << "객체가 생성되었습니다\n"; }
	~Report() { std::cout << "객체가 삭제되었습니다\n"; }
	void Comment() const { std::cout << str << std::endl; }
};

int main()
{
	{
		std::auto_ptr<Report>ps(new Report("auto_ptr"));
		ps->Comment();
	}
	{
		std::shared_ptr<Report>ps(new Report("shared_ptr"));
		ps->Comment();
	}
	{
		std::unique_ptr<Report>ps(new Report("unique_ptr"));
		ps->Comment();
	}

	return 0;
}