#include "stdafx.h"
#include "ObjectClass.h"

Object::Object()
{
	cVector3 temp;

	temp.SetValue(1, 1, 1);
	vecSpot.push_back(temp);

	temp.SetValue(1, 1, -1);
	vecSpot.push_back(temp);

	temp.SetValue(-1, 1, -1);
	vecSpot.push_back(temp);

	temp.SetValue(-1, 1, 1);
	vecSpot.push_back(temp);

	temp.SetValue(1, -1, 1);
	vecSpot.push_back(temp);

	temp.SetValue(1, -1, -1);
	vecSpot.push_back(temp);

	temp.SetValue(-1, -1, -1);
	vecSpot.push_back(temp);

	temp.SetValue(-1, -1, 1);
	vecSpot.push_back(temp);
}

Object::~Object()
{

}

Object * Object::GetInstance()
{
	static Object object;
	return &object;
}

void Object::ObjTransFromCoord(cMatrix matrix)
{
	// renderSpot.clear();
	for (int i = 0; i < vecSpot.size(); i++)
	{
		vecSpot[i] = cVector3::TransformCoord(vecSpot[i], matrix);
	}
}

vector<cVector3> Object::GetRenderSpot()
{
	return vecSpot;
}
