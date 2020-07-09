// Q. �� ��Ʈ�� ������ �־����� ��, ���� ����� �� ���� ã�� ����ϴ� ���α׷��� �ۼ�
// (x, y)�� �־��� ���� ������ �־��� ��

// ex)
//		 x	y
//	0	-1	3
//	1	-1	-1
//	2	 1	 1
//	3	 2	 0.5
//	4	 2	-1
//	5	 3	 3
//	6	 4	 2
//	7	 4	-0.5
// > ���� ����� ������ (1,1) and (2, 0.5)

#include<iostream>
#include<cmath>

struct SPOTPOS_S
{
	float x;
	float y;
};

struct SHORTINDEX_S
{
	int startIndex;
	int endIndex;
	float length;
};

using namespace std;

int main()
{
	int inputNum;
	cout << "�Է��� ���� ���� : ";
	cin >> inputNum;

	SPOTPOS_S *spotPosArr = new SPOTPOS_S[inputNum];
	if (spotPosArr == NULL)
	{
		cout << "error : �����Ҵ�\n";
		exit(1);
	}
	
	int cnt = 0;
	while (cnt != inputNum)
	{
		cout << "�� ��ġ �Է�(x, y) : ";
		cin >> spotPosArr[cnt].x >> spotPosArr[cnt].y;
		cnt++;
	}

	SHORTINDEX_S *shortIndex = new SHORTINDEX_S[inputNum];
	float tempX, tempY;
	float shortTemp;
	for (int i = 0; i < inputNum; i++)
	{	
		for (int j = i + 1; j > i; j--)
		{
			tempX = pow(spotPosArr[j].x - spotPosArr[i].x, 2);
			tempY = pow(spotPosArr[j].y - spotPosArr[i].y, 2);
			shortTemp = pow(tempX + tempY, 0.5);
			if (j - 1 == i)
			{
				shortIndex[i].startIndex = i;
				shortIndex[i].endIndex = j;
				shortIndex[i].length = shortTemp;
			}
			else if (shortIndex[i].length > shortTemp)
			{
				shortIndex[i].endIndex = j;
				shortIndex[i].length = shortTemp;
			}
		}
	}

	int index = 0;
	for (int i = 0; i < inputNum - 1; i++)
	{
		// cout << shortIndex[i].length << endl;
		if (i == 0)
			index = 0;
		if (shortIndex[index].length > shortIndex[i + 1].length)
			index = i + 1;
	}
	
	cout << "\n������ : (" << spotPosArr[shortIndex[index].startIndex].x << ", " << spotPosArr[shortIndex[index].startIndex].y << ")\n";
	cout << "���� : (" << spotPosArr[shortIndex[index].endIndex].x << ", " << spotPosArr[shortIndex[index].endIndex].y << ")\n";
	cout << "�� �� ������ �Ÿ� : " << shortIndex[index].length << endl;
	
	delete[] spotPosArr;
	delete[] shortIndex;

	return 0;
}