#include "stdafx.h"
#include "cBezierPath.h"

#define dMaxT 1.0

cBezierPath::cBezierPath()
{
}

cBezierPath::~cBezierPath()
{
}

void cBezierPath::SetUp(vector<ST_PC_VERTEX> path, float maxT)
{
	float tNum = 0.0f;
	ST_PC_VERTEX addSpot;
	addSpot.c = D3DXCOLOR(255.0f, 0.0f, 0.0f, 1.0f);

	for (int i = 0; i < path.size() - 1; i+=2)
	{
		while (tNum < 1.0f)
		{
			addSpot.p = pow(1 - tNum, 2) * path[i + 0].p
						+ 2 * (1 - tNum) * tNum * path[i + 1].p
						+ pow(tNum, 2) * path[i + 2].p;
			m_vecVertex.push_back(addSpot);
			tNum += maxT;
		}
		tNum = 0.0f;
	}
	
	// // 3차 베지에 곡선
	// for (int i = 0; i < path.size() - 1; i += 3)
	// {
	// 	while (tNum < dMaxT)
	// 	{
	// 		addSpot.p = pow(1 - tNum, 3) * path[i + 0].p
	// 					+ 3 * pow(1 - tNum, 2) * tNum * path[i + 1].p
	// 					+ 3 * (1 - tNum) * pow(tNum, 2)  * path[i + 2].p;
	// 					+ pow(tNum, 3) * path[i + 3].p;
	   
	// 		m_vecVertex.push_back(addSpot);
	// 		tNum += maxT;
	// 	}
	// 	tNum = 0.0f;
	// }

	m_vecVertex.push_back(m_vecVertex[0]);
}

void cBezierPath::Render()
{
	cPath::Render();
}
