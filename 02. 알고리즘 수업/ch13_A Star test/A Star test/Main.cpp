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

	// ���
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
				 printf("��");
			 else
				 printf("��");
		 }
		 cout << endl;
	 }
	 // ���
	 
	 // ��ġ �Է�
	 Point start;
	 Point dest;
	 cout << "������ �Է�(x, y / 0~4) : ";
	 cin >> start.x >> start.y;

	 cout << "������ �Է�(x, y / 0~4) : ";
	 cin >> dest.x >> dest.y;
	 // ��ġ �Է�

	 // �������� ��ֹ����� �Ǻ��ؾ���

	 Point temp;
	 if (start.x > dest.x && start.y > dest.y)
	 {
		 astar[start.x][start.y].SetIsReverse(true);
		 temp = start;
		 start = dest;
		 dest = temp;
	 }

	 astar[start.x][start.y].DoAStar(astar, start, dest, path);

	 // ���
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
	 // ���
	 // �����Ǿ�� ��
	 // -> f��, h���� ���� �������

	 // �޸� ����
	 for (int i = 0; i < defSize; i++)
		 delete[] astar[i];
	 
	 delete[] astar;
	 // �޸� ����
}