#include "stdafx.h"
#include "FigureShape.h"

void BasicFigure::MovePos()
{
	srand((unsigned)time(NULL));

	int direction;
	if (movePos.x == 0)
	{
		direction = rand() % 2;
		movePos.x = rand() % 10 + 1;
		if (direction % 2 == 0)
			movePos.x *= -1;

		direction = rand() % 2;
		movePos.y = rand() % 10 + 1;
		if (direction % 2 == 0)
			movePos.y *= -1;
	}

}