#include "BasicHeader.h"
#include "AStarClass.h"

#define defSize 5

using namespace std;

int main()
{
	AStar **astar = new AStar *[defSize];
	vector<Point> path;

	for (int i = 0; i < defSize; i++)
	{
		astar[i] = new AStar[defSize];
	}

	// 출력
	astar[1][2].SetIsBlock(true);
	astar[2][0].SetIsBlock(true);
	astar[2][1].SetIsBlock(true);
	astar[2][2].SetIsBlock(true);
	
	// astar[3][2].SetIsBlock(true);
	// astar[3][3].SetIsBlock(true);
	// astar[3][4].SetIsBlock(true);

	 for (int i = 0; i < defSize; i++)
	 {
		 for (int j = 0; j < defSize; j++)
		 {
			 if (astar[i][j].GetIsBlock() == false)
				 printf("□");
			 else
				 printf("■");
		 }
		 cout << endl;
	 }
	 // 출력
	 
	 // 위치 입력
	 Point start;
	 Point dest;
	 cout << "시작점 입력(x, y / 0~4) : ";
	 cin >> start.x >> start.y;

	 cout << "도착점 입력(x, y / 0~4) : ";
	 cin >> dest.x >> dest.y;
	 // 위치 입력

	 // 도착점이 장애물인지 판별해야함

	 Point temp;
	 if (start.x > dest.x && start.y > dest.y)
	 {
		 astar[start.x][start.y].SetIsReverse(true);
		 temp = start;
		 start = dest;
		 dest = temp;
	 }

	 astar[start.x][start.y].DoAStar(astar, start, dest, path);

	 // 출력
	 if (astar[start.x][start.y].GetIsReverse() == true)
	 {
		 for (int i = path.size(); i >= 0; i--)
			 cout << "(" << path[i].x << ", " << path[i].y << ")" << " - ";
	 }
	 else
	 {
		 for (int i = 0; i < path.size(); i++)
			 cout << "(" << path[i].x << ", " << path[i].y << ")" << " - ";
	 }
	 // 출력
	 // 수정되어야 함
	 // -> f값, h값이 작은 순서대로

	 // 메모리 해제
	 for (int i = 0; i < defSize; i++)
		 delete[] astar[i];
	 
	 delete[] astar;
	 // 메모리 해제
}