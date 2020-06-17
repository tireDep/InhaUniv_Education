// Q7. �ܵ��� ������ q�� �Էµ� ������ �� ���� �� �ܾ �Է��� �д� ���α׷��� �ۼ��϶�.
// ���α׷��� �������� �����ϴ� �ܾ� ��, �������� �����ϴ� �ܾ� ��, �� ������ ��𿡵� ������ �ʴ� �͵��� ���� �����ؾ� �Ѵ�.
// �� ���� �����, ���ڵ�� �����ϴ� �ܾ�� �׷��� ���� �͵��� �����ϱ� ���� isalpha()�� ����ϰ���,
// if �Ǵ� switch ������ ����Ͽ� isalpha() �˻翡 ���޵� �� �� �߿��� �������� �����ϴ� �ܾ �ٽ� �ĺ��ϴ� ���̴�.
// ���α׷��� ���� ���� ������ ���� �� �� �̴�.

// ex)
// �ܾ���� �Է��Ͻÿ�(�������� q) : 
// The 12 awesome oxen ambled
// quietly across 15 meters of lawn. q
// �������� �����ϴ� �ܾ� �� : 5
// �������� �����ϴ� �ܾ� �� : 4
// ��Ÿ : 2

#include<iostream>
#include<cctype>

using namespace std;

int main()
{
	char inputCh[50] = { 0 };
	int elseCh = 0;
	int consonant = 0;	// ����
	int vowel = 0; // ����
	cout << "�ܾ���� �Է��Ͻÿ�(�������� q) : ";
	cin >> inputCh;

	while (strcmp(inputCh, "q"))	// strcmp : 1(�տ��� ŭ), -1(�ڿ��� ŭ), 0(����)
	{
		if (!isalpha(inputCh[0]))
			elseCh++;
		else
		{		
			for (int i = 0; i < strlen(inputCh); i++)
			{
				inputCh[i] = tolower(inputCh[i]);
			}

			switch (inputCh[0])
			{
			case 'w': case 'e': case 'y':
			case 'u': case 'i': case 'o': case 'a':
				vowel++;
				break;

			default:
				consonant++;
				break;
			}
		}
		cin >> inputCh;

	}
	cout << endl << "�������� �����ϴ� �ܾ� �� : " << vowel
		<< endl << "�������� �����ϴ� �ܾ� �� : " << consonant 
		<< endl << "��Ÿ : " << elseCh << endl;

	return 0;
}