// cin�� ���ܸ� �߻��ϰ� ��
#include<iostream>
#include<exception>

int main()
{
	using namespace std;

	// failbit�� ���ܸ� �߻���Ű�� �����
	cin.exceptions(ios_base::failbit);
	cout << "���� �Է��Ͻʽÿ�.\n";

	int sum = 0;
	int input;
	try
	{
		while (cin >> input)
		{
			sum += input;
		}
	}
	catch(ios_base::failure & bf)
	{
		cout << bf.what() << endl;
		cout << "��! �Ǽ�!\n";
	}

	cout << "���������� �Է��� �� : " << input << endl;
	cout << "�հ� : " << sum << endl;

	return 0;
}