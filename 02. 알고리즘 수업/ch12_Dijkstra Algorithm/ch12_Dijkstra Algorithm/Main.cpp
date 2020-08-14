#include <iostream>
#include <string>
#include "Dijkstra.h"

using namespace std;

void InputData(int &node, string text);

int main()
{
	cDijkstra *dijkstra = cDijkstra::GetInstance();

	int startNode, endNode;
	InputData(startNode, "������ ��� �Է�");
	InputData(endNode, "\n������ ��� �Է� ");

	dijkstra->SetGoalNode(startNode, endNode);
	dijkstra->DoDijkstra();

	return 0;
}

void InputData(int &node, string text)
{
	while (1)
	{
		cout << text <<"(1 ~ " << defNodeCnt << ") : ";
		cin >> node;

		if (node > defNodeCnt || node <= 0)
		{
			cout << "[ �Է� ����. ���Է� �ʿ� ]\n\n";
			while ((node = getchar()) != EOF && node != '\n') {};
			// todo : ���� �Է½� ���� ������
		}
		else
			break;
	}
}