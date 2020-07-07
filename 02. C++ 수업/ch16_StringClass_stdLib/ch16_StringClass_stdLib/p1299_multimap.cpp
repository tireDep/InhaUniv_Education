#include<iostream>
#include<string>
#include<map>
#include<algorithm>

typedef int KeyType;
typedef std::pair<const KeyType, std::string>Pair;
typedef std::multimap<KeyType, std::string>MapCode;

int main()
{
	using namespace std;
	MapCode codes;

	codes.insert(Pair(415, "�������ý���"));
	codes.insert(Pair(510, "��Ŭ����"));
	codes.insert(Pair(718, "���Ŭ��"));
	codes.insert(Pair(718, "����ư ��"));
	codes.insert(Pair(718, "���ĸ���"));
	codes.insert(Pair(510, "��Ŭ��"));

	cout << "���� �ڵ尡 415�� ���� �� : " << codes.count(415) << endl;
	cout << "���� �ڵ尡 718�� ���� �� : " << codes.count(718) << endl;
	cout << "���� �ڵ尡 510�� ���� �� : " << codes.count(510) << endl;
	cout << "\n���� �ڵ�\t����\n";
	MapCode::iterator iter;
	for (iter = codes.begin(); iter != codes.end(); iter++)
		cout << (*iter).first << "\t\t" << (*iter).second << endl;

	pair<MapCode::iterator, MapCode::iterator> range = codes.equal_range(718);
	cout << "\n�����ڵ尡 718�� ���õ�\n";
	for (iter = range.first; iter != range.second; iter++)
		cout << (*iter).second << endl;

	return 0;
}