// Q. 한 세트의 점들이 주어졌을 때, 가장 가까운 두 점을 찾아 출력하는 프로그램을 작성
// (x, y)로 주어진 여러 점들이 주어질 때

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
// > 가장 가까운 점들은 (1,1) and (2, 0.5)

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
	cout << "입력할 점의 개수 : ";
	cin >> inputNum;

	SPOTPOS_S *spotPosArr = new SPOTPOS_S[inputNum];
	if (spotPosArr == NULL)
	{
		cout << "error : 동적할당\n";
		exit(1);
	}
	
	int cnt = 0;
	while (cnt != inputNum)
	{
		cout << "점 위치 입력(x, y) : ";
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
	
	cout << "\n시작점 : (" << spotPosArr[shortIndex[index].startIndex].x << ", " << spotPosArr[shortIndex[index].startIndex].y << ")\n";
	cout << "끝점 : (" << spotPosArr[shortIndex[index].endIndex].x << ", " << spotPosArr[shortIndex[index].endIndex].y << ")\n";
	cout << "두 점 사이의 거리 : " << shortIndex[index].length << endl;
	
	delete[] spotPosArr;
	delete[] shortIndex;

	return 0;
}