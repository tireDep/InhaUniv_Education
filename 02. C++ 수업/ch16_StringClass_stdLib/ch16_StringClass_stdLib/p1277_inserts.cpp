#include<iostream>
#include<string>
#include<iterator>
#include<vector>
#include<algorithm>

void OutPut(const std::string &s) { std::cout << s << " "; }

int main()
{
	using namespace std;

	string s1[4] = { "fine","fish","fashion","fate" };
	string s2[2] = { "busy","bats" };
	string s3[2] = { "silly","singers" };

	vector<string> words(4);
	copy(s1, s1 + 4, words.begin());
	for_each(words.begin(), words.end(), OutPut);
	cout << endl;

	copy(s2, s2 + 2, back_insert_iterator<vector<string>>(words));	// 劳疙狼 back_insert_iterator 按眉 积己
	for_each(words.begin(), words.end(), OutPut);
	cout << endl;

	copy(s3, s3 + 2, insert_iterator<vector<string>>(words, words.begin()));	// 劳疙狼 insert_iterator 按眉 积己
	for_each(words.begin(), words.end(), OutPut);
	cout << endl;
}