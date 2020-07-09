// 오브젝트의 충돌 판별(2D 기본 충돌판정)

// Q. 두 직사각형에 대해 중심점의 좌표 (x, y)와 폭 w, 높이 h를 입력받아 
// 두 번째 직사각형이 첫 번째 직사각형의 내부에 있는지, 첫 번째 직사각형과 겹치는 지를 판단하는 프로그램 작성
// 내부 / 외부 판단

// ex)
// R1 : 2.5, 4, 2.5, 43
// R2 : 1.5, 5, 0.5, 3
// => R2는 R1의 내부에 있다.

// [ 전제조건 : 처음 입력이 큼 ]

#include<iostream>
#include<cmath>

using namespace std;

struct RECTANGLE_S
{
	float x;
	float y;
	float w;
	float h;
};

struct RECPOS_S
{
	float x[4];
	float y[4];
};

void InputRec(RECTANGLE_S *firstRec, RECTANGLE_S *secRec);
void RecPos(RECTANGLE_S *rectangle, RECPOS_S *recPos);
void CalcRec(RECPOS_S *fRecPos, RECPOS_S *sRecPos, bool *isCheck);

int main()
{
	RECTANGLE_S firstRec;
	RECTANGLE_S secRec;
	InputRec(&firstRec, &secRec);

	RECPOS_S fRecPos;
	RECPOS_S sRecPos;
	RecPos(&firstRec, &fRecPos);
	RecPos(&secRec, &sRecPos);

	bool isCheck = false;
	int checkCnt = 0;
	int posCnt = 2;

	CalcRec(&fRecPos, &sRecPos, &isCheck);

	if (isCheck)
	{
		// 1 : 내부 존재
		for (int i = 0; i < 4; i++)
		{
			if (i == 0 || i == 2)
				posCnt = 2;
			else if (i == 1 || i == 3)
				posCnt = -2;

			// 21
			// 34
			// 일 경우

			// 앞 조건 2개 : 각 모서리 값보다 작거나 같은지
			// 뒤 조건 2개 : 비교 모서리의 반대 위치 모서리 값보다 크거나 같은지 
			// => 첫 번째 사각형의 '세 번째 모서리'와 두 번째 사각형의 '첫 번째 모서리'가 만나는 경우 등 판별 위해 추가함(이경우는 겹침)
			if (fRecPos.x[i] >= sRecPos.x[i] && fRecPos.y[i] >= sRecPos.y[i] && fRecPos.x[posCnt] <= sRecPos.x[i] && fRecPos.y[posCnt] <= sRecPos.y[i])
				checkCnt++;
		}
		if (checkCnt == 4)
			cout << "사각형 내부에 존재함" << endl;
		// 2 : 겹침
		else
			cout << "사각형과 겹침" << endl;
	}
	else
	{
		// 3: 외부 존재
		cout << "사각형 외부에 존재함" << endl;
	}

	return 0;
}

void InputRec(RECTANGLE_S *firstRec, RECTANGLE_S *secRec)
{
	cout << "첫 번째 사각형의 좌표 입력(중심점 좌표 : x, y) : ";
	cin >> firstRec->x >> firstRec->y;
	cout << "첫 번째 사각형의 좌표 입력(가로 세로 : w, h) : ";
	cin >> firstRec->w >> firstRec->h;

	cout << "두 번째 사각형의 좌표 입력(중심점 좌표 : x, y) : ";
	cin >> secRec->x >> secRec->y;
	cout << "두 번째 사각형의 좌표 입력(가로 세로 : w, h) : ";
	cin >> secRec->w >> secRec->h;
}

void RecPos(RECTANGLE_S *rectangle, RECPOS_S *recPos)
{
	// 사각형의 좌표
	int minus = -1;
	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
			recPos->x[i] = rectangle->x + rectangle->w / 2;
			recPos->y[i] = rectangle->y + rectangle->h / 2;
			break;
		case 1:
			recPos->x[i] = rectangle->x + -(rectangle->w / 2);
			recPos->y[i] = rectangle->y + rectangle->h / 2;
			break;
		case 2:
			recPos->x[i] = rectangle->x + -(rectangle->w / 2);
			recPos->y[i] = rectangle->y + -(rectangle->h / 2);
			break;
		case 3:
			recPos->x[i] = rectangle->x + rectangle->w / 2;
			recPos->y[i] = rectangle->y + -(rectangle->h / 2);
			break;
		default:
			break;
		}
	}

	// cout << endl;
	// for (int i = 0; i < 4; i++)
	// {
	// 	cout << recPos->x[i] << " " << recPos->y[i] << endl;
	// }
}

void CalcRec(RECPOS_S *fRecPos, RECPOS_S *sRecPos, bool *isCheck)
{
	// 첫번째 사각형의 우상단 모서리가 두번째 사각형의 좌하단 모서리 넘음			: x
	// 첫번째 사각형의 좌하단 모서리가 두번째 사각형의 우상단 모서리 넘지 않음	: x
	// 첫번째 사각형의 좌하단 모서리가 두번째 사각형의 우상단 모서리 넘지 않음	: y
	// 첫번째 사각형의 우상단 모서리가 두번째 사각형의 좌하단 모서리를 넘음		: y 
	// https://progdev.tistory.com/8

	if ((fRecPos->x[0] >= sRecPos->x[2]) && (fRecPos->x[2] <= sRecPos->x[0]) && (fRecPos->y[2] <= sRecPos->y[0]) && (fRecPos->y[0] >= sRecPos->y[2]))
		*isCheck = true;
	else
		*isCheck = false;
}
